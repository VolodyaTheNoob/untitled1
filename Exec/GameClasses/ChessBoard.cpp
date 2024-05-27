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
    if(MovedPeace->GetTeam() == this->CurrentPlayerMove) {
        if (MovedPeace->IsCanMoveThere(this, NewPeaceBoardPosition)) {
            /*If move correct - we create copy of CurrentPeaceMap;
             * We move peace and calculate - is King attacked now
             * if Counters of king attacker not equal Zero - we don't pass move
             * Also in future we should add extra checks but its in future
             */
            //check if king checked after move if not pass
            this->GetPeaceMapPtr()->MovePeace(MovedPeace,NewPeaceBoardPosition,NewPeacePosition);

            if(!IsOwnKingChecked()) {

                if (!MovedPeace->IsKingThere(this, NewPeaceBoardPosition)) {
                    if (MovedPeace->IsEnemyThere(this, NewPeaceBoardPosition)) {
                        this->GetPeaceMapPtr()->DestroyPeace(NewPeaceBoardPosition);
                    }
                    this->NextPlayer();
                    return true;
                }
            }
        }
    }
    this->GetPeaceMapPtr()->MovePeace(MovedPeace,PrevPeaceBoardPosition,PrevPeacePosition);
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

bool ChessBoard::IsOwnKingChecked(){
    sf::Vector2u OwnKingCoordinates = this->GetOwnKingCoordinates();
    std::string EnemyTeam = this->GetEnemyTeam();
    for(unsigned int y = 0; y < this->Size.y; y++){
        for(unsigned int x = 0; x < this->Size.x; x++) {
            if((*this->GetPeaceMapPtr()->GetMapPtr())[y][x] != nullptr){
                if((*this->GetPeaceMapPtr()->GetMapPtr())[y][x]->GetTeam() == EnemyTeam){
                    if((*this->GetPeaceMapPtr()->GetMapPtr())[y][x]->IsAttackingSquare(this,OwnKingCoordinates)){
                        std::cout << "Checked by " << (*this->GetPeaceMapPtr()->GetMapPtr())[y][x]->GetType() << "\n";
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
