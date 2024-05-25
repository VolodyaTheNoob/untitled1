//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/Peaces/ChessPeace.h"

//Constructors
ChessPeace::ChessPeace(){
    this->SetTeam("Unknown");
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
void ChessPeace::Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) {
    this->SetBoardCoordinates(CoordinatesToMove);
    this->SetPeaceCoordinates(PeaceCoordinatesToMove);
}
void ChessPeace::SetCalculatedPeaceCoordinates(sf::Vector2u ChessTileSize) {
    float LocalX = float(this->Coordinates.x) * float(ChessTileSize.x);
    float LocalY = float(this->Coordinates.y) * float(ChessTileSize.y);
    this->SetPeaceCoordinates(sf::Vector2f(LocalX, LocalY));
}
void ChessPeace::Destroy(){
    delete this;
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
void ChessPeace::SetSprite(sf::Sprite *ToSet){
    if(this->Sprite == nullptr){
        this->Sprite = new sf::Sprite;
    }
    this->Sprite->setTexture(*ToSet->getTexture());
    this->Sprite->setPosition(ToSet->getPosition());
}
void ChessPeace::SetName(std::string ToSet){
    this->Name = ToSet;
}