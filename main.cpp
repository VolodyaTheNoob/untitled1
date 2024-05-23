#include "Headers/Includes.h"

int main() {
    //Creating our game Window
    Window *GameWindow = new Window();
    //Creating VirtualChessMap
    CreateVirtualChessMap(*GameWindow->GetChessMapPtr());
    //Loading Tiles Textures
    LoadChessTileTexturesToWindow(GameWindow);
    //Loading Peaces Textures
    LoadChessPeacesTexturesToWindow(GameWindow);
    //Creating ChessBoard(just drawing sprites lol)
    CreateChessBoard(GameWindow);
    //LoadingChessPeaces
    CreateChessPeaces(GameWindow, *GameWindow->GetChessMapPtr(), ChessBoardSize.x,ChessBoardSize.y);
    //Binding RenderSystem
    GameWindow->SetRenderSystem(RenderSystem);
    //Binding EventSystem
    GameWindow->SetEventSystem(EventSystem);

    while(GameWindow->GetWindowPtr()->isOpen()){
        GameWindow->CallEventSystem();
        GameWindow->CallRenderSystem();
    }

    return 0;
}
