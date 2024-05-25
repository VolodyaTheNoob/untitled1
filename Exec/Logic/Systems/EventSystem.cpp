//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"
bool IsMouseOnSprite(GameWindow* Wnd,sf::Sprite *Sprite);
ChessPeace* GetClickedPeace(GameWindow* Wnd);
//Main function
void EventSystem(GameWindow* Wnd){
    sf::Event event;
    while(Wnd->GetWindowPtr()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Wnd->GetWindowPtr()->close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            ChessPeace* ClickedPeace = GetClickedPeace(Wnd);
            std::cout << ClickedPeace->GetName() << "\n";
        }
    }
}

ChessPeace* GetClickedPeace(GameWindow* Wnd){
    PeaceMap* PeaceMapPtr = Wnd->GetBoardPtr()->GetPeaceMapPtr();
    ChessPeace* ClickedPeace = nullptr;
    for(unsigned int y = 0; y < Wnd->GetBoardPtr()->GetSize().y && ClickedPeace == nullptr;y++){
        for(unsigned int x = 0; x < Wnd->GetBoardPtr()->GetSize().x && ClickedPeace == nullptr;x++){
            if((*PeaceMapPtr->GetMapPtr())[y][x] != nullptr) {
                if (IsMouseOnSprite(Wnd, (*PeaceMapPtr->GetMapPtr())[y][x]->GetSprite())) {
                    ClickedPeace = (*PeaceMapPtr->GetMapPtr())[y][x];
                }
            }
        }
    }
    return ClickedPeace;
}

bool IsMouseOnSprite(GameWindow* Wnd,sf::Sprite *Sprite){
    Wnd->GetBoardPtr()->GetPeaceMapPtr()->GetMapPtr();
    sf::Vector2f MousePos = Wnd->GetWindowPtr()->mapPixelToCoords(sf::Mouse::getPosition(*Wnd->GetWindowPtr()));

    // retrieve the bounding box of the sprite
    sf::FloatRect SpriteBounds = Sprite->getGlobalBounds();

    // hit test
    if (SpriteBounds.contains(MousePos))
    {
        return true;
    }
    return false;
}