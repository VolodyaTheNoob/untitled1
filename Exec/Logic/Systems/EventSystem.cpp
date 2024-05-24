//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"

bool IsPawnMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool ChecStraightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool CheckCrossMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsKnightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool CheckOneCordMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsQueenMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsAlliePeaceThere(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);

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
    std::cout << Entity->GetBoardCoordinates().y << " " << Entity->GetBoardCoordinates().x << "\n";
    std::cout << NewBoardCoordinates.y << " " << NewBoardCoordinates.x << "\n";
    std::cout << "<->" << "\n";
        if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 2 || (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 1){
            bool IsMoveCorrect = IsPawnMoveCorrect(Wnd, Entity, NewBoardCoordinates);
            std::cout << IsMoveCorrect << "\n";
        }
        if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 4 || (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 3){
            bool IsMoveCorrect = ChecStraightMoveCorrect(Wnd, Entity, NewBoardCoordinates);
            std::cout << IsMoveCorrect << "\n";

        }
        if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 6 || (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 5){
            bool IsMoveCorrect = CheckCrossMoveCorrect(Wnd, Entity, NewBoardCoordinates);
            std::cout << IsMoveCorrect << "\n";
        }
        if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 8 || (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 7){
            bool IsMoveCorrect = IsKnightMoveCorrect(Wnd, Entity, NewBoardCoordinates);
            std::cout << IsMoveCorrect << "\n";
        }
        if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 10 || (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 9){
            bool IsMoveCorrect = IsQueenMoveCorrect(Wnd, Entity, NewBoardCoordinates);
            std::cout << IsMoveCorrect << "\n";
        }
        if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 12){
            bool IsMoveCorrect = CheckOneCordMoveCorrect(Wnd, Entity, NewBoardCoordinates);
            std::cout << IsMoveCorrect << "\n";
        }

}

bool IsPawnMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates) {
    int ChangeMoveVec = 1;
    if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 1) {
        ChangeMoveVec = -1;
    }
    int MoveVec; //0 - Top; 1 - Bottom
    if (Wnd->IsViewFlipped() == 0) {
        MoveVec = 1;
    } else {
        MoveVec = -1;
    }
    MoveVec *= ChangeMoveVec;
    if (Entity->GetBoardCoordinates().y - NewBoardCoordinates.y == MoveVec) {
        if (NewBoardCoordinates.x == Entity->GetBoardCoordinates().x) {
            if ((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0) {
                bool AlliePeaceThere = IsAlliePeaceThere(Wnd, Entity, NewBoardCoordinates);
                return !AlliePeaceThere;
            }
            return true;
        }
    }
    return false;
}

