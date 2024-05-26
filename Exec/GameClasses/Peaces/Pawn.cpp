//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/Peaces/Pawn.h"

Pawn::Pawn() = default;
Pawn::~Pawn() = default;

bool Pawn::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove) {
    sf::Vector2u CurrentPos = this->GetBoardCoordinates();
    if (CoordinatesToMove.y - CurrentPos.y == (abs(CoordinatesToMove.y - CurrentPos.y) * this->MoveVectorY)) {
        if (abs(CurrentPos.y - CoordinatesToMove.y) < 3) {
            if (abs(CurrentPos.x - CoordinatesToMove.x) < 2) {
                if (abs(CurrentPos.y - CoordinatesToMove.y) == 1) {
                    if(abs(CurrentPos.x - CoordinatesToMove.x) == 1){
                        if (IsEnemyThere(ChessBoardPtr, CoordinatesToMove) && (!IsKingThere(ChessBoardPtr,CoordinatesToMove))) {
                            this->DestroyEnemy(ChessBoardPtr,CoordinatesToMove);
                            this->SetAlreadyMoved(true);
                            return true;
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
bool Pawn::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack, sf::Vector2u BoardSize){
    if(SquareToAttack.x >= BoardSize.x || SquareToAttack.y >= BoardSize.y){
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
void Pawn::SetAlreadyMoved(bool NewState){
    this->AlreadyMoved = NewState;
}
bool Pawn::IsAlreadyMove(){
    return this->AlreadyMoved;
}
