//
// Created by SystemX on 25.05.2024.
//

#include "Headers/Abstracts/Tile.h"
//Constructors
Tile::Tile(){
    ++this->Count;
    this->SetSize(sf::Vector2u(0,0));
    this->Coordinates = sf::Vector2u(0,0);
}
Tile::Tile(std::string Name, sf::Sprite* Sprite){
    ++this->Count;
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->SetSize(sf::Vector2u(0,0));
    this->Coordinates = sf::Vector2u(0,0);
}
Tile::Tile(sf::Vector2u Coordinates,sf::Vector2u Size){
    ++this->Count;
    this->SetSize(Size);
    this->SetCoordinates(Coordinates);
}
Tile::Tile(std::string Name, sf::Sprite* Sprite,sf::Vector2u Size,sf::Vector2u Coordinates){
    ++this->Count;
    this->SetName(Name);
    this->SetSprite(Sprite);
    this->SetSize(Size);
    this->SetCoordinates(Coordinates);
}
//Destructors
Tile::~Tile(){
    --this->Count;
}
//Functions
sf::Vector2u Tile::GetSize(){
    return this->Size;
}
sf::Vector2u Tile::GetCoordinates(){
    return this->Coordinates;
}
sf::Sprite* Tile::GetSprite(){
    return this->Sprite;
}
std::string Tile::GetName(){
    return this->Name;
}
void Tile::SetCoordinates(sf::Vector2u NewCoordinates){
    this->Coordinates = NewCoordinates;
    if(this->GetSprite() != nullptr){
        sf::Vector2f NewTileSpritePos;
        NewTileSpritePos.y = NewCoordinates.y * int(this->Size.y);
        NewTileSpritePos.y = NewCoordinates.x * int(this->Size.x);
        this->GetSprite()->setPosition(NewTileSpritePos);
    }
}
void Tile::SetSize(sf::Vector2u NewSize){
    this->Size = NewSize;
}

uint32_t Tile::GetID(){
    return this->Count;
}
Tile& Tile::operator=(Tile* ToCopy){
    if (this == ToCopy) {
        return *this;
    }
    this->SetSize(ToCopy->GetSize());
    this->Coordinates = ToCopy->GetCoordinates();
    this->SetName(ToCopy->GetName());
    this->SetSprite(ToCopy->GetSprite());
    return *this;
}