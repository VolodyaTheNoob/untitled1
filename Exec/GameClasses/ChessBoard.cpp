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
bool ChessBoard::IsPlayerMoveCorrect(ChessPeace* MovedPeace, sf::Vector2u NewPeacePosition){
    std::cout << "Move" << "\n";
    return true;
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