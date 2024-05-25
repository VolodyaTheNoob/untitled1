//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"

//C:/Users/SystemX/CLionProjects/untitled1/Sprites

void LoadPawns(TextureManager* TextureManagerPtr);
void LoadWhitePawn(TextureManager* TextureManagerPtr);void LoadBlackPawn(TextureManager* TextureManagerPtr);

void LoadRooks(TextureManager* TextureManagerPtr);
void LoadWhiteRook(TextureManager* TextureManagerPtr);void LoadBlackRook(TextureManager* TextureManagerPtr);

void LoadBishops(TextureManager* TextureManagerPtr);
void LoadWhiteBishop(TextureManager* TextureManagerPtr);void LoadBlackBishop(TextureManager* TextureManagerPtr);

void LoadKnights(TextureManager* TextureManagerPtr);
void LoadWhiteKnight(TextureManager* TextureManagerPtr);void LoadBlackKnight(TextureManager* TextureManagerPtr);

void LoadQueens(TextureManager* TextureManagerPtr);
void LoadWhiteQueen(TextureManager* TextureManagerPtr);void LoadBlackQueen(TextureManager* TextureManagerPtr);

void LoadKings(TextureManager* TextureManagerPtr);
void LoadWhiteKing(TextureManager* TextureManagerPtr);void LoadBlackKing(TextureManager* TextureManagerPtr);
/*
 *   |
 *   |   MAIN FUNCTION
 *  \ /
 */

void LoadChessPeacesTexturesToTextureManager(TextureManager* TextureManagerPtr){
    LoadPawns(TextureManagerPtr);
    LoadRooks(TextureManagerPtr);
    LoadBishops(TextureManagerPtr);
    LoadKnights(TextureManagerPtr);
    LoadQueens(TextureManagerPtr);
    LoadKings(TextureManagerPtr);
    }

/*
 * / \
 *  |   MAIN FUNCTION
 *  |
 */
//Loading Pawns
void LoadPawns(TextureManager* TextureManagerPtr){
    LoadWhitePawn(TextureManagerPtr);
    LoadBlackPawn(TextureManagerPtr);
}
void LoadWhitePawn(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/pawn.png");
    TextureManagerPtr->Add("WhitePawn",WhitePawnTexture);
}
void LoadBlackPawn(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/pawn1.png");
    TextureManagerPtr->Add("BlackPawn",WhitePawnTexture);
}
//Loading Rooks
void LoadRooks(TextureManager* TextureManagerPtr){
    LoadWhiteRook(TextureManagerPtr);
    LoadBlackRook(TextureManagerPtr);
}
void LoadWhiteRook(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/rook.png");
    TextureManagerPtr->Add("WhiteRook",WhitePawnTexture);
}
void LoadBlackRook(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/rook1.png");
    TextureManagerPtr->Add("BlackRook",WhitePawnTexture);
}
//Loading Bishops
void LoadBishops(TextureManager* TextureManagerPtr){
    LoadWhiteBishop(TextureManagerPtr);
    LoadBlackBishop(TextureManagerPtr);
}
void LoadWhiteBishop(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/bishop.png");
    TextureManagerPtr->Add("WhiteBishop",WhitePawnTexture);
}
void LoadBlackBishop(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/bishop1.png");
    TextureManagerPtr->Add("BlackBishop",WhitePawnTexture);
}
//Loading Knights
void LoadKnights(TextureManager* TextureManagerPtr){
    LoadWhiteKnight(TextureManagerPtr);
    LoadBlackKnight(TextureManagerPtr);
}
void LoadWhiteKnight(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/knight.png");
    TextureManagerPtr->Add("WhiteKnight",WhitePawnTexture);
}
void LoadBlackKnight(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/knight1.png");
    TextureManagerPtr->Add("BlackKnight",WhitePawnTexture);
}
//Loading Queens
void LoadQueens(TextureManager* TextureManagerPtr){
    LoadWhiteQueen(TextureManagerPtr);
    LoadBlackQueen(TextureManagerPtr);
}
void LoadWhiteQueen(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/queen.png");
    TextureManagerPtr->Add("WhiteQueen",WhitePawnTexture);
}
void LoadBlackQueen(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/queen1.png");
    TextureManagerPtr->Add("BlackQueen",WhitePawnTexture);
}
//Loading Kings
void LoadKings(TextureManager* TextureManagerPtr){
    LoadWhiteKing(TextureManagerPtr);
    LoadBlackKing(TextureManagerPtr);
}
void LoadWhiteKing(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/king.png");
    TextureManagerPtr->Add("WhiteKing",WhitePawnTexture);
}
void LoadBlackKing(TextureManager* TextureManagerPtr){
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/king1.png");
    TextureManagerPtr->Add("BlackKing",WhitePawnTexture);
}
