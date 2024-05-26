//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Knight.h"

Knight::Knight() = default;
Knight::~Knight() = default;

/*
void Knight::Destroy(){
    delete this;
}
*/

Knight::Knight(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Knight::Knight(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}

bool Knight::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    if(!IsKingThere(ChessBoardPtr,CoordinatesToMove) && !IsAllieThere(ChessBoardPtr,CoordinatesToMove)) {
        std::cout << 1;
        if (CoordinatesToMove.x < ChessBoardPtr->GetTileMapPtr()->GetSize().x &&
            CoordinatesToMove.y < ChessBoardPtr->GetTileMapPtr()->GetSize().y) {
            sf::Vector2u OwnCoordinates = this->GetBoardCoordinates();
            int OffsetX = abs(int(OwnCoordinates.x) - int(CoordinatesToMove.x));
            int OffsetY = abs(int(OwnCoordinates.y) - int(CoordinatesToMove.y));
            if ((OffsetX == 1 || OffsetX == 2) && (OffsetY == 1 || OffsetY == 2)) {
                if (abs(OffsetX - OffsetY) == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Knight::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack, sf::Vector2u BoardSize){
    if(IsCanMoveThere(ChessBoardPtr,SquareToAttack)){
        return true;
    }
    return false;
}