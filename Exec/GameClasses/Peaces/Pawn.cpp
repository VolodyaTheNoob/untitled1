//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/Peaces/Pawn.h"

Pawn::Pawn() = default;
Pawn::Pawn(sf::Vector2u Coordinates, sf::Vector2u BoardSize){
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Pawn::Pawn(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team){
    this->SetTeam(Team);
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->SetBoardCoordinates(Coordinates);
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
Pawn::~Pawn() = default;
void Pawn::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove){
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
bool Pawn::IsCanMoveThere(ChessBoard* BoardPtr, sf::Vector2u CoordinatesToMove){
    std::string Team = this->GetTeam();
    sf::Vector2u StartPos = this->GetBoardCoordinates();
    if(CoordinatesToMove.y - StartPos.y != 0) {
        if (abs(CoordinatesToMove.x - StartPos.x) < 2) {
            if (abs(CoordinatesToMove.y - StartPos.y) < 3) {
                sf::Vector2i MoveVec;
                MoveVec.x = CoordinatesToMove.x - StartPos.x;
                MoveVec.y = CoordinatesToMove.y - StartPos.y;
            }
        }
    }
    return false;
}
void Pawn::Destroy(){
    delete this;
}