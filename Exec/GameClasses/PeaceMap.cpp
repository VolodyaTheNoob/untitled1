//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/PeaceMap.h"

//Constructors
PeaceMap::PeaceMap(){
    this->Size = sf::Vector2u(0,0);
    this->Map = new std::vector<std::vector<ChessPeace*>>(0,std::vector<ChessPeace*>(0));
}
PeaceMap::PeaceMap(sf::Vector2u BoardSize){
    this->Size = BoardSize;
    this->Map = new std::vector<std::vector<ChessPeace*>>(BoardSize.y,std::vector<ChessPeace*>(BoardSize.x));
}
//Destructors
PeaceMap::~PeaceMap() = default;
//Functions
void PeaceMap::AddPeace(ChessPeace* PeaceToAdd, sf::Vector2u BoardCoordinates){
    (*this->Map)[BoardCoordinates.y][BoardCoordinates.x] = PeaceToAdd;
}
void PeaceMap::MovePeace(ChessPeace* PeaceToMove, sf::Vector2u BoardCoordinates){
    (*this->Map)[PeaceToMove->GetBoardCoordinates().y][PeaceToMove->GetBoardCoordinates().x] = nullptr;
    (*this->Map)[BoardCoordinates.y][BoardCoordinates.x] = PeaceToMove;
    PeaceToMove->SetBoardCoordinates(BoardCoordinates);
    PeaceToMove->SetCalculatedPeaceCoordinates(BoardCoordinates);
}