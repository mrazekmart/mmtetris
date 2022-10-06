#include "MMTetrisManager.h"

MMTetrisManager::MMTetrisManager(int bW, int bH, int particleSize)
{
    this->blocksWidth = bW;
    this->blocksHeight = bH;
    this->particleSize = particleSize;
    this->spawnPointX = bW / 2;
    this->spawnPointY = 3;
    this->matrix = new std::vector<MMStone3d *>(bW * bH);
    this->createWalls();
    this->createNewPiece();
}

void MMTetrisManager::createWalls()
{
    for (int i = 0; i < this->blocksWidth; i++)
    {
        for (int j = 0; j < this->blocksHeight; j++)
        {
            if (i == 0 || i == this->blocksWidth - 1 || j == 0 || j == this->blocksHeight - 1)
            {
                MMStone3d *mmStone3d = new MMStone3d(i * particleSize, j * particleSize, 0, this->particleSize);
                this->blocksCount++;
                this->setElementAtIndex(i, j, mmStone3d);

                std::vector<float> gV = mmStone3d->getCube()->getVertices();
                this->verticesWalls.insert(std::end(this->verticesWalls), std::begin(gV), std::end(gV));
                std::vector<unsigned int> gI = mmStone3d->getCube()->getIndices();
                for (int ind : gI)
                {
                    this->indicesWalls.push_back(ind + this->indicesCount);
                }
                this->indicesCount += mmStone3d->getCube()->getIndCount();
                this->matrixWallsIndices += mmStone3d->getCube()->getIndCount();
                std::vector<float> gC = mmStone3d->getCube()->getColor();
                this->colorsWalls.insert(std::end(this->colorsWalls), std::begin(gC), std::end(gC));
            }
        }
    }
}

void MMTetrisManager::createNewPiece()
{
    this->activePiece = new MMTetrisPiece(spawnPointX, spawnPointY, particleSize);
    this->verticesActivePiece.clear();
    this->indicesActivePiece.clear();
    this->colorsActivePiece.clear();
    for (MMStone3d *mmStone3d : *activePiece->pieces)
    {
        this->blocksCount++;
        std::vector<float> gV = mmStone3d->getCube()->getVertices();
        this->verticesActivePiece.insert(std::end(this->verticesActivePiece), std::begin(gV), std::end(gV));
        std::vector<unsigned int> gI = mmStone3d->getCube()->getIndices();
        for (int ind : gI)
        {
            this->indicesActivePiece.push_back(ind + this->indicesCount);
        }
        this->indicesCount += mmStone3d->getCube()->getIndCount();
        std::vector<float> gC = mmStone3d->getCube()->getColor();
        this->colorsActivePiece.insert(std::end(this->colorsActivePiece), std::begin(gC), std::end(gC));
    }
    spawnNew = false;

    this->verticesFinished.clear();
    this->indicesFinished.clear();
    this->colorsFinished.clear();
    this->matrixFinishedIndices = 0;
    for (int j = this->blocksHeight - 2; j > 0; j--)
    {
        for (int i = 1; i < this->blocksWidth - 1; i++)
        {
            MMStone3d *mmStone3d = getElementAtIndex(i, j);
            if (mmStone3d == nullptr)
                continue;

            std::vector<float> gV = mmStone3d->getCube()->getVertices();
            this->verticesFinished.insert(std::end(this->verticesFinished), std::begin(gV), std::end(gV));
            std::vector<unsigned int> gI = mmStone3d->getCube()->getIndices();
            for (int ind : gI)
            {
                this->indicesFinished.push_back(ind + this->matrixFinishedIndices + this->matrixWallsIndices);
            }
            this->matrixFinishedIndices += mmStone3d->getCube()->getIndCount();
            std::vector<float> gC = mmStone3d->getCube()->getColor();
            this->colorsFinished.insert(std::end(this->colorsFinished), std::begin(gC), std::end(gC));
        }
    }

    this->verticesAll.clear();
    this->indicesAll.clear();
    this->colorsAll.clear();

    this->verticesAll.insert(std::end(this->verticesAll), std::begin(this->verticesWalls), std::end(this->verticesWalls));
    this->verticesAll.insert(std::end(this->verticesAll), std::begin(this->verticesFinished), std::end(this->verticesFinished));
    this->verticesAll.insert(std::end(this->verticesAll), std::begin(this->verticesActivePiece), std::end(this->verticesActivePiece));

    this->indicesAll.insert(std::end(this->indicesAll), std::begin(this->indicesWalls), std::end(this->indicesWalls));
    this->indicesAll.insert(std::end(this->indicesAll), std::begin(this->indicesFinished), std::end(this->indicesFinished));
    this->indicesAll.insert(std::end(this->indicesAll), std::begin(this->indicesActivePiece), std::end(this->indicesActivePiece));

    this->colorsAll.insert(std::end(this->colorsAll), std::begin(this->colorsWalls), std::end(this->colorsWalls));
    this->colorsAll.insert(std::end(this->colorsAll), std::begin(this->colorsFinished), std::end(this->colorsFinished));
    this->colorsAll.insert(std::end(this->colorsAll), std::begin(this->colorsActivePiece), std::end(this->colorsActivePiece));

    MMGraphicsSingleton::getInstance().verticesAll = this->verticesAll;
    MMGraphicsSingleton::getInstance().indicesAll = this->indicesAll;
    MMGraphicsSingleton::getInstance().colorsAll = this->colorsAll;
}

