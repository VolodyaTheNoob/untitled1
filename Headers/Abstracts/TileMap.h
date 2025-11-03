//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_TILEMAP_H
#define UNTITLED1_TILEMAP_H

#include "Headers/Abstracts/Tile.h"

/*
 * Abstract class used to make Manager for tile/tile movement, also can be used as gane class
 */
class TileMap{
    friend class ChessBoard;
    friend class PeaceMap;
private:
    static inline uint32_t CountOfTiles{};
    std::vector<std::vector<Tile*>> *Map = nullptr;
    //Tile map size
    sf::Vector2u Size;
    //Every tile size
    sf::Vector2u TileSize;
public:
    TileMap();
    TileMap(sf::Vector2u Size, sf::Vector2u TileSize);
    ~TileMap();
    std::vector<std::vector<Tile*>>* GetMapPtr();
    sf::Vector2u GetSize();
    Tile* GetTile(sf::Vector2u Coordinates);
    std::string GetTileName(sf::Vector2u Coordinates);
    std::string SetTileName(sf::Vector2u Coordinates, std::string NameToSet);
    void SetMap(std::vector<std::vector<Tile*>>* NewMap);
    void ResizeMap();
    void ResizeMap(sf::Vector2u NewCoordinates);
    void SetSize(sf::Vector2u NewSize);
    void SetTileSize(sf::Vector2u NewTileSize);
    void AddTile(Tile* ToAdd);
    void ChangeTile(sf::Vector2u Coordinates, Tile *ToChange);
    void DeleteTile(sf::Vector2u Coordinates);
    sf::Vector2u GetTileSize();
};

#endif //UNTITLED1_TILEMAP_H
