//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/GameWindow.h"

GameWindow::GameWindow(){
    this->EventSystem = nullptr;
    this->RenderSystem = nullptr;
    this->Board = nullptr;
    this->Wnd = new sf::RenderWindow(sf::VideoMode(512,512,32),"A");
}
GameWindow::GameWindow(ChessBoard *Board){
    this->EventSystem = nullptr;
    this->RenderSystem = nullptr;
    this->Board = Board;
    this->Wnd = new sf::RenderWindow(sf::VideoMode(512,512,32),"A");
}
GameWindow::~GameWindow() = default;

void GameWindow::SetRenderSystem(void (*NewRenderSystem)(GameWindow* Wnd)){
    this->RenderSystem = NewRenderSystem;
}
void GameWindow::SetEventSystem(void (*NewEventSystem)(GameWindow* Wnd)){
    this->EventSystem = NewEventSystem;
}
void GameWindow::CallRenderSystem(){
    if(this->RenderSystem != nullptr) {
        this->RenderSystem(this);
    }
}
void GameWindow::CallEventSystem(){
    if(this->EventSystem != nullptr) {
        this->EventSystem(this);
    }
}