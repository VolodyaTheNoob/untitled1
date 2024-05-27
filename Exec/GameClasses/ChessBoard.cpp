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
    if(MovedPeace->GetTeam() == this->CurrentPlayerMove) {
        if (MovedPeace->IsCanMoveThere(this, NewPeaceBoardPosition)) {
            sf::Vector2f NewPeacePosition = MovedPeace->GetPeaceCoordinates();
            /*If move correct - we create copy of CurrentPeaceMap;
             * We move peace and calculate - is King attacked now
             * if Counters of king attacker not equal Zero - we don't pass move
             * Also in future we should add extra checks but its in future
             */
            //check if king checked after move if not pass
            this->GetPeaceMapPtr()->MovePeace(MovedPeace, NewPeaceBoardPosition, NewPeacePosition);
            this->NextPlayer();
            return true;
        }
    }
    MovedPeace->SetPeaceCoordinates(PrevPeacePosition);
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