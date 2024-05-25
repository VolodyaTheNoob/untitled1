//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/ChessPeace.h"

//Constructors
ChessPeace::ChessPeace(){
    this->SetTeam("Unknown");
}

ChessPeace::ChessPeace(sf::Vector2u Coordinates) {
    this->SetTeam("Unknown");
    this->Coordinates = Coordinates;
}
ChessPeace::ChessPeace(sf::Vector2u Coordinates, sf::Vector2u BoardSize) {
    this->SetTeam("Unknown");
    this->Coordinates = Coordinates;
    this->SetCalculatedPeaceCoordinates(BoardSize);
}
ChessPeace::ChessPeace(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates) {
    this->SetTeam("Unknown");
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->Coordinates = Coordinates;
}
ChessPeace::ChessPeace(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize) {
    this->SetTeam("Unknown");
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->Coordinates = Coordinates;
    this->SetCalculatedPeaceCoordinates(BoardSize);
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
void ChessPeace::SetCalculatedPeaceCoordinates(sf::Vector2u BoardSize){
    this->SetPeaceCoordinates(sf::Vector2f (float(this->GetBoardCoordinates().y) * float(BoardSize.y),float(this->GetBoardCoordinates().x) * float(BoardSize.x)));
}
void ChessPeace::Destroy(){
    delete this;
}
std::string ChessPeace::GetType(){
    return this->Type;
}
std::string ChessPeace::GetTeam() {
    return this->Team;
}
void ChessPeace::SetTeam(std::string NewTeam){
    this->Team = NewTeam;
}