//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_PEACEMAP_H
#define UNTITLED1_PEACEMAP_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/GameClasses/ChessPeace.h"
/*
 * Contains all Chess peaces
 */
class ChessPeace;

class PeaceMap{
private:
    sf::Vector2u Size;
    std::vector<std::vector<ChessPeace*>>*Map;
public:
    PeaceMap();
    PeaceMap(sf::Vector2u BoardSize);
    ~PeaceMap();
    void AddPeace(ChessPeace* PeaceToAdd, sf::Vector2u BoardCoordinates);
    void MovePeace(ChessPeace* PeaceToMove, sf::Vector2u BoardCoordinates);
};

#endif //UNTITLED1_PEACEMAP_H
