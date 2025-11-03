//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/Peaces/Pawn.h"
//Constructors
Pawn::Pawn() = default;
Pawn::Pawn(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2f SpriteCoordinates) : ChessPeace(Name, Type, Team, Sprite, Coordinates, SpriteCoordinates) {
    this->MoveVectorY = 1;
    if(this->GetTeam() == "White"){
        MoveVectorY *= -1;
    }
}
Pawn::Pawn(std::string Name, std::string Type, std::string Team, sf::Sprite *Sprite, sf::Vector2u Coordinates,
           sf::Vector2u BoardSize) : ChessPeace(Name, Type, Team, Sprite, Coordinates, ChessTileSize) {
    this->MoveVectorY = 1;
    if(this->GetTeam() == "White"){
        MoveVectorY *= -1;
    }
}
//Destructors
Pawn::~Pawn() = default;
//Functions
bool Pawn::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove) {
    sf::Vector2u CurrentPos = this->GetBoardCoordinates();
    if (CoordinatesToMove.y - CurrentPos.y == (abs(CoordinatesToMove.y - CurrentPos.y) * this->MoveVectorY)) {
        if (abs(CurrentPos.y - CoordinatesToMove.y) < 3) {
            if (abs(CurrentPos.x - CoordinatesToMove.x) < 2) {
                if (abs(CurrentPos.y - CoordinatesToMove.y) == 1) {
                    if(abs(CurrentPos.x - CoordinatesToMove.x) == 1) {
                        if (!IsTileEmpty(ChessBoardPtr, CoordinatesToMove)) {
                            if(!IsKingThere(ChessBoardPtr,CoordinatesToMove)) {
                                if(IsEnemyThere(ChessBoardPtr,CoordinatesToMove)){
                                this->SetAlreadyMoved(true);
                                return true;
                            }
                        }
                    }
                    }else{
                        if (IsTileEmpty(ChessBoardPtr,CoordinatesToMove)) {
                            this->SetAlreadyMoved(true);
                            return true;
                        }
                    }
                }else{
                    if(!this->IsAlreadyMove()) {
                        if (abs(CurrentPos.y - CoordinatesToMove.y) == 2) {
                            if (abs(CurrentPos.x - CoordinatesToMove.x) == 0) {
                                if (IsTileEmpty(ChessBoardPtr, CoordinatesToMove)) {
                                    this->SetAlreadyMoved(true);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool Pawn::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    if(SquareToAttack.x >= ChessBoardPtr->GetSize().x || SquareToAttack.y >= ChessBoardPtr->GetSize().y){
        return false;
    }
    sf::Vector2u AttackerCoordinates = this->GetBoardCoordinates();
    AttackerCoordinates.y += this->MoveVectorY;
    if(AttackerCoordinates.x != 8){
        AttackerCoordinates.x += 1;
        if(AttackerCoordinates == SquareToAttack){
            return true;
        }
    }
    if(AttackerCoordinates.x != 1 ){
        AttackerCoordinates.x -= 2;
        if(AttackerCoordinates == SquareToAttack){
            return true;
        }
    }
    return false;
}

void Pawn::SetAlreadyMoved(bool NewState){
    this->AlreadyMoved = NewState;
}
bool Pawn::IsAlreadyMove(){
    return this->AlreadyMoved;
}
