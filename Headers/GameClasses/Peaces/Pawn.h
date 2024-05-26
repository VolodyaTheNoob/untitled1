//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_PAWN_H
#define UNTITLED1_PAWN_H

#include "ChessPeace.h"

class ChessPeace;

class Pawn : public ChessPeace{
private:
    static inline std::string Type = "Pawn";
    bool AlreadyMoved;
    int32_t MoveVectorY;
public:
    Pawn();
    using ChessPeace::ChessPeace;
    Pawn(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    Pawn(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    ~Pawn();
    bool Move(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove) override;
    void Destroy() override;
    bool IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove);
    bool IsAttackingSquare(sf::Vector2u SquareToAttack, sf::Vector2u BoardSize) override;
};

#endif //UNTITLED1_PAWN_H
