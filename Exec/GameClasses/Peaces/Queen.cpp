//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Queen.h"

Queen::Queen() = default;
Queen::Queen(sf::Vector2u Coordinates, sf::Vector2u BoardSize){
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Queen::Queen(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team){
    this->SetTeam(Team);
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Queen::~Queen() = default;
void Queen::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Queen::Destroy(){
    delete this;
}