//
// Created by SystemX on 25.05.2024.
//

#ifndef UNTITLED1_GAMEWINDOW_H
#define UNTITLED1_GAMEWINDOW_H

#include "Headers/Abstracts/Window.h"
#include "Headers/GameClasses/ChessBoard.h"

//Game class based on abstract Window class

class ChessBoard;
class Window;

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
    ChessBoard* GetBoardPtr();
};


#endif //UNTITLED1_GAMEWINDOW_H
