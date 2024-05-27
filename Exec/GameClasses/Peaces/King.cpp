//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/King.h"

King::King() = default;
King::~King() = default;

bool King::Move(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    if (this->IsCanMoveThere(ChessBoardPtr, CoordinatesToMove)) {
        return true;
    }
    return false;
}
/*
void King::Destroy(){
    delete this;
}
 */

King::King(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

King::King(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}

bool King::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    sf::Vector2u OwnCoordinates = this->GetBoardCoordinates();
    if(OwnCoordinates != CoordinatesToMove){
        int32_t OffsetX = abs(int(OwnCoordinates.x) - int(CoordinatesToMove.x));
        int32_t OffsetY = abs(int(OwnCoordinates.y) - int(CoordinatesToMove.y));
        if(OffsetX < 2 && OffsetY < 2){
            if(IsTileEmpty(ChessBoardPtr,CoordinatesToMove)){
                return true;
            }
        }
    }
    return false;
}

bool King::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    sf::Vector2u OwnCoordinates = this->GetBoardCoordinates();
    if(OwnCoordinates != SquareToAttack){
        int32_t OffsetX = abs(int(OwnCoordinates.x) - int(SquareToAttack.x));
        int32_t OffsetY = abs(int(OwnCoordinates.y) - int(SquareToAttack.y));
        if(OffsetX < 2 && OffsetY < 2){
            return true;
        }
    }
    return false;
}
