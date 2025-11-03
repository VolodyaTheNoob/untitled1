//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_WINDOW_H
#define UNTITLED1_WINDOW_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Constants.h"
#include "Headers/Managers/TextureManager.h"
/*
 * Abstract class used to build own Window classes, can be used as game class
 */
class GameWindow;
class Window;
class TextureManager;

class Window {
    friend class GameWindow;
private:
    sf::RenderWindow *Wnd;
    void (*RenderSystem)(Window* Wnd);
    void (*EventSystem)(Window* Wnd);
public:
    virtual void SetRenderSystem(void (*NewRenderSystem)(Window* Wnd));
    virtual void CallRenderSystem();
    virtual void SetEventSystem(void (*NewEventSystem)(Window* Wnd));
    virtual void CallEventSystem();
    sf::RenderWindow* GetWindowPtr();
    void SetWindowPtr(sf::RenderWindow* NewWindowPtr);
};


#endif //UNTITLED1_WINDOW_H
