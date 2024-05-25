//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_ROOK_H
#define UNTITLED1_ROOK_H

#include "Headers/GameClasses/ChessPeace.h"

class ChessPeace;

class Rook : public ChessPeace{
private:
    static inline std::string Type = "Rook";
public:
    Rook();
    explicit Rook(sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    explicit Rook(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team);
    ~Rook();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
};

#endif //UNTITLED1_ROOK_H
