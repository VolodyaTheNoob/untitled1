//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_ROOK_H
#define UNTITLED1_ROOK_H

#include "ChessPeace.h"

class ChessPeace;
class Rook : public ChessPeace{
private:
    static inline std::string Type = "Rook";
public:
    Rook();
    using ChessPeace::ChessPeace;
    Rook(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    Rook(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~Rook();
  //  void Destroy() override;
    bool IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove) override;
    bool IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack, sf::Vector2u BoardSize) override;
};

#endif //UNTITLED1_ROOK_H
