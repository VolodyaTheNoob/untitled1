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
  //  void Destroy() override;
    bool IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove) override;
    bool IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack, sf::Vector2u BoardSize) override;
};

#endif //UNTITLED1_KNIGHT_H
