//
// Created by SystemX on 25.05.2024.
//
#include "Headers/Abstracts/TileMap.h"

//Constructors
TileMap::TileMap(){
    this->Map = new std::vector<std::vector<Tile*>>(0,std::vector<Tile*>(0));
}
TileMap::TileMap(sf::Vector2u Size){
    this->Size = Size;
    this->Map = new std::vector<std::vector<Tile*>>(this->Size.y,std::vector<Tile*>(this->Size.x));
}
//Destructors
TileMap::~TileMap(){
    --this->CountOfTiles;
}
//Functions
std::vector<std::vector<Tile*>>* TileMap::GetMap(){
    return this->Map;
}
sf::Vector2u TileMap::GetSize(){
    return this->Size;
}
Tile* TileMap::GetTile(sf::Vector2u Coordinates){
    return (*this->Map)[Coordinates.y][Coordinates.x];
}
void TileMap::SetMap(std::vector<std::vector<Tile*>>* NewMap){
    this->Map = NewMap;
}
void TileMap::ResizeMap(){
    if(this->Map != nullptr) {
        delete this->Map;
    }else{
        this->Map = new std::vector<std::vector<Tile *>>(this->Size.y, std::vector<Tile *>(this->Size.x));
    }
}
void TileMap::ResizeMap(sf::Vector2u NewCoordinates){
    this->Size = NewCoordinates;
    if(this->Map != nullptr) {
        delete this->Map;
    }else{
        this->Map = new std::vector<std::vector<Tile *>>(NewCoordinates.y, std::vector<Tile *>(NewCoordinates.x));
    }
}
void TileMap::SetSize(sf::Vector2u NewSize){
    this->Size = NewSize;
}
void TileMap::AddTile(Tile* ToAdd){
    sf::Vector2u CurrentPos;
    CurrentPos.y = this->CountOfTiles / this->Size.y;
    CurrentPos.x = CountOfTiles % Size.x;
    (*this->Map)[CurrentPos.y][CurrentPos.x] = ToAdd;
    ++this->CountOfTiles;
}
void TileMap::ChangeTile(sf::Vector2u Coordinates, Tile *ToChange){
    (*this->Map)[Coordinates.y][Coordinates.x] = ToChange;
}
void TileMap::DeleteTile(sf::Vector2u Coordinates){
    delete (*this->Map)[Coordinates.y][Coordinates.x];
    (*this->Map)[Coordinates.y][Coordinates.x] = new Tile();
}
std::string TileMap::GetTileName(sf::Vector2u Coordinates) {
    (*this->Map)[Coordinates.y][Coordinates.x]->GetName();
}
std::string TileMap::SetTileName(sf::Vector2u Coordinates, std::string NameToSet) {
    (*this->Map)[Coordinates.y][Coordinates.x]->SetName(NameToSet);
}