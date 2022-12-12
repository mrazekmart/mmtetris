#ifndef CLASS_MM_TETRIS_PIECE
#define CLASS_MM_TETRIS_PIECE

#include <vector>
#include <cmath>
#include <iostream>
#include "MMStone3d.h"
#include "MMGraphicsSingleton.h"

class MMTetrisManager;

class MMTetrisPiece
{
public:
    MMTetrisPiece(int posX, int posY, int particleSize);
    std::vector<MMStone3d *> *pieces;
    int positionX, positionY, particleSize;
    int blocksCount = 4;
    int pieceType = 1;
    int piecePhase = 0;
    int pieceNumberOfPhases = 4;
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    /* 
    void rorateLeft(std::vector<MMStone3d *> *matrix);
    void rotateRight(std::vector<MMStone3d *> *matrix);
     */
    void RorateLeft(MMTetrisManager *mmTetrisManager);
    void RotateRight(MMTetrisManager *mmTetrisManager);
    void UpdateVertices();
    //bool checkCollision(MMStone3d *mmStone, int moveX, int moveY, std::vector<MMStone3d *> *matrix);
    bool CheckCollision(MMStone3d *mmStone, int moveX, int moveY, MMTetrisManager *mmTetrisManager);
};

#endif