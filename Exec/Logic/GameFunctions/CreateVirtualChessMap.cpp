//
// Created by SystemX on 23.05.2024.
//
#include "Headers/Logic/GameFunctions/GameFunctions.h"
/*
            3,7,5,9,11,5,7,3,
            1,1,1,1,1,1,1,1,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            2,2,2,2,2,2,2,2,
            4,8,6,10,12,6,8,4,
 */
/*
     * ChessMap id's
     * 0 - Empty
     * 2 - WhitePawn
     * 1 - BlackPawn
     * 4 - WhiteTower
     * 3 - BlackTower
     * 6 - WhiteBishop
     * 5 - BlackBishop
     * 8 - WhiteHorse
     * 7 - BlackHorse
     * 10 - WhiteQueen
     * 9 - BlackQueen
     * 12 - WhiteKing
     * 11 - BlackKing
*/

void FillVirtualChessMapWithZeroes(std::vector<std::vector<uint32_t>> &ChessMap);

//Main function
void CreateVirtualChessMap(std::vector<std::vector<uint32_t>> &ChessMap){

    FillVirtualChessMapWithZeroes(ChessMap);
    //Now setting peaces - ofc hardcode
    //White peaces
    //Pawns
    for(unsigned int x = 0; x < 8;x++){
        ChessMap[1][x] = 1;
    }
    //3,7,5,9,11,5,7,3,
    ChessMap[0][0] = 3;
    ChessMap[0][1] = 7;
    ChessMap[0][2] = 5;
    ChessMap[0][3] = 9;
    ChessMap[0][4] = 11;
    ChessMap[0][5] = 5;
    ChessMap[0][6] = 7;
    ChessMap[0][7] = 3;

    //BlackPeaces
    //Pawns
    for(unsigned int x = 0; x < 8;x++){
        ChessMap[6][x] = 2;
    }
    //4,8,6,10,12,6,8,4,
    ChessMap[7][0] = 4;
    ChessMap[7][1] = 8;
    ChessMap[7][2] = 6;
    ChessMap[7][3] = 10;
    ChessMap[7][4] = 12;
    ChessMap[7][5] = 6;
    ChessMap[7][6] = 8;
    ChessMap[7][7] = 4;
}

void FillVirtualChessMapWithZeroes(std::vector<std::vector<uint32_t>> &ChessMap){
    for(unsigned int y = 0; y < ChessBoardSize.y;y++){
        for(unsigned int x = 0; x < ChessBoardSize.x;x++){
            ChessMap[y][x] = 0;
        }
    }
}