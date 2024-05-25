//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"
bool IsMouseOnSprite(GameWindow* Wnd,sf::Sprite *Sprite);
ChessPeace* GetClickedPeace(GameWindow* Wnd);
void PeaceDragAndDrop(GameWindow* Wnd,ChessPeace* PeaceToMove);
bool IsPeacePositionChanged(sf::Vector2u CurrentTilePosition,sf::Vector2f CurrentPosition, sf::Vector2u TileSize);
//Main function
void EventSystem(GameWindow* Wnd){
    sf::Event event;
    while(Wnd->GetWindowPtr()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Wnd->GetWindowPtr()->close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            ChessPeace* ClickedPeace = GetClickedPeace(Wnd);
            sf::Vector2f PrevCoordinates = ClickedPeace->GetPeaceCoordinates();
            PeaceDragAndDrop(Wnd,ClickedPeace);
            sf::Vector2u TileSize = Wnd->GetBoardPtr()->GetTileMapPtr()->GetTileSize();
            bool IsPosChanged = IsPeacePositionChanged(ClickedPeace->GetBoardCoordinates(),ClickedPeace->GetPeaceCoordinates(),TileSize);
            if(IsPosChanged) {
                sf::Vector2f CurrentSpritePosition = ClickedPeace->GetPeaceCoordinates();
                sf::Vector2u NewTilePosition;CurrentSpritePosition.x += 20;CurrentSpritePosition.y += 40;
                NewTilePosition.x = uint32_t(CurrentSpritePosition.x) / TileSize.x;NewTilePosition.y = uint32_t(CurrentSpritePosition.y) / TileSize.y;
                if(!Wnd->GetBoardPtr()->IsPlayerMoveCorrect(ClickedPeace,NewTilePosition)){
                    ClickedPeace->SetPeaceCoordinates(PrevCoordinates);
                }
            }
        }
    }
}

void PeaceDragAndDrop(GameWindow* Wnd,ChessPeace* PeaceToMove){
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2f MousePos = Wnd->GetWindowPtr()->mapPixelToCoords(sf::Mouse::getPosition(*Wnd->GetWindowPtr()));
        MousePos.x -= 20;
        MousePos.y -= 20;
        PeaceToMove->SetPeaceCoordinates(MousePos);
        Wnd->CallRenderSystem();
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
    sf::FloatRect SpriteBounds = Sprite->getGlobalBounds();
    if (SpriteBounds.contains(MousePos))
    {
        return true;
    }
    return false;
}
bool IsPeacePositionChanged(sf::Vector2u CurrentTilePosition,sf::Vector2f CurrentPosition, sf::Vector2u TileSize){
    sf::Vector2u NewTilePosition;
    CurrentPosition.x += 20;
    CurrentPosition.y += 40;
    NewTilePosition.x = uint32_t(CurrentPosition.x) / TileSize.x;
    NewTilePosition.y = uint32_t(CurrentPosition.y) / TileSize.y;
    if(CurrentTilePosition != NewTilePosition){
        return true;
    }
    return false;
}