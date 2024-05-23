//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"
/*
 * ChessMap id's
 * 0 - Empty
 * 1 - WhitePawn
 * 2 - BlackPawn
 * 3 - WhiteTower
 * 4 - BlackTower
 * 5 - WhiteBishop
 * 6 - BlackBishop
 * 7 - WhiteHorse
 * 8 - BlackHorse
 * 9 - WhiteQueen
 * 10 - BlackQueen
 * 11 - WhiteKing
 * 12 - BlackKing
 */
void CreatePeace(Window* WindowPtr,sf::Vector2u Coordinates,std::string PeaceName);

//MainFunctions
void CreateChessPeaces(Window* WindowPtr, std::vector<std::vector<uint32_t>> ChessMap, uint32_t x, uint32_t y) {
    std::map<uint32_t, std::string>PeaceMap;
    PeaceMap[0] = " ";
    PeaceMap[1] = "WhitePawn";
    PeaceMap[2] = "BlackPawn";
    PeaceMap[3] = "WhiteRook";
    PeaceMap[4] = "BlackRook";
    PeaceMap[5] = "WhiteBishop";
    PeaceMap[6] = "BlackBishop";
    PeaceMap[7] = "WhiteKnight";
    PeaceMap[8] = "BlackKnight";
    PeaceMap[9] = "WhiteQueen";
    PeaceMap[10] = "BlackQueen";
    PeaceMap[11] = "WhiteKing";
    PeaceMap[12] = "BlackKing";
    sf::Vector2u CurrentCoordinates;
    for (CurrentCoordinates.y = 0; CurrentCoordinates.y < y; CurrentCoordinates.y++) {
        for (CurrentCoordinates.x = 0; CurrentCoordinates.x < x; CurrentCoordinates.x++) {
            for(unsigned int PeaceMapId = 1; PeaceMapId < 13; PeaceMapId++){
                if(ChessMap[CurrentCoordinates.y][CurrentCoordinates.x] == PeaceMapId){
                    CreatePeace(WindowPtr, CurrentCoordinates, PeaceMap[PeaceMapId]);
                }
            }
        }
    }
}

void CreatePeace(Window* WindowPtr,sf::Vector2u Coordinates,std::string PeaceName){
    ChessPeace *Peace = new ChessPeace(1,1);
    sf::Sprite *PeaceSprite = new sf::Sprite();
    PeaceSprite->setTexture(*WindowPtr->GetTextureManagerPtr()->Get(PeaceName));
    PeaceSprite->setPosition(Coordinates.x * ChessTileSize.x, Coordinates.y * ChessTileSize.y);
    Peace->SetSprite(PeaceSprite);
    Peace->SetName(PeaceName + " " + std::to_string(Coordinates.x) + " " + std::to_string(Coordinates.y));
    Peace->SetBoardCoordinates(Coordinates);
    WindowPtr->GetObjectManagerPtr()->Add(PeaceName + " " + std::to_string(Coordinates.x) + " " + std::to_string(Coordinates.y),Peace);
}