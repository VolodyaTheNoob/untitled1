#include "Headers/Includes.h"

void EventSystem(Window* Wnd){
    sf::Event event;
    while(Wnd->GetWindowPtr()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Wnd->GetWindowPtr()->close();
        }
    }
}

void RenderSystem(Window* Wnd){
    sf::RenderWindow* WindowPointer = Wnd->GetWindowPtr();
    WindowPointer->clear();
    //<->
    for(auto& Tile : Wnd->GetTileManager()->GetStorage())
    {
        WindowPointer->draw(*Tile.second->GetSprite());
    }
    for(auto& Object : Wnd->GetObjectManager()->GetStorage())
    {
        WindowPointer->draw(*Object.second->GetSprite());
    }
    //<->
    WindowPointer->display();
}

int main() {
    sf::Image *I1 = new sf::Image();
    I1->create(64,64,sf::Color::White);
    sf::Texture *T1 = new sf::Texture();
    T1->loadFromImage(*I1);
    sf::Sprite *S1 = new sf::Sprite();
    S1->setTexture(*T1);
    Entity *E1 = new Entity();
    E1->SetSprite(S1);
    Window *GameWindow = new Window();
    GameWindow->GetTileManager()->Add("WhiteBox",E1);
    GameWindow->SetRenderSystem(RenderSystem);
    GameWindow->SetEventSystem(EventSystem);
    while(GameWindow->GetWindowPtr()->isOpen()){
        GameWindow->CallEventSystem();
        GameWindow->CallRenderSystem();
    }

    return 0;
}
