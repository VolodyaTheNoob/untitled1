//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_GAMEFUNCTIONS_H
#define UNTITLED1_GAMEFUNCTIONS_H
/*
 * Game functions there - we use them in Event/Render system
 */
#include "Headers/Abstracts/Window.h"
#include "Headers/Constants.h"

void LoadChessTileTexturesToWindow(Window* WindowPtr);
void LoadChessPeacesTexturesToWindow(Window* WindowPtr);
void CreateVirtualChessMap(std::vector<std::vector<uint32_t>> &ChessMap);
void CreateChessBoard(Window* WindowPtr);
void CreateChessPeaces(Window* WindowPtr, std::vector<std::vector<uint32_t>> ChessMap, uint32_t x, uint32_t y);

#endif //UNTITLED1_GAMEFUNCTIONS_H
