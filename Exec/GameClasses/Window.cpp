//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/Window.h"
//Constructors
Window::Window(){
    this->TextureStorage = new TextureManager();
    this->Tiles = new EntityManager<Entity>();
    this->Objects = new EntityManager<ChessPeace>();
    this->Wnd = new sf::RenderWindow(sf::VideoMode(WindowSize.x,WindowSize.y,32),WindowTile);
}
//Destructors
Window::~Window() = default;
//Public functions
void Window::SetRenderSystem(void (*NewRenderSystem)(Window* Wnd)){
    this->RenderSystem = NewRenderSystem;
}
void Window::CallRenderSystem(){
    this->RenderSystem(this);
}
void Window::SetEventSystem(void (*NewEventSystem)(Window* Wnd)){
    this->EventSystem = NewEventSystem;
}
void Window::CallEventSystem(){
    this->EventSystem(this);
}
sf::RenderWindow* Window::GetWindowPtr(){
    return this->Wnd;
}
EntityManager<Entity>* Window::GetTileManagerPtr(){
    return this->Tiles;
}
EntityManager<ChessPeace>* Window::GetObjectManagerPtr(){
    return this->Objects;
}
TextureManager* Window::GetTextureManagerPtr(){
    return this->TextureStorage;
}

