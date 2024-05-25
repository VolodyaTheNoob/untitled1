//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/RenderSystem.h"

void RenderSystem(GameWindow* Wnd){
    Wnd->GetWindowPtr()->clear();

    Wnd->GetWindowPtr()->display();
}