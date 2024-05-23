#include "Headers/Includes.h"

int main() {
    //Creating our game Window
    Window *GameWindow = new Window();
    /*
     * ChessMap id's
     * 0 - Empty
     * 1 - WhitePawn
     * 2 - BlackPawn
     * 3 - WhiteTower
     * 4 - BlackTower
     * 5 - WhiteBishop
     * 6 - BlackBishop
     * 7 - WhiteHorse
     * 8 - BlackHorse
     * 9 - WhiteQueen
     * 10 - BlackQueen
     * 11 - WhiteKing
     * 12 - BlackKing
     */
    //ChessMap(ty cap)
    uint32_t ChessMap[8][8] = {
            3,7,5,9,11,5,7,3,
            1,1,1,1,1,1,1,1,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            2,2,2,2,2,2,2,2,
            4,8,6,10,12,6,8,4,
    };

    //Loading Tiles Textures
    LoadChessTileTexturesToWindow(GameWindow);
    //Loading Peaces Textures
    LoadChessPeacesTexturesToWindow(GameWindow);
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
