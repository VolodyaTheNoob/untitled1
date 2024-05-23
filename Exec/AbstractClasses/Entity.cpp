//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Abstracts/Entity.h"

//Constructors
Entity::Entity(){
    this->Sprite = new sf::Sprite();
}
Entity::Entity(std::string Name, sf::Sprite* Sprite){
    this->Sprite = new sf::Sprite();
    this->SetSprite(Sprite);
    this->SetName(Name);
}
//Destructors
Entity::~Entity() = default;
//Functions
void Entity::SetSprite(sf::Sprite *ToSet) {
    this->Sprite->setTexture(*ToSet->getTexture());
    this->Sprite->setPosition(ToSet->getPosition());
}
void Entity::SetName(std::string ToSet) {
    this->Name = ToSet;
}
sf::Sprite* Entity::GetSprite() {
    return this->Sprite;
}
std::string Entity::GetName() {
    return this->Name;
}
//Operators
Entity& Entity::operator=(Entity* ToCopy){
    if (this == ToCopy) {
        return *this;
    }
    this->SetSprite(ToCopy->Sprite);
    this->Name = ToCopy->Name;
    return *this;
}