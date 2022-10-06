#ifndef CLASS_MM_TETRIS_MANAGER
#define CLASS_MM_TETRIS_MANAGER

#include "MMCube.h"
#include "MMGraphicsSingleton.h"
#include "MMStone3d.h"
#include "MMTetrisPiece.h"

#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>

class MMTetrisManager
{
public:
    MMTetrisManager(int blockWidth, int blockHeight, int particleSize);
    ~MMTetrisManager();
    int blocksCount = 0;
    bool moveSide = true;
    bool moveDown = false;
    bool rotate = true;
    void update(GLFWwindow *window);

private:
    int blocksWidth, blocksHeight, particleSize;
    int spawnPointX, spawnPointY;
    bool spawnNew = false;
    std::vector<float> verticesAll;
    std::vector<unsigned int> indicesAll;
    std::vector<float> colorsAll;

    std::vector<float> verticesWalls;
    std::vector<unsigned int> indicesWalls;
    std::vector<float> colorsWalls;

    std::vector<float> verticesFinished;
    std::vector<unsigned int> indicesFinished;
    std::vector<float> colorsFinished;

    std::vector<float> verticesActivePiece;
    std::vector<unsigned int> indicesActivePiece;
    std::vector<float> colorsActivePiece;

    int indicesCount = 0;
    // std::vector<int> matrix;
    std::vector<MMStone3d *> *matrix;
    int matrixFinishedIndices = 0;
    int matrixWallsIndices = 0;
    MMStone3d* getElementAtIndex(int x, int y);
    void setElementAtIndex(int x, int y, MMStone3d* element);

    int matrixId[50][100];
    int matrixIdCount = 0;
    MMTetrisPiece *activePiece;
    void checkForFullLines();
    void fallFinished();
    void createWalls();
    void createNewPiece();
    void movePieceDown();
    void movePieceLeft();
    void movePieceRight();
    void roratePieceLeft();
    void roratePieceRight();
};

#endif