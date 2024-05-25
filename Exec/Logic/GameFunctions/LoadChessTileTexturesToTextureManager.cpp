//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"

sf::Texture* CreateWhiteTile();
sf::Texture* CreateBlackTile();

void LoadChessTileTexturesToTextureManager(TextureManager* TextureManagerPtr){
    sf::Texture* WhiteTileTexture = CreateWhiteTile();
    sf::Texture* BlackTileTexture = CreateBlackTile();
    TextureManagerPtr->Add("WhiteTile",WhiteTileTexture);
    TextureManagerPtr->Add("BlackTile",BlackTileTexture);
}

sf::Texture* CreateWhiteTile(){
    sf::Image ImageTemp;
    ImageTemp.create(ChessTileSize.x,ChessTileSize.y,sf::Color::White);
    sf::Texture *TextureTemp = new sf::Texture;
    TextureTemp->loadFromImage(ImageTemp);
    return TextureTemp;
}
sf::Texture* CreateBlackTile(){
    sf::Image ImageTemp;
    ImageTemp.create(ChessTileSize.x,ChessTileSize.y,sf::Color::Black);
    sf::Texture *TextureTemp = new sf::Texture;
    TextureTemp->loadFromImage(ImageTemp);
    return TextureTemp;
}

