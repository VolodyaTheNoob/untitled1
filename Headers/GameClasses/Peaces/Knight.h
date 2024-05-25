//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_KNIGHT_H
#define UNTITLED1_KNIGHT_H

#include "Headers/GameClasses/ChessPeace.h"

class ChessPeace;

class Knight : public ChessPeace{
private:
    static inline std::string Type = "Knight";
public:
    Knight();
    explicit Knight(sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    explicit Knight(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team);
    ~Knight();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_KNIGHT_H
