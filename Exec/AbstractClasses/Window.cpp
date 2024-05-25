//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Abstracts/Window.h"
//Functions
void Window::SetRenderSystem(void (*NewRenderSystem)(Window* Wnd)){
    this->RenderSystem = NewRenderSystem;
}
void Window::CallRenderSystem(){
    if(this->RenderSystem != nullptr) {
        this->RenderSystem(this);
    }
}
void Window::SetEventSystem(void (*NewEventSystem)(Window* Wnd)){
    this->EventSystem = NewEventSystem;
}
void Window::CallEventSystem(){
    if(this->EventSystem != nullptr) {
        this->EventSystem(this);
    }
}
sf::RenderWindow* Window::GetWindowPtr(){
    return this->Wnd;
}
void Window::SetWindowPtr(sf::RenderWindow* NewWindowPtr){
    this->Wnd = NewWindowPtr;
}

