//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_CHESSBOARD_H
#define UNTITLED1_CHESSBOARD_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
//#include "Headers/GameClasses/GameWindow.h"
#include "Headers/GameClasses/PeaceMap.h"
#include "Headers/Abstracts/TileMap.h"

class Window;
class PeaceMap;

class ChessBoard{
private:
    bool IsFlipped = false;
    std::string CurrentPlayerMove = "White";
    TileMap* Tiles;
    PeaceMap* Peaces;
    sf::Vector2u Size;
public:
    ChessBoard();
    ChessBoard(bool IsFlipped,std::string CurrentPlayerMove, TileMap* TileMapPtr, PeaceMap* PeaceMapPtr, sf::Vector2u BoardSize);
    ~ChessBoard();
    void GameLogic();
};

#endif //UNTITLED1_CHESSBOARD_H
