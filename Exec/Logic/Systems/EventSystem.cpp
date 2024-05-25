//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"

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


        }
    }
}
