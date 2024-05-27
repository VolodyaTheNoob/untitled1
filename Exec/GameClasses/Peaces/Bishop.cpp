//
// Created by SystemX on 25.05.2024.
//
#include "Headers/GameClasses/Peaces/Bishop.h"

Bishop::Bishop() = default;
Bishop::~Bishop() = default;
/*
void Bishop::Destroy(){
    delete this;

*/
Bishop::Bishop(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {

}

Bishop::Bishop(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
               sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {

}
bool Bishop::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
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

bool Bishop::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    if(this->GetBoardCoordinates() != SquareToAttack){
        int OffsetX = abs(int(this->GetBoardCoordinates().x) - int(SquareToAttack.x));
        int OffsetY = abs(int(this->GetBoardCoordinates().y) - int(SquareToAttack.y));
        if(OffsetX == OffsetY){
            sf::Vector2i MoveVector;
            OffsetX = int(this->GetBoardCoordinates().x) - int(SquareToAttack.x);
            OffsetY = int(this->GetBoardCoordinates().y) - int(SquareToAttack.y);
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
            sf::Vector2u TempCoordinatesToMove = SquareToAttack;
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
            return true;
        }
    }
    return false;
}