#include "MMTetrisManager.h"

MMTetrisManager::MMTetrisManager(int bW, int bH, int particleSize)
{
    this->blocksWidth = bW;
    this->blocksHeight = bH;
    this->particleSize = particleSize;
    this->spawnPointX = bW / 2;
    this->spawnPointY = 3;
    this->matrix = new std::vector<MMStone3d *>(bW * bH);
    this->CreateWalls();
    this->CreateNewPiece();
}

void MMTetrisManager::CreateWalls()
{
    for (int i = 0; i < this->blocksWidth; i++)
    {
        for (int j = 0; j < this->blocksHeight; j++)
        {
            if (i == 0 || i == this->blocksWidth - 1 || j == 0 || j == this->blocksHeight - 1)
            {
                MMStone3d *mmStone3d = new MMStone3d(i * particleSize, j * particleSize, 0, this->particleSize);
                this->blocksCount++;
                this->SetElementAtIndex(i, j, mmStone3d);

                std::vector<float> gV = mmStone3d->GetCube()->GetVertices();
                this->verticesWalls.insert(std::end(this->verticesWalls), std::begin(gV), std::end(gV));
                std::vector<unsigned int> gI = mmStone3d->GetCube()->GetIndices();
                for (int ind : gI)
                {
                    this->indicesWalls.push_back(ind + this->indicesCount);
                }
                this->indicesCount += mmStone3d->GetCube()->GetIndCount();
                this->matrixWallsIndices += mmStone3d->GetCube()->GetIndCount();
                std::vector<float> gC = mmStone3d->GetCube()->GetColor();
                this->colorsWalls.insert(std::end(this->colorsWalls), std::begin(gC), std::end(gC));
            }
        }
    }
}

void MMTetrisManager::CreateNewPiece()
{
    this->activePiece = new MMTetrisPiece(spawnPointX, spawnPointY, particleSize);
    this->verticesActivePiece.clear();
    this->indicesActivePiece.clear();
    this->colorsActivePiece.clear();
    for (MMStone3d *mmStone3d : *activePiece->pieces)
    {
        this->blocksCount++;
        std::vector<float> gV = mmStone3d->GetCube()->GetVertices();
        this->verticesActivePiece.insert(std::end(this->verticesActivePiece), std::begin(gV), std::end(gV));
        std::vector<unsigned int> gI = mmStone3d->GetCube()->GetIndices();
        for (int ind : gI)
        {
            this->indicesActivePiece.push_back(ind + this->indicesCount);
        }
        this->indicesCount += mmStone3d->GetCube()->GetIndCount();
        std::vector<float> gC = mmStone3d->GetCube()->GetColor();
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
            MMStone3d *mmStone3d = GetElementAtIndex(i, j);
            if (mmStone3d == nullptr)
                continue;

            std::vector<float> gV = mmStone3d->GetCube()->GetVertices();
            this->verticesFinished.insert(std::end(this->verticesFinished), std::begin(gV), std::end(gV));
            std::vector<unsigned int> gI = mmStone3d->GetCube()->GetIndices();
            for (int ind : gI)
            {
                this->indicesFinished.push_back(ind + this->matrixFinishedIndices + this->matrixWallsIndices);
            }
            this->matrixFinishedIndices += mmStone3d->GetCube()->GetIndCount();
            std::vector<float> gC = mmStone3d->GetCube()->GetColor();
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

void MMTetrisManager::Update(GLFWwindow *window)
{
    if (this->spawnNew)
    {
        this->CreateNewPiece();
    }
    if (this->moveDown)
    {
        this->MovePieceDown();
        this->moveDown = false;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && moveSide)
    {
        this->MovePieceLeft();
        this->moveSide = false;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && moveSide)
    {
        this->MovePieceRight();
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
        this->RoratePieceRight();
        this->rotate = false;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && rotate)
    {
        this->RoratePieceLeft();
        this->rotate = false;
    }
}

void MMTetrisManager::FallFinished()
{
    for (MMStone3d *mmStone3d : *this->activePiece->pieces)
    {
        int matrixPosStoneX = mmStone3d->positionX / this->particleSize;
        int matrixPosStoneY = mmStone3d->positionY / this->particleSize;
        this->SetElementAtIndex(matrixPosStoneX, matrixPosStoneY, mmStone3d);
        this->matrixId[matrixPosStoneX][matrixPosStoneY] = this->matrixIdCount;
        this->matrixIdCount++;
    }

    this->CheckForFullLines();
}
void MMTetrisManager::CheckForFullLines()
{
    for (int j = this->blocksHeight - 2; j > 0; j--)
    {
        bool isLineFull = true;
        for (int i = 1; i < this->blocksWidth - 1; i++)
        {
            if (this->GetElementAtIndex(i, j) == nullptr)
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
                    MMStone3d *stone = this->GetElementAtIndex(l, k - 1);
                    if (stone)
                    {
                        stone->MoveDown();
                    }
                    this->SetElementAtIndex(l, k, this->GetElementAtIndex(l, k - 1));
                }
            }
            j++;
            this->matrixFinishedIndices -= 8 * (this->blocksWidth - 2);
            this->indicesCount -= 8 * (this->blocksWidth - 2);
        }
    }
}
void MMTetrisManager::MovePieceDown()
{
    for (MMStone3d *stone : *this->activePiece->pieces)
    {
        int matrixPosStoneX = stone->positionX / this->particleSize;
        int matrixPosStoneY = stone->positionY / this->particleSize;
        if (this->GetElementAtIndex(matrixPosStoneX, matrixPosStoneY + 1))
        {
            this->FallFinished();
            this->spawnNew = true;
            return;
        }
    }
    this->activePiece->MoveDown();
}
void MMTetrisManager::MovePieceRight()
{
    for (MMStone3d *stone : *this->activePiece->pieces)
    {
        int matrixPosStoneX = stone->positionX / this->particleSize;
        int matrixPosStoneY = stone->positionY / this->particleSize;
        if (this->GetElementAtIndex(matrixPosStoneX + 1, matrixPosStoneY))
        {
            return;
        }
    }
    this->activePiece->MoveRight();
}
void MMTetrisManager::MovePieceLeft()
{
    for (MMStone3d *stone : *this->activePiece->pieces)
    {
        int matrixPosStoneX = stone->positionX / this->particleSize;
        int matrixPosStoneY = stone->positionY / this->particleSize;
        if (this->GetElementAtIndex(matrixPosStoneX - 1, matrixPosStoneY))
        {
            return;
        }
    }
    this->activePiece->MoveLeft();
}

void MMTetrisManager::RoratePieceLeft()
{
    this->activePiece->RorateLeft(this);
}
void MMTetrisManager::RoratePieceRight()
{
    this->activePiece->RotateRight(this);
}
MMStone3d *MMTetrisManager::GetElementAtIndex(int x, int y)
{
    return (*this->matrix)[x + y * this->blocksWidth];
}

void MMTetrisManager::SetElementAtIndex(int x, int y, MMStone3d *element)
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