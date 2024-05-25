//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Bishop.h"

Bishop::Bishop() = default;
Bishop::~Bishop() = default;
void Bishop::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Bishop::Destroy(){
    delete this;
}

Bishop::Bishop(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Bishop::Bishop(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