void MMTetrisManager::update(GLFWwindow *window)
{
    if (this->spawnNew)
    {
        this->createNewPiece();
    }
    if (this->moveDown)
    {
        this->movePieceDown();
        this->moveDown = false;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && moveSide)
    {
        this->movePieceLeft();
        this->moveSide = false;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && moveSide)
    {
        this->movePieceRight();
        this->moveSide = false;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        this->moveDown = true;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_RELEASE)
    {
        this->moveDown = false;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && rotate)
    {
        if (this->activePiece->pieces->at(0)->positionX >= 2 * particleSize &&
            this->activePiece->pieces->at(0)->positionX <= (this->blocksWidth - 3) * particleSize)
        {
            if (this->activePiece->pieceType == 5 &&
                this->activePiece->pieces->at(0)->positionX >= (this->blocksWidth - 3) * particleSize)
            {
                return;
            }

            this->roratePieceRight();
            this->rotate = false;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && rotate)
    {
        if (this->activePiece->pieces->at(0)->positionX >= 2 * particleSize &&
            this->activePiece->pieces->at(0)->positionX <= (this->blocksWidth - 3) * particleSize)
        {
            this->roratePieceLeft();
            this->rotate = false;
        }
    }
}

void MMTetrisManager::fallFinished()
{
    for (MMStone3d *mmStone3d : *this->activePiece->pieces)
    {
        int matrixPosStoneX = mmStone3d->positionX / this->particleSize;
        int matrixPosStoneY = mmStone3d->positionY / this->particleSize;
        this->setElementAtIndex(matrixPosStoneX, matrixPosStoneY, mmStone3d);
        this->matrixId[matrixPosStoneX][matrixPosStoneY] = this->matrixIdCount;
        this->matrixIdCount++;
    }

    this->checkForFullLines();
}
void MMTetrisManager::checkForFullLines()
{
    for (int j = this->blocksHeight - 2; j > 0; j--)
    {
        bool isLineFull = true;
        for (int i = 1; i < this->blocksWidth - 1; i++)
        {
            if (this->getElementAtIndex(i, j) == nullptr)
            {
                isLineFull = false;
                break;
            }
        }
        if (isLineFull)
        {
            for (int k = j; k > 1; k--)
            {
                for (int l = 1; l < this->blocksWidth - 1; l++)
                {
                    MMStone3d *stone = this->getElementAtIndex(l, k - 1);
                    if (stone)
                    {
                        stone->moveDown();
                    }
                    this->setElementAtIndex(l, k, this->getElementAtIndex(l, k - 1));
                }
            }
            j++;
            this->matrixFinishedIndices -= 8 * (this->blocksWidth - 2);
            this->indicesCount -= 8 * (this->blocksWidth - 2);
        }
    }
}
void MMTetrisManager::movePieceDown()
{
    for (MMStone3d *stone : *this->activePiece->pieces)
    {
        int matrixPosStoneX = stone->positionX / this->particleSize;
        int matrixPosStoneY = stone->positionY / this->particleSize;
        if (this->getElementAtIndex(matrixPosStoneX, matrixPosStoneY + 1))
        {
            this->fallFinished();
            this->spawnNew = true;
            return;
        }
    }
    this->activePiece->moveDown();
}
void MMTetrisManager::movePieceRight()
{
    for (MMStone3d *stone : *this->activePiece->pieces)
    {
        int matrixPosStoneX = stone->positionX / this->particleSize;
        int matrixPosStoneY = stone->positionY / this->particleSize;
        if (this->getElementAtIndex(matrixPosStoneX + 1, matrixPosStoneY))
        {
            return;
        }
    }
    this->activePiece->moveRight();
}
void MMTetrisManager::movePieceLeft()
{
    for (MMStone3d *stone : *this->activePiece->pieces)
    {
        int matrixPosStoneX = stone->positionX / this->particleSize;
        int matrixPosStoneY = stone->positionY / this->particleSize;
        if (this->getElementAtIndex(matrixPosStoneX - 1, matrixPosStoneY))
        {
            return;
        }
    }
    this->activePiece->moveLeft();
}

void MMTetrisManager::roratePieceLeft()
{
    this->activePiece->rorateLeft(this);
}
void MMTetrisManager::roratePieceRight()
{
    this->activePiece->rotateRight(this);
}
MMStone3d *MMTetrisManager::getElementAtIndex(int x, int y)
{
    return (*this->matrix)[x + y * this->blocksWidth];
}

void MMTetrisManager::setElementAtIndex(int x, int y, MMStone3d *element)
{
    (*this->matrix)[x + y * this->blocksWidth] = element;
}
MMTetrisManager::~MMTetrisManager()
{
    if (this->matrix)
    {
        delete (this->matrix);
    }
}