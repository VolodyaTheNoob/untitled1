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
    bool IsCanMoveCross(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove);
    bool IsCanMoveStraight(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove);
public:
    Queen();
    using ChessPeace::ChessPeace;
    Queen(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    Queen(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~Queen();
   // void Destroy() override;
    bool IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove) override;
    bool IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack) override;
    bool IsCanAttackStraight(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack);
    bool IsCanAttackCross(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack);
};

#endif //UNTITLED1_QUEEN_H
