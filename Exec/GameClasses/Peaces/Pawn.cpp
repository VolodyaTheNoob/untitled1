//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/Peaces/Pawn.h"

Pawn::Pawn() = default;
Pawn::~Pawn() = default;
void Pawn::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Pawn::Destroy(){
    delete this;
}

Pawn::Pawn(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Pawn::Pawn(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
