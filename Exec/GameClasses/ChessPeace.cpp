//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/ChessPeace.h"

//Constructors
ChessPeace::ChessPeace() = default;
ChessPeace::ChessPeace(bool MoveCount,bool Changeable){
    this->MoveCount = MoveCount;
    this->Changeable = Changeable;
}
//Destructors
ChessPeace::~ChessPeace() = default;
//Functions
void ChessPeace::SetCoordinates(sf::Vector2f NewCoordinates){
    this->GetSprite()->setPosition(NewCoordinates);
}
