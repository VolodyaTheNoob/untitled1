#include "Headers/Includes.h"

int main() {
    //Creating our game Window
    Window *GameWindow = new Window();
    //Loading Tiles
    LoadChessTileTexturesToWindow(GameWindow);
    //Creating ChessBoard(just drawing sprites lol)
    CreateChessBoard(GameWindow);
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
