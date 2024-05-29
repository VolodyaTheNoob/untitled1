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
    bool IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove) override;
    bool IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack) override;
    void SetAlreadyMoved(bool NewState);
    bool IsAlreadyMove();
};

#endif //UNTITLED1_PAWN_H
