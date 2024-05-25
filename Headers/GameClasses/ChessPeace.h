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
    /*
    sf::Sprite *Sprite;
    std::string Name;
    */
    sf::Vector2u Coordinates;//(1,1) | (8,8) - like this
public:
    ChessPeace();
    ~ChessPeace();
    void SetPeaceCoordinates(sf::Vector2f NewCoordinates);
    void SetBoardCoordinates(sf::Vector2u NewCoordinates);
    sf::Vector2f GetPeaceCoordinates();
    sf::Vector2u GetBoardCoordinates();
};


#endif //UNTITLED1_CHESSPEACE_H
