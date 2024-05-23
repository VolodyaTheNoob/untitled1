//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"

ChessPeace* GetClickedObject(Window* Wnd);
void EntityDragAndDrop(Window* Wnd, ChessPeace* ToTrack, sf::Vector2f* TrackedPos);
std::string GetEntityType(ChessPeace *Entity);
void MoveEntity(Window* Wnd, ChessPeace* Entity, sf::Vector2f PrevPos, std::string EntityType);
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
                MoveEntity(Wnd,ClickedEntity,PrevPosition,GetEntityType(ClickedEntity));
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

void EntityDragAndDrop(Window* Wnd, ChessPeace* ToTrack, sf::Vector2f* TrackedPos){
    auto mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
    auto translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
        translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
        translated_pos.x = translated_pos.x - 21;
        translated_pos.y = translated_pos.y - 21;
        TrackedPos->x = ToTrack->GetSprite()->getPosition().x;
        TrackedPos->x = ToTrack->GetSprite()->getPosition().y;
        ToTrack->GetSprite()->setPosition(translated_pos.x,translated_pos.y);
        Wnd->CallRenderSystem();
    }
}
std::string GetEntityType(ChessPeace *Entity){
    std::string EntityFullName = Entity->GetName();
    std::string Temp = "";
    unsigned int i = 0;
    while(EntityFullName[i] != ' '){
        Temp += EntityFullName[i];
        i++;
    }
    return Temp;
}

void MoveEntity(Window* Wnd, ChessPeace* Entity, sf::Vector2f PrevPos, std::string EntityType){
    auto mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
    auto translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
    translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    sf::Vector2u PrevBoardCoordinates = Entity->GetBoardCoordinates();
    sf::Vector2u NewBoardCoordinates;
    NewBoardCoordinates.x = int(translated_pos.x) / 64;
    NewBoardCoordinates.y = int(translated_pos.y + 16) / 64;
    std::cout << "<->" << "\n";
    for(unsigned int y = 0; y < 8; y++){
        for(unsigned int x = 0; x < 8; x++){
            std::cout << (*Wnd->GetChessMapPtr())[y][x] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "<->" << "\n";
    if((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] == 0){
        if(EntityType == "WhitePawn" ||EntityType == "BlackPawn" ){

        }
        if(EntityType == "WhiteRook" ||EntityType == "BlackRook" ){

        }
        if(EntityType == "WhiteKnight" ||EntityType == "BlackKnight" ){

        }
        if(EntityType == "WhiteBishop" ||EntityType == "BlackBishop" ){

        }
        if(EntityType == "WhiteQueen" ||EntityType == "BlackQueen" ){

        }
        if(EntityType == "WhiteKing" ||EntityType == "BlackKing" ){

        }
    }else{
        Entity->SetPeaceCoordinates(PrevPos);
    }
}