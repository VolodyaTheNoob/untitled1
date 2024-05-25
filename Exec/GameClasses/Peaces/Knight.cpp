//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Knight.h"

Knight::Knight() = default;
Knight::Knight(sf::Vector2u Coordinates, sf::Vector2u BoardSize){
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Knight::Knight(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team){
    this->SetTeam(Team);
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Knight::~Knight() = default;
void Knight::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Knight::Destroy(){
    delete this;
}