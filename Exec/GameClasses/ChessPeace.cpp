//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/ChessPeace.h"

//Constructors
ChessPeace::ChessPeace() = default;
//Destructors
ChessPeace::~ChessPeace() = default;
//Functions
void ChessPeace::SetPeaceCoordinates(sf::Vector2f NewCoordinates){
    this->GetSprite()->setPosition(NewCoordinates);
}
void ChessPeace::SetBoardCoordinates(sf::Vector2u NewCoordinates) {
    this->Coordinates = NewCoordinates;
}
sf::Vector2f ChessPeace::GetPeaceCoordinates(){
    return this->GetSprite()->getPosition();
}
sf::Vector2u ChessPeace::GetBoardCoordinates(){
    return this->Coordinates;
}