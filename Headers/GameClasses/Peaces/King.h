//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_KING_H
#define UNTITLED1_KING_H

#include "Headers/GameClasses/ChessPeace.h"

class ChessPeace;

class King : public ChessPeace{
private:
    static inline std::string Type = "King";
public:
    King();
    explicit King(sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    explicit King(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team);
    ~King();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_KING_H
