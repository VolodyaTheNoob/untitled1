//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_PAWN_H
#define UNTITLED1_PAWN_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/GameClasses/ChessPeace.h"

class Pawn : public ChessPeace{
private:
    static inline std::string Type = "Pawn";
public:
    Pawn();
    explicit Pawn(sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    explicit Pawn(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize,std::string Team);
    ~Pawn();
    void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    bool IsCanMoveThere(ChessBoard* BoardPtr, sf::Vector2u CoordinatesToMove);
    void Destroy() override;
};

#endif //UNTITLED1_PAWN_H
