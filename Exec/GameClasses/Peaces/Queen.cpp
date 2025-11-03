//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Queen.h"

//Constructors
Queen::Queen() = default;
Queen::Queen(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
             sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}
Queen::Queen(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
             sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
//Destructors
Queen::~Queen() = default;
//Functions
bool Queen::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    if(this->IsCanMoveStraight(ChessBoardPtr,CoordinatesToMove)){
        return true;
    }
    if(this->IsCanMoveCross(ChessBoardPtr,CoordinatesToMove)){
        return true;
    }
    return false;
}

bool Queen::IsCanMoveStraight(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
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

bool Queen::IsCanMoveCross(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    if(this->GetBoardCoordinates() != CoordinatesToMove){
        int OffsetX = abs(int(this->GetBoardCoordinates().x) - int(CoordinatesToMove.x));
        int OffsetY = abs(int(this->GetBoardCoordinates().y) - int(CoordinatesToMove.y));
        if(OffsetX == OffsetY){
            sf::Vector2i MoveVector;
            OffsetX = int(this->GetBoardCoordinates().x) - int(CoordinatesToMove.x);
            OffsetY = int(this->GetBoardCoordinates().y) - int(CoordinatesToMove.y);
            if(OffsetX > 0){
                MoveVector.x = -1;
            }else{
                MoveVector.x = 1;
            }
            if(OffsetY > 0){
                MoveVector.y = -1;
            }else{
                MoveVector.y = 1;
            }
            sf::Vector2u TempCoordinatesToMove = CoordinatesToMove;
            TempCoordinatesToMove.x += MoveVector.x;
            TempCoordinatesToMove.y += MoveVector.y;
            sf::Vector2u CurrentPosition = TempCoordinatesToMove;
            while(CurrentPosition != TempCoordinatesToMove){
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
    return false;
}

bool Queen::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    if(this->IsCanAttackStraight(ChessBoardPtr,SquareToAttack)){
        return true;
    }
    if(this->IsCanAttackCross(ChessBoardPtr,SquareToAttack)){
        return true;
    }
    return false;
}


bool Queen::IsCanAttackStraight(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
        sf::Vector2u CurrentPosition = this->GetBoardCoordinates();
        sf::Vector2i MoveVector(0,0);
        if(CurrentPosition != CoordinatesToMove) {
            int OffsetX = int(CurrentPosition.x) - int(CoordinatesToMove.x);
            int OffsetY = int(CurrentPosition.y) - int(CoordinatesToMove.y);
            sf::Vector2u TempCoordsToMove = CoordinatesToMove;
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

bool Queen::IsCanAttackCross(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    if(this->GetBoardCoordinates() != SquareToAttack){
        int OffsetX = abs(int(this->GetBoardCoordinates().x) - int(SquareToAttack.x));
        int OffsetY = abs(int(this->GetBoardCoordinates().y) - int(SquareToAttack.y));
        if(OffsetX == OffsetY){
            sf::Vector2i MoveVector;
            OffsetX = int(this->GetBoardCoordinates().x) - int(SquareToAttack.x);
            OffsetY = int(this->GetBoardCoordinates().y) - int(SquareToAttack.y);
            sf::Vector2u CurrentPosition = this->GetBoardCoordinates();
            sf::Vector2u TempCoordinatesToMove = SquareToAttack;
            if(OffsetX > 0){
                MoveVector.x = -1;
                TempCoordinatesToMove.x += 1;
            }else{
                MoveVector.x = 1;
                TempCoordinatesToMove.x -=1;
            }
            if(OffsetY > 0){
                MoveVector.y = -1;
                TempCoordinatesToMove.y += 1;
            }else{
                MoveVector.y = 1;
                TempCoordinatesToMove.y -= 1;
            }
            while(CurrentPosition != TempCoordinatesToMove){
                CurrentPosition.x += MoveVector.x;
                CurrentPosition.y += MoveVector.y;
                if((*ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr())[CurrentPosition.y][CurrentPosition.x] != nullptr){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
