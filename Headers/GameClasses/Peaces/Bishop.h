//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_BISHOP_H
#define UNTITLED1_BISHOP_H

#include "ChessPeace.h"

class ChessPeace;

class Bishop : public ChessPeace{
private:
    static inline std::string Type = "Bishop";
public:
    Bishop();
    using ChessPeace::ChessPeace;
    Bishop(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    Bishop(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~Bishop();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};
#endif //UNTITLED1_BISHOP_H
