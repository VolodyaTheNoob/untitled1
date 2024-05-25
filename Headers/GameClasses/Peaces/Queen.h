//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_QUEEN_H
#define UNTITLED1_QUEEN_H

#include "Headers/GameClasses/ChessPeace.h"

class ChessPeace;

class Queen : public ChessPeace{
private:
    static inline std::string Type = "Queen";
public:
    Queen();
    explicit Queen(sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    explicit Queen(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team);
    ~Queen();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_QUEEN_H
