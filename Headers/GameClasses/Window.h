//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_WINDOW_H
#define UNTITLED1_WINDOW_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Constants.h"
#include "Headers/Managers/EntityManager.h"
#include "Headers/Managers/TextureManager.h"

class Window {
private:
    sf::RenderWindow *Wnd;
    TextureManager *TextureStorage;
    EntityManager<Entity> *Tiles;
    EntityManager<ChessPeace> *Objects;
    std::vector<std::vector<uint32_t>>*ChessMap;//(8,std::vector<uint32_t>(8))
    bool ViewFlipped = false;
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
    EntityManager<Entity>* GetTileManagerPtr();
    EntityManager<ChessPeace>* GetObjectManagerPtr();
    TextureManager* GetTextureManagerPtr();
    bool IsViewFlipped();
    std::vector<std::vector<uint32_t>>* GetChessMapPtr();
};


#endif //UNTITLED1_WINDOW_H
