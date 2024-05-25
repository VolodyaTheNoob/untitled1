//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_KING_H
#define UNTITLED1_KING_H

#include "ChessPeace.h"

class ChessPeace;

class King : public ChessPeace{
private:
    static inline std::string Type = "King";
public:
    King();
    using ChessPeace::ChessPeace;
    King(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    King(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~King();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_KING_H
