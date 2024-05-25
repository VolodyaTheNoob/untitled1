//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"
/*
void CreateChessBoard(Window* WindowPtr){
    EntityManager<Entity>* TileManagerPtr = WindowPtr->GetTileManagerPtr();
    sf::Sprite *WhiteTileSprite = new sf::Sprite;
    WhiteTileSprite->setTexture(*WindowPtr->GetTextureManagerPtr()->Get("WhiteTile"));
    sf::Sprite *BlackTileSprite = new sf::Sprite;
    BlackTileSprite->setTexture(*WindowPtr->GetTextureManagerPtr()->Get("BlackTile"));

    sf::Vector2f Position;
    for(unsigned int y = 0; y < 8; ++y){
        for(unsigned int x = 0; x < 8; ++x){
            if((x + y) % 2 == 0) {
                TileManagerPtr->Add(std::to_string(y) + "-" + std::to_string(x),
                                    new Entity(std::to_string(y) + "-" + std::to_string(x),BlackTileSprite)
                );
            }else{
                TileManagerPtr->Add(std::to_string(y) + "-" + std::to_string(x),
                                    new Entity(std::to_string(y) + "-" + std::to_string(x),WhiteTileSprite)
                );
                Position.x = x * ChessTileSize.x;
                Position.y = y * ChessTileSize.y;
                TileManagerPtr->Get(std::to_string(y) + "-" + std::to_string(x))->GetSprite()->setPosition(Position);
            }
        }
    }
}
*/