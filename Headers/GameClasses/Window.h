//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_WINDOW_H
#define UNTITLED1_WINDOW_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Managers/EntityManager.h"

class Window {
private:
    sf::RenderWindow *Wnd;
    EntityManager<Entity> *Tiles;
    EntityManager<Entity> *Objects;
    void (*RenderSystem)(Window* Wnd);
    void (*EventSystem)(Window* Wnd);
public:
    Window();
    ~Window();
    void SetRenderSystem(void (*NewRenderSystem)(Window* Wnd));
    void CallRenderSystem();
    void SetEventSystem(void (*NewEventSystem)(Window* Wnd));
    void CallEventSystem();
    sf::RenderWindow* GetWindowPtr();
    EntityManager<Entity>* GetTileManager();
    EntityManager<Entity>* GetObjectManager();
};


#endif //UNTITLED1_WINDOW_H
