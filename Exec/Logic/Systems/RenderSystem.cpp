//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/RenderSystem.h"

void RenderSystem(Window* Wnd){
    sf::RenderWindow* WindowPointer = Wnd->GetWindowPtr();
    WindowPointer->clear();
    //<->
    for(auto& Tile : Wnd->GetTileManagerPtr()->GetStorage())
    {
        WindowPointer->draw(*Tile.second->GetSprite());
    }
    for(auto& Object : Wnd->GetObjectManagerPtr()->GetStorage())
    {
        WindowPointer->draw(*Object.second->GetSprite());
    }
    //<->
    WindowPointer->display();
}