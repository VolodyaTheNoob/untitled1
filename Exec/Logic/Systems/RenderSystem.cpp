//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/RenderSystem.h"

void DrawTileMap(GameWindow* Wnd);
void DrawChessPeaces(GameWindow* Wnd);

void RenderSystem(GameWindow* Wnd){
    Wnd->GetWindowPtr()->clear();
    DrawTileMap(Wnd);
    DrawChessPeaces(Wnd);
    Wnd->GetWindowPtr()->display();
}

void DrawTileMap(GameWindow* Wnd){
    TileMap* TileMapPtr = Wnd->GetBoardPtr()->GetTileMapPtr();
    for(uint32_t y = 0;y < Wnd->GetBoardPtr()->GetSize().y;y++){
        for(uint32_t x = 0;x < Wnd->GetBoardPtr()->GetSize().x;x++){
            Wnd->GetWindowPtr()->draw(*(*TileMapPtr->GetMapPtr())[y][x]->GetSprite());
        }
    }
}

void DrawChessPeaces(GameWindow* Wnd){
    PeaceMap* PeaceMapPtr = Wnd->GetBoardPtr()->GetPeaceMapPtr();
    for(uint32_t y = 0;y < Wnd->GetBoardPtr()->GetSize().y;y++){
        for(uint32_t x = 0;x < Wnd->GetBoardPtr()->GetSize().x;x++){
            if((*PeaceMapPtr->GetMapPtr())[y][x] != nullptr) {
                Wnd->GetWindowPtr()->draw(*(*PeaceMapPtr->GetMapPtr())[y][x]->GetSprite());
            }
        }
    }
}