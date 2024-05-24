//
// Created by SystemX on 23.05.2024.
//

#include "Headers/Logic/Systems/EventSystem.h"

std::string GetEntityType(ChessPeace *Entity);
bool IsPawnMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool CheckStraightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool CheckCrossMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsKnightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool CheckOneCordMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsQueenMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsAlliePeaceThere(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsEnemyPeaceThere(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
bool IsTileEmpty(Window *Wnd, sf::Vector2u CoordinatesToCheck);
void Move(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates);
void DestroyEntity(Window *Wnd, ChessPeace *Entity, sf::Vector2u EntityCoordinates);
bool IsKingAttacked(Window *Wnd, sf::Vector2u EntityCoordinates);
bool IsKingChecked(Window* Wnd);
bool IsTileAttacked(Window *Wnd,sf::Vector2u Tile);
unsigned int CountOfKingAttackers(Window *Wnd,sf::Vector2u Tile);
sf::Vector2u GetKingTileCoordinates(Window *Wnd);
bool IsPeaceProtectKing(Window *Wnd, ChessPeace *Entity, sf::Vector2u EntityCoordinates);

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

void MoveEntity(Window* Wnd, ChessPeace* Entity, sf::Vector2f PrevPos, std::string EntityType) {
    auto mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
    auto translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    mouse_pos = sf::Mouse::getPosition(*Wnd->GetWindowPtr());
    translated_pos = Wnd->GetWindowPtr()->mapPixelToCoords(mouse_pos);
    sf::Vector2u PrevBoardCoordinates = Entity->GetBoardCoordinates();
    sf::Vector2u NewBoardCoordinates;
    NewBoardCoordinates.x = int(translated_pos.x) / 64;
    NewBoardCoordinates.y = int(translated_pos.y + 16) / 64;
    if (IsKingChecked(Wnd)) {
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] ==
            12 - Wnd->CurrentPlayerMove) {
            if (!IsTileAttacked(Wnd, NewBoardCoordinates)) {
                if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                    DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                    Move(Wnd, Entity, NewBoardCoordinates);
                    Wnd->NextMove();
                } else {
                    Move(Wnd, Entity, NewBoardCoordinates);
                    Wnd->NextMove();
                }
            } else {
                Entity->SetPeaceCoordinates(PrevPos);
            }
        } else {
            if (IsPeaceProtectKing(Wnd, Entity, NewBoardCoordinates)) {
                Move(Wnd, Entity, NewBoardCoordinates);
                Wnd->NextMove();
            } else {
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
    } else {
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 2 ||
            (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 1) {
            if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==
                Wnd->CurrentPlayerMove) {
                if (IsPawnMoveCorrect(Wnd, Entity, NewBoardCoordinates)) {
                    if (!IsPeaceProtectKing(Wnd, Entity, NewBoardCoordinates)) {
                        if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                            DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        } else {
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        }
                    } else {
                        Entity->SetPeaceCoordinates(PrevPos);
                    }
                } else {
                    Entity->SetPeaceCoordinates(PrevPos);
                }
            }else{
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 4 ||
            (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 3) {
            if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==
                Wnd->CurrentPlayerMove) {
                if (CheckStraightMoveCorrect(Wnd, Entity, NewBoardCoordinates)) {
                    if (!IsPeaceProtectKing(Wnd, Entity, NewBoardCoordinates)) {
                        if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                            DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        } else {
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        }
                    } else {
                        Entity->SetPeaceCoordinates(PrevPos);
                    }
                } else {
                    Entity->SetPeaceCoordinates(PrevPos);
                }
            }else{
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 6 ||
            (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 5) {
            if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==
                Wnd->CurrentPlayerMove) {
                if (CheckCrossMoveCorrect(Wnd, Entity, NewBoardCoordinates)) {
                    if (!IsPeaceProtectKing(Wnd, Entity, NewBoardCoordinates)) {
                        if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                            DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        } else {
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        }
                    } else {
                        Entity->SetPeaceCoordinates(PrevPos);
                    }
                } else {
                    Entity->SetPeaceCoordinates(PrevPos);
                }
            }else{
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 8 ||
            (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 7) {
            if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==
                Wnd->CurrentPlayerMove) {
                if (IsKnightMoveCorrect(Wnd, Entity, NewBoardCoordinates)) {
                    if (!IsPeaceProtectKing(Wnd, Entity, NewBoardCoordinates)) {
                        if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                            DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        } else {
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        }
                    } else {
                        Entity->SetPeaceCoordinates(PrevPos);
                    }
                } else {
                    Entity->SetPeaceCoordinates(PrevPos);
                }
            }else{
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 10 ||
            (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 9) {
            if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==
                Wnd->CurrentPlayerMove) {
                if (IsQueenMoveCorrect(Wnd, Entity, NewBoardCoordinates)) {
                    if (!IsPeaceProtectKing(Wnd, Entity, NewBoardCoordinates)) {
                        if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                            DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        } else {
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        }
                    } else {
                        Entity->SetPeaceCoordinates(PrevPos);
                    }
                } else {
                    Entity->SetPeaceCoordinates(PrevPos);
                }
            }else{
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
        if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 12 ||
            (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] == 11) {
            if ((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 ==
                Wnd->CurrentPlayerMove) {
                if (CheckOneCordMoveCorrect(Wnd, Entity, NewBoardCoordinates)) {
                    if (!IsTileAttacked(Wnd, NewBoardCoordinates)) {
                        if (IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates)) {
                            DestroyEntity(Wnd, Entity, NewBoardCoordinates);
                            Move(Wnd, Entity, NewBoardCoordinates);
                            Wnd->NextMove();
                        } else {
                            Entity->SetPeaceCoordinates(PrevPos);
                        }
                    } else {
                        Entity->SetPeaceCoordinates(PrevPos);
                    }
                } else {
                    Entity->SetPeaceCoordinates(PrevPos);
                }
            }
            else{
                Entity->SetPeaceCoordinates(PrevPos);
            }
        }
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

bool IsPawnMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates) {
    if(abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x)) < 2){
        if(abs(int(Entity->GetBoardCoordinates().y) - int(NewBoardCoordinates.y)) < 3){
            int MoveVectorY;
            if((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2 == 0){
                MoveVectorY = 1;
            }else{
                MoveVectorY = -1;
            }
            if(Wnd->IsViewFlipped()){
                MoveVectorY *= -1;
            }
            bool IsVectorCorrect = false;
            if(Entity->GetBoardCoordinates().y - NewBoardCoordinates.y == MoveVectorY || Entity->GetBoardCoordinates().y - NewBoardCoordinates.y == MoveVectorY * 2){
                IsVectorCorrect = true;
            }
            if(IsVectorCorrect){
                if (abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x)) == 0) {
                    if ((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] == 0) {
                        bool AlliePeaceThere = IsAlliePeaceThere(Wnd, Entity, NewBoardCoordinates);
                        if (AlliePeaceThere) {
                            return false;
                        }
                        bool EnemyPeaceThere = IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates);
                        if (EnemyPeaceThere) {
                            return false;
                        }
                        return true;
                    }else{
                        return false;
                    }
                } else {
                    if (abs(int(Entity->GetBoardCoordinates().x) - int(NewBoardCoordinates.x)) == 1) {
                        bool EnemyPeaceThere = IsEnemyPeaceThere(Wnd, Entity, NewBoardCoordinates);
                        return EnemyPeaceThere;
                    }else{
                        return false;
                    }
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool CheckStraightMoveCorrect(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates) {
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
            bool IsMoveCorrect = true;
            sf::Vector2u CurrentPos(Entity->GetBoardCoordinates().y, Entity->GetBoardCoordinates().x);
            if(MoveCount > 1){
                for(unsigned int Move = 0; Move < MoveCount-1;Move++){
                    CurrentPos.x += MoveVec.x;
                    CurrentPos.y += MoveVec.y;
                    if((*Wnd->GetChessMapPtr())[CurrentPos.y][CurrentPos.x] != '0'){
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
    bool IsStraightMoveCorrect = CheckStraightMoveCorrect(Wnd, Entity, NewBoardCoordinates);
    bool IsCrossMoveCorrect = CheckCrossMoveCorrect(Wnd, Entity, NewBoardCoordinates);
    if(IsStraightMoveCorrect == 1 || IsCrossMoveCorrect == 1) {
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
bool IsEnemyPeaceThere(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates){
    if((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] != 0) {
        if (((*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] % 2) != ((*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] % 2)) {
            return true;
        }
    }
    return false;
}

bool IsTileEmpty(Window *Wnd, sf::Vector2u CoordinatesToCheck){
    if((*Wnd->GetChessMapPtr())[CoordinatesToCheck.y][CoordinatesToCheck.x] == 0){
        return true;
    }
    return false;
}

void Move(Window *Wnd, ChessPeace *Entity,sf::Vector2u NewBoardCoordinates) {
    uint32_t TempEntityId = (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x];
    (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x] = 0;
    (*Wnd->GetChessMapPtr())[NewBoardCoordinates.y][NewBoardCoordinates.x] = TempEntityId;
    Entity->SetBoardCoordinates(NewBoardCoordinates);
}

void DestroyEntity(Window *Wnd, ChessPeace *Entity, sf::Vector2u EntityCoordinates){
    std::string EntityNameToDestroy;
    for(auto& Object : Wnd->GetObjectManagerPtr()->GetStorage())
    {
       if(Object.second->GetBoardCoordinates() == EntityCoordinates){
           EntityNameToDestroy = Object.first;
       }
    }
    Wnd->GetObjectManagerPtr()->Delete(EntityNameToDestroy);
//    (*Wnd->GetChessMapPtr())[EntityCoordinates.y][EntityCoordinates.x] = (*Wnd->GetChessMapPtr())[Entity->GetBoardCoordinates().y][Entity->GetBoardCoordinates().x];
}

bool IsKingAttacked(Window *Wnd, sf::Vector2u EntityCoordinates){
    if((*Wnd->GetChessMapPtr())[EntityCoordinates.y][EntityCoordinates.x] == 11 || (*Wnd->GetChessMapPtr())[EntityCoordinates.y][EntityCoordinates.x] == 12){
        return true;
    }
    return false;
}

bool IsKingChecked(Window* Wnd) {
    bool AttackerSide = Wnd->CurrentPlayerMove - 1;
    sf::Vector2u OwnKingCoordinates = GetKingTileCoordinates(Wnd);
    for (auto &Object: Wnd->GetObjectManagerPtr()->GetStorage()) {
        if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] !=
            0) {
            if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] %
                2 == AttackerSide) {
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    2 - AttackerSide) {
                    if(IsPawnMoveCorrect(Wnd, Object.second, OwnKingCoordinates)){
                        return IsKingAttacked(Wnd, OwnKingCoordinates);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    4 - AttackerSide) {
                    if(CheckStraightMoveCorrect(Wnd,Object.second,OwnKingCoordinates)) {
                        return IsKingAttacked(Wnd, OwnKingCoordinates);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    6 - AttackerSide) {
                    if(CheckCrossMoveCorrect(Wnd,Object.second,OwnKingCoordinates)){
                        return IsKingAttacked(Wnd,OwnKingCoordinates);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    8 - AttackerSide) {
                    if(IsKnightMoveCorrect(Wnd,Object.second,OwnKingCoordinates)) {
                        return IsKingAttacked(Wnd,  OwnKingCoordinates);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    10 - AttackerSide) {
                    if(IsQueenMoveCorrect(Wnd,Object.second,OwnKingCoordinates)) {
                        return IsKingAttacked(Wnd, OwnKingCoordinates);
                    }
                }
            }
        }
    }
    return false;
}

bool IsTileAttacked(Window *Wnd,sf::Vector2u Tile){
    bool AttackerSide = Wnd->CurrentPlayerMove - 1;
    for (auto &Object: Wnd->GetObjectManagerPtr()->GetStorage()) {
        if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] !=
            0) {
            if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] %
                2 == AttackerSide) {
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    2 - AttackerSide) {
                    if(IsPawnMoveCorrect(Wnd, Object.second, Tile)){
                        return IsKingAttacked(Wnd, Tile);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    4 - AttackerSide) {
                    if(CheckStraightMoveCorrect(Wnd,Object.second,Tile)) {
                        return IsKingAttacked(Wnd, Tile);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    6 - AttackerSide) {
                    if(CheckCrossMoveCorrect(Wnd,Object.second,Tile)){
                        return IsKingAttacked(Wnd,Tile);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    8 - AttackerSide) {
                    if(IsKnightMoveCorrect(Wnd,Object.second,Tile)) {
                        return IsKingAttacked(Wnd, Tile);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    10 - AttackerSide) {
                    if(IsQueenMoveCorrect(Wnd,Object.second,Tile)) {
                        return IsKingAttacked(Wnd, Tile);
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    12 - AttackerSide) {
                    if(CheckOneCordMoveCorrect(Wnd,Object.second,Tile)) {
                        return IsKingAttacked(Wnd, Tile);
                    }
                }
            }
        }
    }
}

unsigned int CountOfKingAttackers(Window *Wnd,sf::Vector2u Tile){
    unsigned int Count = 0;
    bool AttackerSide = Wnd->CurrentPlayerMove - 1;
    for (auto &Object: Wnd->GetObjectManagerPtr()->GetStorage()) {
        if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] !=
            0) {
            if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] %
                2 == AttackerSide) {
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    2 - AttackerSide) {
                    if(IsPawnMoveCorrect(Wnd, Object.second, Tile)){
                        if(IsKingAttacked(Wnd, Tile)){
                            Count++;
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    4 - AttackerSide) {
                    if(CheckStraightMoveCorrect(Wnd,Object.second,Tile)) {
                        if(IsKingAttacked(Wnd, Tile)){
                            Count++;
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    6 - AttackerSide) {
                    if(CheckCrossMoveCorrect(Wnd,Object.second,Tile)){
                        if(IsKingAttacked(Wnd, Tile)){
                            Count++;
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    8 - AttackerSide) {
                    if(IsKnightMoveCorrect(Wnd,Object.second,Tile)) {
                        if(IsKingAttacked(Wnd, Tile)){
                            Count++;
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    10 - AttackerSide) {
                    if(IsQueenMoveCorrect(Wnd,Object.second,Tile)) {
                        if(IsKingAttacked(Wnd, Tile)){
                            Count++;
                        }
                    }
                }
            }
        }
    }
    return Count;
}

bool IsPeaceProtectKing(Window *Wnd, ChessPeace *Entity, sf::Vector2u EntityNewCoordinates){
    std::vector<std::vector<uint32_t>>PrevChessMap(*Wnd->GetChessMapPtr());
    sf::Vector2u PrevCoordinates = Entity->GetBoardCoordinates();
    Move(Wnd,Entity,EntityNewCoordinates);
    sf::Vector2u KingTile;
    if(CountOfKingAttackers(Wnd,KingTile) == 0){
        Wnd->SetChessMap(PrevChessMap);
        Entity->SetBoardCoordinates(PrevCoordinates);
        return false;
    }
    Wnd->SetChessMap(PrevChessMap);
    Entity->SetBoardCoordinates(PrevCoordinates);
    return true;
}

sf::Vector2u GetKingTileCoordinates(Window *Wnd){
    bool AttackerSide = Wnd->CurrentPlayerMove - 1;
    sf::Vector2u OwnKingCoordinates;
    for (auto &Object: Wnd->GetObjectManagerPtr()->GetStorage()) {
        if((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] == 12 - Wnd->CurrentPlayerMove){
            OwnKingCoordinates = Object.second->GetBoardCoordinates();
        }
    }
    return OwnKingCoordinates;
}

bool IsKingCheckmated(Window* Wnd){
    sf::Vector2u TempTile;
    bool DefenderSide = Wnd->CurrentPlayerMove;
    for (auto &Object: Wnd->GetObjectManagerPtr()->GetStorage()) {
        if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] !=
            0) {
            if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] %
                2 == DefenderSide) {
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    2 - DefenderSide) {
                    for(TempTile.y = 0; TempTile.y < 8;TempTile.y++){
                        for(TempTile.x = 0; TempTile.x < 8;TempTile.x++){
                            if(IsPawnMoveCorrect(Wnd, Object.second, TempTile)){
                                if(IsPeaceProtectKing(Wnd,Object.second,TempTile)){
                                    return false;
                                }
                            }
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    4 - DefenderSide) {
                    for(TempTile.y = 0; TempTile.y < 8;TempTile.y++){
                        for(TempTile.x = 0; TempTile.x < 8;TempTile.x++){
                            if(CheckStraightMoveCorrect(Wnd,Object.second,TempTile)) {
                                if(IsPeaceProtectKing(Wnd,Object.second,TempTile)){
                                    return false;
                                }
                            }
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    6 - DefenderSide) {
                    for(TempTile.y = 0; TempTile.y < 8;TempTile.y++){
                        for(TempTile.x = 0; TempTile.x < 8;TempTile.x++){
                            if(CheckCrossMoveCorrect(Wnd,Object.second,TempTile)){
                                if(IsPeaceProtectKing(Wnd,Object.second,TempTile)){
                                    return false;
                                }
                            }
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    8 - DefenderSide) {
                    for(TempTile.y = 0; TempTile.y < 8;TempTile.y++){
                        for(TempTile.x = 0; TempTile.x < 8;TempTile.x++){
                            if(IsKnightMoveCorrect(Wnd,Object.second,TempTile)) {
                                if(IsPeaceProtectKing(Wnd,Object.second,TempTile)){
                                    return false;
                                }
                            }
                        }
                    }
                }
                if ((*Wnd->GetChessMapPtr())[Object.second->GetBoardCoordinates().y][Object.second->GetBoardCoordinates().x] ==
                    10 - DefenderSide) {
                    for(TempTile.y = 0; TempTile.y < 8;TempTile.y++){
                        for(TempTile.x = 0; TempTile.x < 8;TempTile.x++){
                            if(IsQueenMoveCorrect(Wnd,Object.second,TempTile)) {
                                if(IsPeaceProtectKing(Wnd,Object.second,TempTile)){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

