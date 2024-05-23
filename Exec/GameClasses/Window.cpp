//
// Created by SystemX on 23.05.2024.
//

#include "Headers/GameClasses/Window.h"


//Constructors
Window::Window(){
    this->Tiles = new EntityManager<Entity>();
    this->Objects = new EntityManager<Entity>();
    this->Wnd = new sf::RenderWindow(sf::VideoMode(800,600,32),"A");
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
EntityManager<Entity>* Window::GetTileManager(){
    return this->Tiles;
}
EntityManager<Entity>* Window::GetObjectManager(){
    return this->Objects;
}

