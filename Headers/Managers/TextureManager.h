//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_TEXTUREMANAGER_H
#define UNTITLED1_TEXTUREMANAGER_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
/*
 * Containing SFML sf::Textures
 * <->
 * Usage:
 * create temp texture -> use Add(name, created temp) -> delete temp -> Done.
 * now you can Use get and Delete only by passing name to functions,
 * <->
 * ATTENTION function Add - creates new sf::Texture, so we can freely delete
 * sf::Textures, which not in TextureManagers
 */
class TextureManager {
private:
    std::map<std::string, sf::Texture*>Storage;
public:
    TextureManager();
    ~TextureManager();
    void Add(std::string Name, sf::Texture *ToAdd);
    void Delete(std::string Name);
    sf::Texture* Get(std::string Name);
};


#endif //UNTITLED1_TEXTUREMANAGER_H
