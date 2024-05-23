//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_CHESSPEACE_H
#define UNTITLED1_CHESSPEACE_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Abstracts/Entity.h"

class ChessPeace : public Entity{

private:
    std::vector<uint32_t>MoveMap;
    bool MoveCount;
    sf::Vector2u Coordinates;//(1,1) | (8,8) - like this
    bool Changeable;
public:
    ChessPeace();
    ChessPeace(bool MoveCount,bool Changeable);
    ~ChessPeace();
    //void Move(std::vector<uint32_t>&ChessMap,sf::Vector2u CoordinatesToMove);
    void SetCoordinates(sf::Vector2f NewCoordinates);
};


#endif //UNTITLED1_CHESSPEACE_H
