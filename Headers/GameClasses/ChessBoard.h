//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_CHESSBOARD_H
#define UNTITLED1_CHESSBOARD_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/GameClasses/GameWindow.h"
#include "Headers/GameClasses/PeaceMap.h"
#include "Headers/Abstracts/TileMap.h"


class ChessBoard{
private:
    bool IsFlipped = false;
    std::string CurrentPlayerMove = "White";
    TileMap Tiles;
    PeaceMap Peaces;
    sf::Vector2u Size;
    Window* Wnd;
public:
    ChessBoard();
    ~ChessBoard();
};

#endif //UNTITLED1_CHESSBOARD_H
