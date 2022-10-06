#ifndef CLASS_MM_TETRIS_PIECE
#define CLASS_MM_TETRIS_PIECE

#include <vector>
#include <cmath>
#include <iostream>
#include "MMStone3d.h"
#include "MMGraphicsSingleton.h"

class MMTetrisPiece
{
public:
    MMTetrisPiece(int posX, int posY, int particleSize);
    std::vector<MMStone3d *> *pieces;
    int blocksCount = 4;
    int pieceType = 5;
    int piecePhase = 0;
    int pieceNumberOfPhases = 4;
    void moveDown();
    void moveLeft();
    void moveRight();
    void rorateLeft();
    void rotateRight();
    void updateVertices();
};

#endif