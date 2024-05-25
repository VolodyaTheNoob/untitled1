#include "Headers/Includes.h"

TextureManager *GlobalTextureManager = new TextureManager();

int main() {
    Pawn WP1("Pawn",new sf::Sprite,sf::Vector2u(4,4),ChessBoardSize,"White");
    LoadChessTileTexturesToTextureManager(GlobalTextureManager);
    LoadChessPeacesTexturesToTextureManager(GlobalTextureManager);
    TileMap *tileMap = new TileMap(ChessBoardSize,ChessTileSize);
    CreateChessBoard(tileMap,GlobalTextureManager);
    PeaceMap *peaceMap = new PeaceMap(ChessBoardSize);
    CreateChessPeaces(peaceMap,GlobalTextureManager);
    //peaceMap->AddPeace(WP1,sf::Vector2u(4,4));
    ChessBoard *chessBoard = new ChessBoard(0,"White",tileMap,peaceMap,ChessBoardSize);
    //Creating our game Window
    GameWindow *gameWindow = new GameWindow(chessBoard);
    gameWindow->SetRenderSystem(RenderSystem);
    gameWindow->SetEventSystem(EventSystem);
    while(gameWindow->GetWindowPtr()->isOpen()){
        gameWindow->CallEventSystem();
        gameWindow->CallRenderSystem();
    }

    return 0;
}
