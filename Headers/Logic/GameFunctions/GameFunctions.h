//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_GAMEFUNCTIONS_H
#define UNTITLED1_GAMEFUNCTIONS_H
/*
 * Game functions there - we use them in Event/Render system
 */
#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Constants.h"
#include "Headers/GameClasses/Peaces/Peaces.h"
#include "Headers/GameClasses/PeaceMap.h"
#include "Headers/Abstracts/Tile.h"
#include "Headers/Abstracts/TileMap.h"
#include "Headers/GameClasses/ChessBoard.h"
#include "Headers/GameClasses/GameWindow.h"

void LoadChessTileTexturesToTextureManager(TextureManager* TextureManagerPtr);
void LoadChessPeacesTexturesToTextureManager(TextureManager* TextureManagerPtr);
void CreateChessBoard(TileMap* TileMapPtr, TextureManager *TextureManager);
void CreateChessPeaces(PeaceMap* PeaceMapPtr, TextureManager* TextureManagerPtr);

#endif //UNTITLED1_GAMEFUNCTIONS_H
