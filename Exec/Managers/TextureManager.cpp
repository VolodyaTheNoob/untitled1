//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Managers/TextureManager.h"

//Constructors
TextureManager::TextureManager() = default;
//Destructors
TextureManager::~TextureManager() = default;
//Functions
void TextureManager::Add(std::string Name, sf::Texture *ToAdd){
    this->Storage[Name] = new sf::Texture();
    sf::Image Temp = ToAdd->copyToImage();
    this->Storage[Name]->loadFromImage(Temp);
}
void TextureManager::Delete(std::string Name){
    this->Storage.erase(Name);
}
sf::Texture* TextureManager::Get(std::string Name) {
    return this->Storage[Name];
}