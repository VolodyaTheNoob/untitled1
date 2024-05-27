//
// Created by SystemX on 25.05.2024.
//

#include "Headers/GameClasses/PeaceMap.h"

//Constructors
PeaceMap::PeaceMap(){
    this->Size = sf::Vector2u(0,0);
    this->Map = new std::vector<std::vector<ChessPeace*>>(0,std::vector<ChessPeace*>(0));
}
PeaceMap::PeaceMap(sf::Vector2u BoardSize){
    this->Size = BoardSize;
    this->Map = new std::vector<std::vector<ChessPeace*>>(BoardSize.y,std::vector<ChessPeace*>(BoardSize.x));
}
//Destructors
PeaceMap::~PeaceMap() = default;
//Functions
void PeaceMap::AddPeace(ChessPeace* PeaceToAdd, sf::Vector2u BoardCoordinates){
    //std::string Name, std::string Type, std::string Team sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates
    (*this->Map)[BoardCoordinates.y][BoardCoordinates.x] = new ChessPeace(PeaceToAdd->GetName(),PeaceToAdd->GetType(),PeaceToAdd->GetTeam(),PeaceToAdd->GetSprite(),PeaceToAdd->GetBoardCoordinates(),PeaceToAdd->GetSprite()->getPosition());
}
void PeaceMap::MovePeace(ChessPeace* PeaceToMove, sf::Vector2u BoardCoordinates,sf::Vector2f NewPeacePosition){
    if(PeaceToMove != nullptr) {
        sf::Vector2u PeaceToMoveCoordinates = PeaceToMove->GetBoardCoordinates();
        if ((*this->GetMapPtr())[BoardCoordinates.y][BoardCoordinates.x] != nullptr) {
            (*this->GetMapPtr())[BoardCoordinates.y][BoardCoordinates.x] = nullptr;
        }
        (*this->GetMapPtr())[PeaceToMoveCoordinates.y][PeaceToMoveCoordinates.x] = nullptr;
        (*this->GetMapPtr())[BoardCoordinates.y][BoardCoordinates.x] = PeaceToMove;
        (*this->GetMapPtr())[BoardCoordinates.y][BoardCoordinates.x]->SetBoardCoordinates(BoardCoordinates);
        (*this->GetMapPtr())[BoardCoordinates.y][BoardCoordinates.x]->SetPeaceCoordinates(NewPeacePosition);
    }
}

std::vector<std::vector<ChessPeace*>>* PeaceMap::GetMapPtr(){
    return this->Map;
}

sf::Vector2u* PeaceMap::GetPeaceBoardCoordinates(std::string Team, std::string Type){
    //I will use it now only for king - but in other cases we should return array
    sf::Vector2u* PeaceBoardCoordinates = nullptr;
    bool Founded = false;
    for(unsigned int y = 0; y < this->Size.y && !Founded;y++){
        for(unsigned int x = 0; x < this->Size.x && !Founded;x++){
            if((*this->GetMapPtr())[y][x] != nullptr){
                if((*this->GetMapPtr())[y][x]->GetType() == Type){
                    if((*this->GetMapPtr())[y][x]->GetTeam() == Team){
                        if(PeaceBoardCoordinates == nullptr){
                            PeaceBoardCoordinates = new sf::Vector2u();
                        }
                        *PeaceBoardCoordinates = (*this->GetMapPtr())[y][x]->GetBoardCoordinates();
                        Founded = true;
                    }
                }
            }
        }
    }
    return PeaceBoardCoordinates;
}

void PeaceMap::DestroyPeace(sf::Vector2u PeaceToDestroyCoordinates){
    if((*this->GetMapPtr())[PeaceToDestroyCoordinates.y][PeaceToDestroyCoordinates.x] != nullptr){
        (*this->GetMapPtr())[PeaceToDestroyCoordinates.y][PeaceToDestroyCoordinates.x]->Destroy();
        (*this->GetMapPtr())[PeaceToDestroyCoordinates.y][PeaceToDestroyCoordinates.x] = nullptr;
    }
}