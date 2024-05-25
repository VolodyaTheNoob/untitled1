//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/GameFunctions/GameFunctions.h"

//C:/Users/SystemX/CLionProjects/untitled1/Sprites
/*
void LoadPawns(Window* WindowPtr);
void LoadWhitePawn(Window* WindowPtr);void LoadBlackPawn(Window* WindowPtr);

void LoadRooks(Window* WindowPtr);
void LoadWhiteRook(Window* WindowPtr);void LoadBlackRook(Window* WindowPtr);

void LoadBishops(Window* WindowPtr);
void LoadWhiteBishop(Window* WindowPtr);void LoadBlackBishop(Window* WindowPtr);

void LoadKnights(Window* WindowPtr);
void LoadWhiteKnight(Window* WindowPtr);void LoadBlackKnight(Window* WindowPtr);

void LoadQueens(Window* WindowPtr);
void LoadWhiteQueen(Window* WindowPtr);void LoadBlackQueen(Window* WindowPtr);

void LoadKings(Window* WindowPtr);
void LoadWhiteKing(Window* WindowPtr);void LoadBlackKing(Window* WindowPtr);
/*
 *   |
 *   |   MAIN FUNCTION
 *  \ /
 */
/*
void LoadChessPeacesTexturesToWindow(Window* WindowPtr){
    LoadPawns(WindowPtr);
    LoadRooks(WindowPtr);
    LoadBishops(WindowPtr);
    LoadKnights(WindowPtr);
    LoadQueens(WindowPtr);
    LoadKings(WindowPtr);
    }
*/
/*
 * / \
 *  |   MAIN FUNCTION
 *  |
 */
//Loading Pawns
/*
void LoadPawns(Window* WindowPtr){
    LoadWhitePawn(WindowPtr);
    LoadBlackPawn(WindowPtr);
}
void LoadWhitePawn(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/pawn.png");
    TextureManagerPtr->Add("WhitePawn",WhitePawnTexture);
}
void LoadBlackPawn(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/pawn1.png");
    TextureManagerPtr->Add("BlackPawn",WhitePawnTexture);
}
//Loading Rooks
void LoadRooks(Window* WindowPtr){
    LoadWhiteRook(WindowPtr);
    LoadBlackRook(WindowPtr);
}
void LoadWhiteRook(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/rook.png");
    TextureManagerPtr->Add("WhiteRook",WhitePawnTexture);
}
void LoadBlackRook(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/rook1.png");
    TextureManagerPtr->Add("BlackRook",WhitePawnTexture);
}
//Loading Bishops
void LoadBishops(Window* WindowPtr){
    LoadWhiteBishop(WindowPtr);
    LoadBlackBishop(WindowPtr);
}
void LoadWhiteBishop(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/bishop.png");
    TextureManagerPtr->Add("WhiteBishop",WhitePawnTexture);
}
void LoadBlackBishop(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/bishop1.png");
    TextureManagerPtr->Add("BlackBishop",WhitePawnTexture);
}
//Loading Knights
void LoadKnights(Window* WindowPtr){
    LoadWhiteKnight(WindowPtr);
    LoadBlackKnight(WindowPtr);
}
void LoadWhiteKnight(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/knight.png");
    TextureManagerPtr->Add("WhiteKnight",WhitePawnTexture);
}
void LoadBlackKnight(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/knight1.png");
    TextureManagerPtr->Add("BlackKnight",WhitePawnTexture);
}
//Loading Queens
void LoadQueens(Window* WindowPtr){
    LoadWhiteQueen(WindowPtr);
    LoadBlackQueen(WindowPtr);
}
void LoadWhiteQueen(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/queen.png");
    TextureManagerPtr->Add("WhiteQueen",WhitePawnTexture);
}
void LoadBlackQueen(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/queen1.png");
    TextureManagerPtr->Add("BlackQueen",WhitePawnTexture);
}
//Loading Kings
void LoadKings(Window* WindowPtr){
    LoadWhiteKing(WindowPtr);
    LoadBlackKing(WindowPtr);
}
void LoadWhiteKing(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/king.png");
    TextureManagerPtr->Add("WhiteKing",WhitePawnTexture);
}
void LoadBlackKing(Window* WindowPtr){
    TextureManager* TextureManagerPtr = WindowPtr->GetTextureManagerPtr();
    sf::Texture *WhitePawnTexture = new sf::Texture();
    WhitePawnTexture->loadFromFile("C:/Users/SystemX/CLionProjects/untitled1/Sprites/king1.png");
    TextureManagerPtr->Add("BlackKing",WhitePawnTexture);
}
*/