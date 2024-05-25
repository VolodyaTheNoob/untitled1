//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_GAMEWINDOW_H
#define UNTITLED1_GAMEWINDOW_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Abstracts/Window.h"

//Game class based on abstract Window class

class GameWindow : public Window{
private:
    ChessBoard* Board = nullptr;
    void (*RenderSystem)(GameWindow* Wnd);
    void (*EventSystem)(GameWindow* Wnd);
public:
    GameWindow();
    GameWindow(ChessBoard *Board);
    ~GameWindow();
    void SetRenderSystem(void (*NewRenderSystem)(GameWindow* Wnd));
    void SetEventSystem(void (*NewEventSystem)(GameWindow* Wnd));
    void CallRenderSystem() override;
    void CallEventSystem() override;
};


#endif //UNTITLED1_GAMEWINDOW_H
