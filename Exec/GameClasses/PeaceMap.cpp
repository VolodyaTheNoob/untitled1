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
    //std::string Name, std::string Type, std::string Team sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates
    (*this->Map)[BoardCoordinates.y][BoardCoordinates.x] = new ChessPeace(PeaceToAdd->GetName(),PeaceToAdd->GetType(),PeaceToAdd->GetTeam(),PeaceToAdd->GetSprite(),PeaceToAdd->GetBoardCoordinates(),PeaceToAdd->GetSprite()->getPosition());
}
void PeaceMap::MovePeace(ChessPeace* PeaceToMove, sf::Vector2u BoardCoordinates){
    if((*this->Map)[PeaceToMove->GetBoardCoordinates().y][PeaceToMove->GetBoardCoordinates().x] != nullptr){
        delete (*this->Map)[PeaceToMove->GetBoardCoordinates().y][PeaceToMove->GetBoardCoordinates().x];
    }
    (*this->Map)[PeaceToMove->GetBoardCoordinates().y][PeaceToMove->GetBoardCoordinates().x] = nullptr;
    (*this->Map)[BoardCoordinates.y][BoardCoordinates.x] = PeaceToMove;
    PeaceToMove->SetBoardCoordinates(BoardCoordinates);
    PeaceToMove->SetCalculatedPeaceCoordinates(BoardCoordinates);
}
std::vector<std::vector<ChessPeace*>>* PeaceMap::GetMapPtr(){
    return this->Map;
}