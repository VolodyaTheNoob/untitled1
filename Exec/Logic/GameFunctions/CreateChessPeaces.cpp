//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"


void CreatePeace(PeaceMap* PeaceMapPtr, TextureManager* TextureManagerPtr,sf::Vector2u Coordinates,std::string PeaceName,std::string PeaceType, std::string PeaceTeam);

//MainFunctions
void CreateChessPeaces(PeaceMap* PeaceMapPtr, TextureManager* TextureManagerPtr) {
    uint32_t LocalChessMap[8][8] =
            {
                    {3,5,7,9,11,7,5,3},
                    {1,1,1,1,1,1,1,1},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {2,2,2,2,2,2,2,2},
                    {4,6,8,10,12,8,6,4},
            };



    std::map<uint32_t, std::string>PeaceNameMap;
    PeaceNameMap[0] = " ";
    PeaceNameMap[1] = "BlackPawn";
    PeaceNameMap[2] = "WhitePawn";
    PeaceNameMap[3] = "BlackRook";
    PeaceNameMap[4] = "WhiteRook";
    PeaceNameMap[5] = "BlackBishop";
    PeaceNameMap[6] = "WhiteBishop";
    PeaceNameMap[7] = "BlackKnight";
    PeaceNameMap[8] = "WhiteKnight";
    PeaceNameMap[9] = "BlackQueen";
    PeaceNameMap[10] = "WhiteQueen";
    PeaceNameMap[11] = "BlackKing";
    PeaceNameMap[12] = "WhiteKing";
    std::map<uint32_t, std::string>PeaceTypeMap;
    PeaceTypeMap[0] = " ";
    PeaceTypeMap[2] = "Pawn";
    PeaceTypeMap[4] = "Rook";
    PeaceTypeMap[6] = "Bishop";
    PeaceTypeMap[8] = "Knight";
    PeaceTypeMap[10] = "Queen";
    PeaceTypeMap[12] = "King";
    sf::Vector2u CurrentCoordinates;
    for (CurrentCoordinates.y = 0; CurrentCoordinates.y < 8; CurrentCoordinates.y++) {
        for (CurrentCoordinates.x = 0; CurrentCoordinates.x < 8; CurrentCoordinates.x++) {
            for(unsigned int PeaceMapId = 0; PeaceMapId < 13; PeaceMapId++) {
                if (PeaceMapId == 0) {
                    (*PeaceMapPtr->GetMapPtr())[CurrentCoordinates.y][CurrentCoordinates.x] = nullptr;
                } else {
                    if (LocalChessMap[CurrentCoordinates.y][CurrentCoordinates.x] == PeaceMapId) {
                        std::string Team;
                        int Offset = 0;
                        if ((CurrentCoordinates.y + CurrentCoordinates.x) % 2 == 0) {
                            Team = "White";
                        } else {
                            Team = "Black";
                            Offset = 1;
                        }
                        CreatePeace(PeaceMapPtr, TextureManagerPtr, CurrentCoordinates, PeaceNameMap[PeaceMapId],
                                    PeaceTypeMap[PeaceMapId - Offset], Team);
                    }
                }
            }
        }
    }
}

void CreatePeace(PeaceMap* PeaceMapPtr, TextureManager* TextureManagerPtr,sf::Vector2u Coordinates,std::string PeaceName,std::string PeaceType, std::string PeaceTeam){
    sf::Sprite *PeaceSprite = new sf::Sprite();
    PeaceSprite->setTexture(*TextureManagerPtr->Get(PeaceName));
    PeaceSprite->setPosition(Coordinates.x * ChessTileSize.x, Coordinates.y * ChessTileSize.y);
    ChessPeace *Peace = new ChessPeace(PeaceName,PeaceSprite,Coordinates,PeaceSprite->getPosition());
    Peace->SetSprite(PeaceSprite);
    Peace->SetTeam(PeaceTeam);
    Peace->SetType(PeaceType);
    PeaceMapPtr->AddPeace(Peace,Coordinates);
}

