//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"

void EventSystem(Window* Wnd){
    sf::Event event;
    while(Wnd->GetWindowPtr()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Wnd->GetWindowPtr()->close();
        }
    }
}
