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
    void (*RenderSystem)(Window* Wnd);
    void (*EventSystem)(Window* Wnd);
    bool ViewFlipped = false;
public:
    bool CurrentPlayerMove = false;
    bool PlayerChecked[2] = {false, false};
    bool IsPLayerCheckmated = false;
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
    void SetChessMap(std::vector<std::vector<uint32_t>> NewChessMap);
    bool GetCurrentPlayerMove();
    void NextMove();
};


#endif //UNTITLED1_WINDOW_H
