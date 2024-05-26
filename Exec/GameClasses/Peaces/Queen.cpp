//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Queen.h"

Queen::Queen() = default;
Queen::~Queen() = default;

void Queen::Destroy(){
    delete this;
}

Queen::Queen(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
             sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Queen::Queen(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
             sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
