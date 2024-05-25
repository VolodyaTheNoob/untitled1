//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Knight.h"

Knight::Knight() = default;
Knight::~Knight() = default;
void Knight::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Knight::Destroy(){
    delete this;
}

Knight::Knight(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Knight::Knight(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
