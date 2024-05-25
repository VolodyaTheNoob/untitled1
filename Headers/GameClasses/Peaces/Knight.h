//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_KNIGHT_H
#define UNTITLED1_KNIGHT_H

#include "ChessPeace.h"

class ChessPeace;

class Knight : public ChessPeace{
private:
    static inline std::string Type = "Knight";
public:
    Knight();
    using ChessPeace::ChessPeace;
    Knight(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    Knight(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~Knight();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_KNIGHT_H
