//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_CHESSPEACE_H
#define UNTITLED1_CHESSPEACE_H

#include "Headers/GameClasses/ChessBoard.h"
#include "Headers/Abstracts/Entity.h"
/*
 * Abstract class for game used to build ChessPeaces
 */

class ChessBoard;

class ChessPeace : public Entity{
    friend class Pawn;friend class Bishop;friend class Knight;friend class Rook;friend class Queen;friend class King;
private:
    std::string Type = "Unknown";
    std::string Team = "Unknown";
    sf::Vector2u Coordinates;//(0,0) | (7,7) - like this
public:
    //Constructors
    ChessPeace();
    ChessPeace(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    ChessPeace(std::string Name,std::string Type,std::string Team, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);
    //Destructors
    ~ChessPeace();
    //Override functions
    //Not used
    virtual bool Move(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove);
    //not override anywhere for now
    virtual void Destroy();
    //Not used
    virtual void DestroyEnemy(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    virtual bool IsAttackingSquare(ChessBoard* ChessBoardPtr, sf::Vector2u SquareToAttack);
    virtual bool IsCanMoveThere(ChessBoard* ChessBoardPtr, sf::Vector2u CoordinatesToMove);
    //Copy function - not used now
    virtual ChessPeace* CopySelf();
    //Type - peace type
    std::string GetType();
    void SetType(std::string NewType);
    //Team
    std::string GetTeam();
    void SetTeam(std::string NewTeam);
    //BoardCoordinates
    sf::Vector2u GetBoardCoordinates();
    void SetBoardCoordinates(sf::Vector2u NewCoordinates);
    //PeaceCoordinates
    sf::Vector2f GetPeaceCoordinates();
    void SetPeaceCoordinates(sf::Vector2f NewCoordinates);
    void SetCalculatedPeaceCoordinates(sf::Vector2u chessTileSize);
    //Check functions
    bool IsAllieThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsEnemyThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsTileEmpty(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsKingThere(ChessBoard* ChessBoardPtr,sf::Vector2u CoordinatesToMove);
    bool IsPeaceTurn(ChessBoard* ChessBoardPtr);
};


#endif //UNTITLED1_CHESSPEACE_H
