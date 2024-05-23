#include "Headers/Includes.h"

int main() {

    sf::RenderWindow Window(sf::VideoMode(800,600,32),"a");
    while(Window.isOpen()){
        sf::Event event;
        while(Window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                Window.close();
            }
        }
        Window.clear();

        Window.display();
    }

    return 0;
}
