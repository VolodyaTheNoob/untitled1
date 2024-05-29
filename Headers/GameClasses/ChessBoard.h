//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_CHESSBOARD_H
#define UNTITLED1_CHESSBOARD_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/GameClasses/PeaceMap.h"
#include "Headers/Abstracts/TileMap.h"

class PeaceMap;
class TileMap;
class ChessPeace;
/*
 * Class used to assembly chess game classes and add logic to them
 */
class ChessBoard{
private:
    /*
     * TileMapSize and PeaceMap sizes should be equal - all logic based on this
     */
    //Contain current player id
    std::string CurrentPlayerMove = "White";
    //Contain chess tile map = representation of our board
    TileMap* Tiles;
    //Contain game peaces
    PeaceMap* Peaces;
    //TileMap size
    sf::Vector2u Size;
public:
    ChessBoard();
    ChessBoard(std::string CurrentPlayerMove, TileMap* TileMapPtr, PeaceMap* PeaceMapPtr, sf::Vector2u BoardSize);
    ~ChessBoard();
    bool PlayerMove(ChessPeace* MovedPeace, sf::Vector2u NewPeaceBoardPosition, sf::Vector2f PrevPeacePosition);
    TileMap* GetTileMapPtr();
    PeaceMap* GetPeaceMapPtr();
    sf::Vector2u GetSize();
    std::string GetCurrentPlayerMove();
    void NextPlayer();
    std::string GetEnemyTeam();
    sf::Vector2u GetOwnKingCoordinates();
    sf::Vector2u GetEnemyKingCoordinates();
    bool IsOwnKingChecked();
    bool IsOwnKingCheckmated();
    bool IsTileAttacked(sf::Vector2u NewPeaceBoardPosition);
};

#endif //UNTITLED1_CHESSBOARD_H
