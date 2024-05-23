//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"

ChessPeace* GetClickedObject(Window* Wnd);
void EntityDragAndDrop(Window* Wnd, Entity* ToTrack, sf::Vector2f* TrackedPos);
//Main function
void EventSystem(Window* Wnd){
    sf::Event event;
    ChessPeace *ClickedEntity;
    sf::Vector2f PrevPosition;
    sf::Vector2f *TrackingPosition = new sf::Vector2f(0,0);
    while(Wnd->GetWindowPtr()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Wnd->GetWindowPtr()->close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            ClickedEntity = GetClickedObject(Wnd);
            if(ClickedEntity != nullptr) {
                PrevPosition = ClickedEntity->GetSprite()->getPosition();
                EntityDragAndDrop(Wnd, ClickedEntity, TrackingPosition);
                std::cout << ClickedEntity->GetBoardCoordinates().x;
            }
        }
    }
}

ChessPeace* GetClickedObject(Window* Wnd){
    auto mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr()); // Mouse position relative to the window
    auto translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    Wnd->GetObjectManagerPtr()->GetStorage();
    for(auto& Object : Wnd->GetObjectManagerPtr()->GetStorage())
    {
        if(Object.second->GetSprite()->getGlobalBounds().contains(translated_pos)){
            return Object.second;
        }
    }
    return nullptr;
}

void EntityDragAndDrop(Window* Wnd, Entity* ToTrack, sf::Vector2f* TrackedPos){
    auto mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
    auto translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
        translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
        TrackedPos->x = ToTrack->GetSprite()->getPosition().x;
        TrackedPos->x = ToTrack->GetSprite()->getPosition().y;
        ToTrack->GetSprite()->setPosition(translated_pos.x,translated_pos.y);
        Wnd->CallRenderSystem();
    }
}
