//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_QUEEN_H
#define UNTITLED1_QUEEN_H

#include "ChessPeace.h"

class ChessPeace;

class Queen : public ChessPeace{
private:
    static inline std::string Type = "Queen";
public:
    Queen();
    using ChessPeace::ChessPeace;
    Queen(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    Queen(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~Queen();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_QUEEN_H
