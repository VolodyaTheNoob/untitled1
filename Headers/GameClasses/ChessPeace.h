//
// Created by SystemX on 23.05.2024.
//

#ifndef UNTITLED1_CHESSPEACE_H
#define UNTITLED1_CHESSPEACE_H

#include "Headers/StandartLibraries.h"
#include "Headers/SFML.h"
#include "Headers/Abstracts/Entity.h"
#include "Headers/GameClasses/ChessBoard.h"
#include "Headers/GameClasses/PeaceMap.h"
/*
 * Abstract class for game used to build ChessPeaces
 */
class ChessPeace : public Entity{
    friend class Pawn;friend class Bishop;friend class Knight;friend class Rook;friend class Queen;friend class King;
private:
    static inline std::string Type = "Unknown";
    std::string Team = "Unknown";
    sf::Vector2u Coordinates;//(1,1) | (8,8) - like this
public:
    ChessPeace();
    explicit ChessPeace(sf::Vector2u Coordinates);
    ChessPeace(sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    ChessPeace(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates);
    ChessPeace(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2u BoardSize);
    ChessPeace(std::string Name, sf::Sprite* Sprite ,sf::Vector2u Coordinates, sf::Vector2f SpriteCoordinates);
    ~ChessPeace();
    virtual void Move(sf::Vector2u CoordinatesToMove, sf::Vector2f PeaceCoordinatesToMove);
    virtual void Destroy();
    std::string GetType();
    void SetType(std::string NewType);
    std::string GetTeam();
    sf::Vector2u GetBoardCoordinates();
    void SetCalculatedPeaceCoordinates(sf::Vector2u BoardSize);
    void SetBoardCoordinates(sf::Vector2u NewCoordinates);
    void SetPeaceCoordinates(sf::Vector2f NewCoordinates);
    sf::Vector2f GetPeaceCoordinates();
    void SetTeam(std::string NewTeam);
};


#endif //UNTITLED1_CHESSPEACE_H
