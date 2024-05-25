#include "Headers/Includes.h"




int main() {
    //Creating our game Window
    Window *GameWindow = new Window();

    while(GameWindow->GetWindowPtr()->isOpen()){
        GameWindow->CallEventSystem();
        GameWindow->CallRenderSystem();
    }

    return 0;
}
