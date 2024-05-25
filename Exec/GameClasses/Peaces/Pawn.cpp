//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/Peaces/Pawn.h"

Pawn::Pawn() = default;
Pawn::Pawn(sf::Vector2u Coordinates, sf::Vector2u BoardSize){
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Pawn::Pawn(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team){
    this->SetTeam(Team);
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Pawn::~Pawn() = default;
void Pawn::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Pawn::Destroy(){
    delete this;
}