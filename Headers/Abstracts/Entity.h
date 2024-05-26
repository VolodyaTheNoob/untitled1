//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_ENTITY_H
#define UNTITLED1_ENTITY_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Constants.h"
/*
 * Abstract class used to build own Entity/Object classes
 */
class Entity{
    friend class Tile;
    friend class TileMap;
    friend class ChessPeace;
private:
    sf::Sprite *Sprite = nullptr;
    std::string Name;
public:
    Entity();
    Entity(std::string Name, sf::Sprite* Sprite);
    ~Entity();
    virtual void SetSprite(sf::Sprite *ToSet);
    virtual void SetName(std::string ToSet);
    virtual sf::Sprite* GetSprite();
    virtual std::string GetName();
    //Entity& operator=(Entity* ToCopy);
};


#endif //UNTITLED1_ENTITY_H
