//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_PEACEMAP_H
#define UNTITLED1_PEACEMAP_H


#include "Headers/GameClasses/Peaces/ChessPeace.h"
/*
 * Contains all Chess peaces
 */

class ChessPeace;
/*
 * Class used to contain chess peaces
 */
class PeaceMap{
private:
    //MapSize
    sf::Vector2u Size;
    //if position is empty ChessPeace should be nullptr
    std::vector<std::vector<ChessPeace*>>*Map;
public:
    PeaceMap();
    PeaceMap(sf::Vector2u BoardSize);
    ~PeaceMap();
    void AddPeace(ChessPeace* PeaceToAdd, sf::Vector2u BoardCoordinates);
    void MovePeace(ChessPeace* PeaceToMove, sf::Vector2u BoardCoordinates,sf::Vector2f NewPeacePosition);
    std::vector<std::vector<ChessPeace*>>* GetMapPtr();
    sf::Vector2u* GetPeaceBoardCoordinates(std::string Team, std::string Type);
    void DestroyPeace(sf::Vector2u PeaceToDestroyCoordinates);
};

#endif //UNTITLED1_PEACEMAP_H
