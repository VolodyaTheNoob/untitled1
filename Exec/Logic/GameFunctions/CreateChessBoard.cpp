//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"

void CreateChessBoard(TileMap* TileMapPtr, TextureManager *TextureManager){
    sf::Sprite *WhiteTileSprite = new sf::Sprite;
    WhiteTileSprite->setTexture(*TextureManager->Get("WhiteTile"));
    sf::Sprite *BlackTileSprite = new sf::Sprite;
    BlackTileSprite->setTexture(*TextureManager->Get("BlackTile"));
    Tile* BlackTile = new Tile("BlackTile",BlackTileSprite);
    Tile* WhiteTile = new Tile("WhiteTile",WhiteTileSprite);
    sf::Vector2f Position;
    for(uint32_t y = 0; y < TileMapPtr->GetSize().y;y++) {
        for (uint32_t x = 0; x < TileMapPtr->GetSize().x; x++) {
            if((x+y) % 2 == 0){
                TileMapPtr->AddTile(BlackTile);
            }else{
                TileMapPtr->AddTile(WhiteTile);
            }
        }
    }
}
