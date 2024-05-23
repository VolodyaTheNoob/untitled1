//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_ENTITY_H
#define UNTITLED1_ENTITY_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"

class Entity{
private:
    sf::Sprite *Sprite;
    std::string Name;
public:
    Entity();
    Entity(std::string Name, sf::Sprite* Sprite);
    ~Entity();
    void SetSprite(sf::Sprite *ToSet);
    void SetName(std::string ToSet);
    sf::Sprite* GetSprite();
    std::string GetName();
    Entity& operator=(Entity* ToCopy);
};


#endif //UNTITLED1_ENTITY_H
