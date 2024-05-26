//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Rook.h"

Rook::Rook() = default;
Rook::~Rook() = default;
bool Rook::Move(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void Rook::Destroy(){
    delete this;
}

Rook::Rook(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Rook::Rook(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
