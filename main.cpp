#include "Headers/Includes.h"

TextureManager *GlobalTextureManager = new TextureManager();

int main() {
    LoadChessTileTexturesToTextureManager(GlobalTextureManager);
    LoadChessPeacesTexturesToTextureManager(GlobalTextureManager);
    TileMap *tileMap = new TileMap(ChessBoardSize,ChessTileSize);
    CreateChessBoard(tileMap,GlobalTextureManager);
    PeaceMap *peaceMap = new PeaceMap(ChessBoardSize);
    CreateChessPeaces(peaceMap,GlobalTextureManager);
    ChessBoard *chessBoard = new ChessBoard("White",tileMap,peaceMap,ChessBoardSize);
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