bool ChecStraightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates) {
    if((Entity->GetBoardCoordinates().y - NewBoardCoordinates.y == 0 || Entity->GetBoardCoordinates().x - NewBoardCoordinates.x == 0) && !(Entity->GetBoardCoordinates().y - NewBoardCoordinates.y == 0 && Entity->GetBoardCoordinates().x - NewBoardCoordinates.x == 0)){
        sf::Vector2i MoveVec(0,0);
        int MoveCount;
        if(Entity->GetBoardCoordinates().y - NewBoardCoordinates.y == 0){
            MoveCount = Entity->GetBoardCoordinates().x - NewBoardCoordinates.x;
            if(Entity->GetBoardCoordinates().x - NewBoardCoordinates.x > 0){
                MoveVec.x = 1;
            }else{
                MoveVec.x = -1;
            }
        }else{
            MoveCount = Entity->GetBoardCoordinates().y - NewBoardCoordinates.y;
            if(Entity->GetBoardCoordinates().y - NewBoardCoordinates.y > 0){
                MoveVec.y = 1;
            }else{
                MoveVec.y = -1;
            }
            if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 4 || (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 10){
                MoveVec.y *= -1;
            }
            if(Wnd->IsViewFlipped()){
                MoveVec.y *= -1;
            }
        }
        if(MoveCount < 0){
            MoveCount *= -1;
        }
        bool IsMoveCorrect = true;
        sf::Vector2i CheckPos;
        CheckPos.y = Entity->GetBoardCoordinates().y;
        CheckPos.x = Entity->GetBoardCoordinates().x;
        std::cout << CheckPos.y << " " << CheckPos.x << "\n";
        if(MoveCount > 1) {
            for (unsigned int Move = 0; Move < MoveCount - 1; Move++) {
                CheckPos.y += MoveVec.y;
                CheckPos.x += MoveVec.x;
                if ((*Wnd->GetChessMapPtr())[CheckPos.y][CheckPos.x] != 0) {
                    IsMoveCorrect = false;
                }
            }
        }
        if(IsMoveCorrect){
            if((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0){
                bool AlliePeaceThere = IsAlliePeaceThere(Wnd,Entity,NewBoardCoordinates);
                return !AlliePeaceThere;
            }
            return true;
        }
    }
    return false;
}

bool CheckCrossMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates){
    if((int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x) != 0) && (int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y))) {
        if (abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x)) ==
            abs(int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y))) {
            sf::Vector2i MoveVec(0, 0);
            if (int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x) > 0) {
                MoveVec.x = 1;
            } else {
                MoveVec.x = -1;
            }
            if (int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y) > 0) {
                MoveVec.y = 1;
            } else {
                MoveVec.y = -1;
            }
            int MoveCount;
            MoveCount = abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x));
            MoveCount -= 1;
            bool IsMoveCorrect = true;
            sf::Vector2u CurrentPos(Entity->GetBoardCoordinates().x, Entity->GetBoardCoordinates().y);
            if(MoveCount > 1){
                for(unsigned int Move = 0; Move < MoveCount;Move++){
                    CurrentPos.x += MoveVec.x;
                    CurrentPos.y += MoveVec.y;
                    if((*Wnd->GetChessMapPtr())[CurrentPos.x][CurrentPos.y] != '0'){
                        IsMoveCorrect = false;
                    }
                }
            }
            if(IsMoveCorrect){
                if((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0){
                    bool AlliePeaceThere = IsAlliePeaceThere(Wnd,Entity,NewBoardCoordinates);
                    return !AlliePeaceThere;
                }
                return true;
            }
        }
    }
    return false;
}

bool IsKnightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates){
    if(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x) != 0 && int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y)) {
        sf::Vector2i PosDif;
        PosDif.x = abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x));
        PosDif.y = abs(int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y));
        if ((PosDif.x == 2 && PosDif.y == 1) || (PosDif.x == 1 && PosDif.y == 2)) {
            if ((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0) {
                bool AlliePeaceThere = IsAlliePeaceThere(Wnd,Entity,NewBoardCoordinates);
                return !AlliePeaceThere;
            }
            return true;
        }
    }
    return false;
}

bool CheckOneCordMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates){
    if((abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x)) < 2) && ((abs(int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y)) < 2))){
        if ((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0) {
            bool AlliePeaceThere = IsAlliePeaceThere(Wnd,Entity,NewBoardCoordinates);
            return !AlliePeaceThere;
        }
        return  true;
    }
    return false;
}

bool IsQueenMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates){
    bool IsOneCordMoveCorrect = CheckOneCordMoveCorrect(Wnd, Entity, NewBoardCoordinates);
    bool IsStraightMoveCorrect = ChecStraightMoveCorrect(Wnd, Entity, NewBoardCoordinates);
    bool IsCrossMoveCorrect = CheckCrossMoveCorrect(Wnd, Entity, NewBoardCoordinates);
    if(IsOneCordMoveCorrect == 1 || IsStraightMoveCorrect == 1 || IsCrossMoveCorrect == 1) {
        bool AlliePeaceThere = IsAlliePeaceThere(Wnd,Entity,NewBoardCoordinates);
        return !AlliePeaceThere;
    }
    return false;
}

bool IsAlliePeaceThere(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates){
    int CheckValue = (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2;
    if((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0) {
        if (((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==CheckValue) &&((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] % 2 == CheckValue)) {
            return true;
        }
    }
    return false;
}