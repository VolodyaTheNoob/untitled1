#include "Headers/Includes.h"

TextureManager *GlobalTextureManager;

int main() {
    TileMap *tileMap = new TileMap(ChessBoardSize);
    PeaceMap *peaceMap = new PeaceMap(ChessBoardSize);
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
