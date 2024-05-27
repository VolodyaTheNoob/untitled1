//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/ChessBoard.h"
//Constructors
ChessBoard::ChessBoard(){
    this->IsFlipped = false;
    this->CurrentPlayerMove = "White";
    this->Tiles = nullptr;
    this->Peaces = nullptr;
    this->Size = sf::Vector2u(0,0);
}
ChessBoard::ChessBoard(bool IsFlipped,std::string CurrentPlayerMove, TileMap* TileMapPtr, PeaceMap* PeaceMapPtr, sf::Vector2u BoardSize){
    this->IsFlipped = IsFlipped;
    this->CurrentPlayerMove = CurrentPlayerMove;
    this->Tiles = TileMapPtr;
    this->Peaces = PeaceMapPtr;
    this->Size = BoardSize;
}
//Destructors
ChessBoard::~ChessBoard() = default;
//Functions
bool ChessBoard::PlayerMove(ChessPeace* MovedPeace, sf::Vector2u NewPeaceBoardPosition, sf::Vector2f PrevPeacePosition){
    //check if king checkmated - if not pass
    /*
     * I guess we can just bruteforce every peace correct move - its 64 x 64 * 16 - a lot, but we can skip this, and just players decide if game over
     * Because I don't know how many time it will take to bruteforce this count of moves
     */
    sf::Vector2f NewPeacePosition = MovedPeace->GetPeaceCoordinates();
    sf::Vector2u PrevPeaceBoardPosition = MovedPeace->GetBoardCoordinates();
    if(!this->IsOwnKingCheckmated()) {
        if (MovedPeace->GetTeam() == this->CurrentPlayerMove) {
            if (MovedPeace->IsCanMoveThere(this, NewPeaceBoardPosition)) {
                /*If move correct - we create copy of CurrentPeaceMap;
                 * We move peace and calculate - is King attacked now
                 * if Counters of king attacker not equal Zero - we don't pass move
                 * Also in future we should add extra checks but its in future
                 */
                //check if king checked after move if not pass
                this->GetPeaceMapPtr()->MovePeace(MovedPeace, NewPeaceBoardPosition, NewPeacePosition);
                if (!IsOwnKingChecked()) {
                    if (!MovedPeace->IsKingThere(this, NewPeaceBoardPosition)) {
                        this->NextPlayer();
                        return true;
                    }
                }
            }
        }
    }else{
        std::cout << "Checkmated" << "\n";
    }
    this->GetPeaceMapPtr()->MovePeace(MovedPeace, PrevPeaceBoardPosition, PrevPeacePosition);
    return false;
}
TileMap* ChessBoard::GetTileMapPtr(){
    return this->Tiles;
}
PeaceMap* ChessBoard::GetPeaceMapPtr(){
    return this->Peaces;
}
sf::Vector2u ChessBoard::GetSize(){
    return this->Size;
}
std::string ChessBoard::GetCurrentPlayerMove(){
    return this->CurrentPlayerMove;
}
bool ChessBoard::IsViewFlipped(){
    return this->IsFlipped;
}
void ChessBoard::NextPlayer(){
    if(this->GetCurrentPlayerMove() == "White"){
        this->CurrentPlayerMove = "Black";
    }else{
        this->CurrentPlayerMove = "White";
    }
}

std::string ChessBoard::GetEnemyTeam(){
    if(this->CurrentPlayerMove == "White"){
        return "Black";
    }
    return "White";
}

sf::Vector2u ChessBoard::GetOwnKingCoordinates(){
    return *this->GetPeaceMapPtr()->GetPeaceBoardCoordinates(this->GetCurrentPlayerMove(),"King");
}

sf::Vector2u ChessBoard::GetEnemyKingCoordinates(){
    return *this->GetPeaceMapPtr()->GetPeaceBoardCoordinates(this->GetEnemyTeam(),"King");
}

bool ChessBoard::IsOwnKingChecked() {
    sf::Vector2u OwnKingCoordinates = this->GetOwnKingCoordinates();
    std::string EnemyTeam = this->GetEnemyTeam();
    for(unsigned int y = 0; y < this->Size.y; y++){
        for(unsigned int x = 0; x < this->Size.x; x++) {
            if((*this->GetPeaceMapPtr()->GetMapPtr())[y][x] != nullptr){
                if((*this->GetPeaceMapPtr()->GetMapPtr())[y][x]->GetTeam() == EnemyTeam){
                    if((*this->GetPeaceMapPtr()->GetMapPtr())[y][x]->IsAttackingSquare(this,OwnKingCoordinates)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ChessBoard::IsOwnKingCheckmated(){
    std::string OwnTeam = this->GetCurrentPlayerMove();
    std::vector<std::vector<ChessPeace*>>* PeaceMapPtr = this->GetPeaceMapPtr()->GetMapPtr();
    for(unsigned int y = 0; y < this->Size.y; y++){
        for(unsigned int x = 0; x < this->Size.x; x++) {
            if((*PeaceMapPtr)[y][x] != nullptr) {
                if ((*PeaceMapPtr)[y][x]->GetTeam() == OwnTeam) {
                    sf::Vector2u NewBoardPos;
                    for(unsigned int ToMoveY = 0; ToMoveY < this->Size.y; ToMoveY++) {
                        NewBoardPos.y = ToMoveY;
                        for (unsigned int ToMoveX = 0; ToMoveX < this->Size.x; ToMoveX++) {
                            if((*PeaceMapPtr)[y][x]->IsCanMoveThere(this,sf::Vector2u(ToMoveX,ToMoveY))){
                                ChessPeace* DeletedPeacePtr = (*PeaceMapPtr)[ToMoveY][ToMoveX];
                                sf::Vector2u PrevPeaceBoardPos = sf::Vector2u(x,y);
                                sf::Vector2f PrevPeacePos = (*PeaceMapPtr)[y][x]->GetPeaceCoordinates();
                                this->GetPeaceMapPtr()->MovePeace((*PeaceMapPtr)[y][x],sf::Vector2u(ToMoveX,ToMoveY),(*PeaceMapPtr)[y][x]->GetPeaceCoordinates());
                                if(!this->IsOwnKingChecked()){
                                    this->GetPeaceMapPtr()->MovePeace((*PeaceMapPtr)[ToMoveY][ToMoveX],PrevPeaceBoardPos,PrevPeacePos);
                                    (*PeaceMapPtr)[ToMoveY][ToMoveX] = DeletedPeacePtr;
                                    return false;
                                }
                                this->GetPeaceMapPtr()->MovePeace((*PeaceMapPtr)[ToMoveY][ToMoveX],PrevPeaceBoardPos,PrevPeacePos);
                                (*PeaceMapPtr)[ToMoveY][ToMoveX] = DeletedPeacePtr;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}