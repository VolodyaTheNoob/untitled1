//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/Peaces/ChessPeace.h"

//Constructors
ChessPeace::ChessPeace(){
    this->SetType("Unknown");
}
ChessPeace::ChessPeace(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates){
    this->SetTeam(Team);
    this->SetType(Type);
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->Coordinates = Coordinates;
    this->Sprite->setPosition(SpriteCoordinates);
}
ChessPeace::ChessPeace(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize){
    this->SetTeam(Team);
    this->SetType(Type);
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->Coordinates = Coordinates;
    this->SetCalculatedPeaceCoordinates(ChessTileSize);
}
//Destructors
ChessPeace::~ChessPeace() = default;
//Functions
void ChessPeace::SetPeaceCoordinates(sf::Vector2f NewCoordinates){
    this->GetSprite()->setPosition(NewCoordinates);
}
void ChessPeace::SetBoardCoordinates(sf::Vector2u NewCoordinates) {
    this->Coordinates = NewCoordinates;
}
sf::Vector2f ChessPeace::GetPeaceCoordinates(){
    return this->GetSprite()->getPosition();
}
sf::Vector2u ChessPeace::GetBoardCoordinates(){
    return this->Coordinates;
}
bool ChessPeace::Move(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove) {
    if (this->IsCanMoveThere(ChessBoardPtr, CoordinatesToMove)) {
        return true;
    }
    return false;
}
void ChessPeace::Destroy(){
    delete this;
}
void ChessPeace::SetCalculatedPeaceCoordinates(sf::Vector2u chessTileSize) {
    float LocalX = float(this->Coordinates.x) * float(chessTileSize.x);
    float LocalY = float(this->Coordinates.y) * float(chessTileSize.y);
    this->SetPeaceCoordinates(sf::Vector2f(LocalX, LocalY));
}

void ChessPeace::DestroyEnemy(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove) {
    if((*ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr())[CoordinatesToMove.y][CoordinatesToMove.x] != nullptr) {
        (*ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr())[CoordinatesToMove.y][CoordinatesToMove.x]->Destroy();
    }
    (*ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr())[CoordinatesToMove.y][CoordinatesToMove.x] = nullptr;
}
std::string ChessPeace::GetType(){
    return this->Type;
}
void ChessPeace::SetType(std::string NewType){
    this->Type = NewType;
}
std::string ChessPeace::GetTeam() {
    return this->Team;
}
void ChessPeace::SetTeam(std::string NewTeam){
    this->Team = NewTeam;
}
bool ChessPeace::IsAllieThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove){
    if((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x] != nullptr) {
        if ((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x]->GetTeam() ==
            ChessBoardPtr->GetCurrentPlayerMove()) {
            return true;
        }
    }
    return false;
}
bool ChessPeace::IsEnemyThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove){
    if((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x] != nullptr) {
        if ((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x]->GetTeam() !=
            ChessBoardPtr->GetCurrentPlayerMove()) {
            return true;
        }
    }
    return false;
}
bool ChessPeace::IsTileEmpty(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove){
    if((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x] == nullptr){
        return true;
    }
    return false;
}
bool ChessPeace::IsKingThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove){
    if((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x] != nullptr) {
        if ((*(ChessBoardPtr->GetPeaceMapPtr()->GetMapPtr()))[CoordinatesToMove.y][CoordinatesToMove.x]->GetType() ==
            "King") {
            return true;
        }
    }
    return false;
}
bool ChessPeace::IsPeaceTurn(ChessBoard* ChessBoardPtr){
    if(this->Team == ChessBoardPtr->GetCurrentPlayerMove()){
        return true;
    }
        return false;
}
ChessPeace* ChessPeace::CopySelf(){
    return new ChessPeace(this->GetName(), this->GetType(),this->GetTeam(),this->GetSprite(),this->GetBoardCoordinates(),this->GetPeaceCoordinates());
}
bool ChessPeace::IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack){
    return true;
}
bool ChessPeace::IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove){
    return true;
}