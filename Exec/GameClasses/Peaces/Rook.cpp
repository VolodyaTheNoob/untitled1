//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Rook.h"
//Constructors
Rook::Rook() = default;
Rook::Rook(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Rook::Rook(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
//Destructors
Rook::~Rook() = default;
//Functions
bool Rook::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    if(!IsKingThere(ChessBoardPtr,CoordinatesToMove) && !IsAllieThere(ChessBoardPtr,CoordinatesToMove)) {
        sf::Vector2u CurrentPosition = this->GetBoardCoordinates();
        sf::Vector2i MoveVector(0,0);
        if(CurrentPosition != CoordinatesToMove){
            int OffsetX = int(CurrentPosition.x) - int(CoordinatesToMove.x);
            int OffsetY = int(CurrentPosition.y) - int(CoordinatesToMove.y);
            sf::Vector2u TempCoordsToMove = CoordinatesToMove;
            if((OffsetX == 0) || (OffsetY == 0)){
               if(OffsetX != 0){
                    if(OffsetX > 0){
                        MoveVector.x = -1;
                    }else{
                        MoveVector.x = 1;
                    }
                   TempCoordsToMove.x -= MoveVector.x;
               }
                if(OffsetY != 0){
                    if(OffsetY > 0){
                        MoveVector.y = -1;
                    }else{
                        MoveVector.y = 1;
                    }
                    TempCoordsToMove.y -= MoveVector.y;
                }
                while(CurrentPosition != TempCoordsToMove){
                    CurrentPosition.x += MoveVector.x;
                    CurrentPosition.y += MoveVector.y;
                    if((*ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr())[CurrentPosition.y][CurrentPosition.x] != nullptr){
                        return false;
                    }
                }
                if(IsTileEmpty(ChessBoardPtr,CoordinatesToMove)) {
                    return true;
                }else{
                    if (IsEnemyThere(ChessBoardPtr, CoordinatesToMove) &&
                        !IsKingThere(ChessBoardPtr, CoordinatesToMove) &&
                        !IsAllieThere(ChessBoardPtr, CoordinatesToMove)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Rook::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    sf::Vector2u CurrentPosition = this->GetBoardCoordinates();
        sf::Vector2i MoveVector(0,0);
        if(CurrentPosition != SquareToAttack) {
            int OffsetX = int(CurrentPosition.x) - int(SquareToAttack.x);
            int OffsetY = int(CurrentPosition.y) - int(SquareToAttack.y);
            sf::Vector2u TempCoordsToMove = SquareToAttack;
            if ((OffsetX == 0) || (OffsetY == 0)) {
                if (OffsetX != 0) {
                    if (OffsetX > 0) {
                        MoveVector.x = -1;
                    } else {
                        MoveVector.x = 1;
                    }
                    TempCoordsToMove.x -= MoveVector.x;
                }
                if (OffsetY != 0) {
                    if (OffsetY > 0) {
                        MoveVector.y = -1;
                    } else {
                        MoveVector.y = 1;
                    }
                    TempCoordsToMove.y -= MoveVector.y;
                }
                while (CurrentPosition != TempCoordsToMove) {
                    CurrentPosition.x += MoveVector.x;
                    CurrentPosition.y += MoveVector.y;
                    if ((*ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr())[CurrentPosition.y][CurrentPosition.x] !=
                        nullptr) {
                        return false;
                    }
                }
                return true;
            }
        }
    return false;
}