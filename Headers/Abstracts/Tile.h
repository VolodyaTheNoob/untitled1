//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_TILE_H
#define UNTITLED1_TILE_H
/*
 * Abstract class used to create game tiles - can be used as game class
 */
#include "Headers/Abstracts/Entity.h"

class Tile:Entity{
    friend class TileMap;
private:
    static inline uint32_t Count{};
    sf::Vector2u Coordinates;
    sf::Vector2u Size;
public:
    Tile();
    Tile(std::string Name, sf::Sprite* Sprite);
    Tile(sf::Vector2u Coordinates,sf::Vector2u Size);
    Tile(std::string Name, sf::Sprite* Sprite,sf::Vector2u Size, sf::Vector2u Coordinates);
    ~Tile();
    sf::Vector2u GetSize();
    sf::Vector2u GetCoordinates();
    sf::Sprite* GetSprite() override;
    std::string GetName() override;
    void SetCoordinates(sf::Vector2u NewCoordinates);
    void SetSize(sf::Vector2u NewSize);
    uint32_t GetID();
    Tile& operator=(Tile* ToCopy);
};

#endif //UNTITLED1_TILE_H
