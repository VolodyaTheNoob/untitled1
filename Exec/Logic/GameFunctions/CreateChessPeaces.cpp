//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"

void CreatePeace(PeaceMap* PeaceMapPtr,TextureManager* TextureManagerPtr, std::string Team, std::string PeaceType, sf::Vector2u Coordinates, sf::Vector2u ChessTileSize);

void CreateChessPeaces(PeaceMap* PeaceMapPtr,TextureManager* TextureManagerPtr){
    uint32_t VirtualChessMap[8][8] = {
            {2,3,4,5,6,4,3,2},
            {1,1,1,1,1,1,1,1},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {7,7,7,7,7,7,7,7},
            {8,9,10,11,12,10,9,8},
    };
    std::map<uint32_t,std::string>IdToPeaceType;
    IdToPeaceType[0] = "Null";
    IdToPeaceType[1] = "Pawn";
    IdToPeaceType[2] = "Rook";
    IdToPeaceType[3] = "Bishop";
    IdToPeaceType[4] = "Knight";
    IdToPeaceType[5] = "Queen";
    IdToPeaceType[6] = "King";
    IdToPeaceType[7] = "Pawn";
    IdToPeaceType[8] = "Rook";
    IdToPeaceType[9] = "Bishop";
    IdToPeaceType[10] = "Knight";
    IdToPeaceType[11] = "Queen";
    IdToPeaceType[12] = "King";
    std::string Team;
    sf::Vector2u CurrentCoordinates(0,0);
    for(CurrentCoordinates.y = 0;CurrentCoordinates.y < 8; CurrentCoordinates.y++){
        for(CurrentCoordinates.x = 0;CurrentCoordinates.x < 8; CurrentCoordinates.x++){
            if(VirtualChessMap[CurrentCoordinates.y][CurrentCoordinates.x] > 6){
                Team = "White";
            }else{
                Team = "Black";
            }
            CreatePeace(PeaceMapPtr,TextureManagerPtr,Team,IdToPeaceType[VirtualChessMap[CurrentCoordinates.y][CurrentCoordinates.x]],CurrentCoordinates, ChessTileSize);
        }
    }
}

void CreatePeace(PeaceMap* PeaceMapPtr,TextureManager* TextureManagerPtr, std::string Team, std::string PeaceType, sf::Vector2u Coordinates, sf::Vector2u ChessTileSize) {
    if (PeaceType != "Null") {
        sf::Sprite *TempSprite = new sf::Sprite;
        TempSprite->setTexture(*TextureManagerPtr->Get(Team + PeaceType));
        if (PeaceType == "Pawn") {
            (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = new Pawn(Team + PeaceType, PeaceType, Team,
                                                                                 TempSprite, Coordinates,
                                                                                 ChessTileSize);
        }
        if (PeaceType == "Rook") {
            (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = new Rook(Team + PeaceType, PeaceType, Team,
                                                                                 TempSprite, Coordinates,
                                                                                 ChessTileSize);

        }
        if (PeaceType == "Bishop") {
            (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = new Bishop(Team + PeaceType, PeaceType, Team,
                                                                                   TempSprite, Coordinates,
                                                                                   ChessTileSize);
        }
        if (PeaceType == "Knight") {
            (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = new King(Team + PeaceType, PeaceType, Team,
                                                                                 TempSprite, Coordinates,
                                                                                 ChessTileSize);
        }
        if (PeaceType == "Queen") {
            (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = new Queen(Team + PeaceType, PeaceType, Team,
                                                                                  TempSprite, Coordinates,
                                                                                  ChessTileSize);
        }
        if (PeaceType == "King") {
            (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = new King(Team + PeaceType, PeaceType, Team,
                                                                                 TempSprite, Coordinates,
                                                                                 ChessTileSize);
        }
    }else{
        (*PeaceMapPtr->GetMapPtr())[Coordinates.y][Coordinates.x] = nullptr;
    }
}