//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_ENTITYMANAGER_H
#define UNTITLED1_ENTITYMANAGER_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Abstracts/Entity.h"
#include "Headers/GameClasses/ChessPeace.h"

/*
 * Container for game Entities - uses C++ Templates - to simplify code,
 * Similar with TextureManager - but I don't want to create Abstract class for this,
 * Just not for now
 * <->
 * ATTENTION!
 * You should overload operator= - to store not links, but to create new Object,
 * and copy parameters of Object to this new
 * <->
 */
template<class Object>
class EntityManager {
private:
    std::map<std::string,Object*>Storage;
public:
    EntityManager();
    ~EntityManager();
    void Add(std::string Name, Object* ToAdd);
    void Delete(std::string Name);
    Object* Get(std::string Name);
    std::map<std::string,Object*> GetStorage();
};


#endif //UNTITLED1_ENTITYMANAGER_H
