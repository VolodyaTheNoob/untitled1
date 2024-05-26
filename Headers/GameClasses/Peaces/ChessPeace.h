//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_CHESSPEACE_H
#define UNTITLED1_CHESSPEACE_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Abstracts/Entity.h"
#include "Headers/GameClasses/ChessBoard.h"

/*
 * Abstract class for game used to build ChessPeaces
 */

class ChessBoard;

class ChessPeace : public Entity{
    friend class Pawn;friend class Bishop;friend class Knight;friend class Rook;friend class Queen;friend class King;
private:
    std::string Type = "Unknown";
    std::string Team = "Unknown";
    sf::Vector2u Coordinates;//(1,1) | (8,8) - like this
public:
    ChessPeace();
    ChessPeace(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    ChessPeace(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);

    ~ChessPeace();
    virtual bool Move(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove);
    virtual void Destroy();
    virtual void DestroyEnemy(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    std::string GetType();
    void SetType(std::string NewType);
    std::string GetTeam();
    sf::Vector2u GetBoardCoordinates();
    void SetCalculatedPeaceCoordinates(sf::Vector2u ChessTileSize);
    void SetBoardCoordinates(sf::Vector2u NewCoordinates);
    void SetPeaceCoordinates(sf::Vector2f NewCoordinates);
    sf::Vector2f GetPeaceCoordinates();
    void SetTeam(std::string NewTeam);
    bool IsAllieThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsEnemyThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsTileEmpty(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsKingThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsPeaceTurn(ChessBoard* ChessBoardPtr);
    virtual void* CopySelf();
    virtual bool IsAttackingSquare(sf::Vector2u SquareToAttack, sf::Vector2u BoardSize);
};


#endif //UNTITLED1_CHESSPEACE_H
