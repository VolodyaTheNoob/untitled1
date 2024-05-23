//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Managers/EntityManager.h"

//Constructors
template<class Object>
EntityManager<Object>::EntityManager() = default;

//Destructors
template<class Object>
EntityManager<Object>::~EntityManager() = default;

/*
 * Functions
*/

template<class Object>
void EntityManager<Object>::Add(std::string Name, Object* ToAdd){
    this->Storage[Name] = ToAdd;
}
template<class Object>
void EntityManager<Object>::Delete(std::string Name){
    this->Storage.erase(Name);
}
template<class Object>
Object* EntityManager<Object>::Get(std::string Name){
    return this->Storage[Name];
}
/*
 * Description:
 * One of solution for successful work of this code,
 * it's to add templates at the end of *.cpp file,
 * we should do it if we use separate files, I mean Header + CPP
 * Use:
 * just add classes for entity manager in <*>, example:
 * template class EntityManager<ClassName>
 */
template class EntityManager<sf::Sprite>;
template class EntityManager<Entity>;
template class EntityManager<ChessPeace>;