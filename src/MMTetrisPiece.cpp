#include "MMTetrisPiece.h"
#include "MMTetrisManager.h"

MMTetrisPiece::MMTetrisPiece(int posX, int posY, int particleSize)
{

    this->pieces = new std::vector<MMStone3d *>();
    this->particleSize = particleSize;
    int posXFirst, posYFirst;
    int posXSecond, posYSecond;
    int posXThird, posYThird;
    int posXFourth, posYFourth;

    this->pieceType = rand() % 7 + 1;

    switch (this->pieceType)
    {
    case 1:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = posX * particleSize;
        posYSecond = (posY - 1) * particleSize;

        posXThird = (posX - 1) * particleSize;
        posYThird = posY * particleSize;

        posXFourth = (posX + 1) * particleSize;
        posYFourth = posY * particleSize;
        break;

    case 2:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = posX * particleSize;
        posYSecond = (posY - 1) * particleSize;

        posXThird = (posX - 1) * particleSize;
        posYThird = (posY - 1) * particleSize;

        posXFourth = posX * particleSize;
        posYFourth = (posY + 1) * particleSize;
        break;
    case 3:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = posX * particleSize;
        posYSecond = (posY - 1) * particleSize;

        posXThird = (posX + 1) * particleSize;
        posYThird = (posY - 1) * particleSize;

        posXFourth = posX * particleSize;
        posYFourth = (posY + 1) * particleSize;
        break;
    case 4:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = posX * particleSize;
        posYSecond = (posY - 1) * particleSize;

        posXThird = (posX + 1) * particleSize;
        posYThird = (posY - 1) * particleSize;

        posXFourth = (posX + 1) * particleSize;
        posYFourth = posY * particleSize;
        break;
    case 5:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = posX * particleSize;
        posYSecond = (posY - 1) * particleSize;

        posXThird = posX * particleSize;
        posYThird = (posY + 1) * particleSize;

        posXFourth = posX * particleSize;
        posYFourth = (posY + 2) * particleSize;
        break;
    case 6:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = (posX - 1) * particleSize;
        posYSecond = posY * particleSize;

        posXThird = posX * particleSize;
        posYThird = (posY + 1) * particleSize;

        posXFourth = (posX + 1) * particleSize;
        posYFourth = (posY + 1) * particleSize;
        break;
    case 7:
        posXFirst = posX * particleSize;
        posYFirst = posY * particleSize;

        posXSecond = (posX + 1) * particleSize;
        posYSecond = posY * particleSize;

        posXThird = posX * particleSize;
        posYThird = (posY + 1) * particleSize;

        posXFourth = (posX - 1) * particleSize;
        posYFourth = (posY + 1) * particleSize;
        break;
    default:
        break;
    }

    MMStone3d *mmStone3d1 = new MMStone3d(posXFirst, posYFirst, 0, particleSize);
    this->pieces->push_back(mmStone3d1);

    MMStone3d *mmStone3d2 = new MMStone3d(posXSecond, posYSecond, 0, particleSize);
    this->pieces->push_back(mmStone3d2);

    MMStone3d *mmStone3d3 = new MMStone3d(posXThird, posYThird, 0, particleSize);
    this->pieces->push_back(mmStone3d3);

    MMStone3d *mmStone3d4 = new MMStone3d(posXFourth, posYFourth, 0, particleSize);
    this->pieces->push_back(mmStone3d4);
}

void MMTetrisPiece::MoveDown()
{
    for (MMStone3d *stone : *this->pieces)
    {
        stone->MoveDown();
    }
    this->UpdateVertices();
}
void MMTetrisPiece::MoveLeft()
{
    for (MMStone3d *stone : *this->pieces)
    {
        stone->MoveLeft();
    }
    this->UpdateVertices();
}
void MMTetrisPiece::MoveRight()
{
    for (MMStone3d *stone : *this->pieces)
    {
        stone->MoveRight();
    }
    this->UpdateVertices();
}
void MMTetrisPiece::RorateLeft(MMTetrisManager *mmTetrisManager)
{
    switch (this->pieceType)
    {
    case 1:

        switch (this->piecePhase % 4)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(3), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 2:
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 3:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        default:
            break;
        }

        break;
    case 2:

        switch (this->piecePhase % 4)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, 2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 2:
            if (this->CheckCollision(this->pieces->at(1), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, -2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 3:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (this->piecePhase % 4)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, 2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 2:
            if (this->CheckCollision(this->pieces->at(1), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 3:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, -2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;

    case 5:
        switch (this->piecePhase % 2)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 2, -2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -2, 2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 6:
        switch (this->piecePhase % 2)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 0, -2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveUp();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 0, 2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveDown();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 7:
        switch (this->piecePhase % 2)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 2, 0, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveRight();
            this->pieces->at(3)->MoveRight();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -2, 0, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveLeft();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase++;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void MMTetrisPiece::RotateRight(MMTetrisManager *mmTetrisManager)
{
    switch (this->pieceType)
    {
    case 1:

        switch (this->piecePhase % 4)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase = 3;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(3), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        case 2:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        case 3:
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        default:
            break;
        }

        break;
    case 2:

        switch (this->piecePhase % 4)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase = 3;
            this->UpdateVertices();
            break;
        case 3:
            if (this->CheckCollision(this->pieces->at(1), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, 2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        case 2:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveRight();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, -2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 3:

        switch (this->piecePhase % 4)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, 2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase = 3;
            this->UpdateVertices();
            break;
        case 3:
            if (this->CheckCollision(this->pieces->at(1), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, -1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        case 2:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 0, -2, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveRight();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 2, 0, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -1, 1, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (this->piecePhase % 2)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 2, -2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveRight();
            this->piecePhase = 1;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -2, 2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 6:
        switch (this->piecePhase % 2)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 0, -2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveUp();
            this->pieces->at(3)->MoveUp();
            this->piecePhase = 1;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 0, 2, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveDown();
            this->pieces->at(3)->MoveDown();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    case 7:
        switch (this->piecePhase % 2)
        {
        case 0:
            if (this->CheckCollision(this->pieces->at(1), -1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), 1, -1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), 2, 0, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveUp();
            this->pieces->at(1)->MoveLeft();
            this->pieces->at(2)->MoveUp();
            this->pieces->at(2)->MoveRight();
            this->pieces->at(3)->MoveRight();
            this->pieces->at(3)->MoveRight();
            this->piecePhase = 1;
            this->UpdateVertices();
            break;
        case 1:
            if (this->CheckCollision(this->pieces->at(1), 1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(2), -1, 1, mmTetrisManager))
                break;
            if (this->CheckCollision(this->pieces->at(3), -2, 0, mmTetrisManager))
                break;
            this->pieces->at(1)->MoveDown();
            this->pieces->at(1)->MoveRight();
            this->pieces->at(2)->MoveDown();
            this->pieces->at(2)->MoveLeft();
            this->pieces->at(3)->MoveLeft();
            this->pieces->at(3)->MoveLeft();
            this->piecePhase--;
            this->UpdateVertices();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void MMTetrisPiece::UpdateVertices()
{
    int s = 0;
    for (MMStone3d *stone : *this->pieces)
    {
        std::vector<float> newVertices = stone->GetCube()->GetVertices();
        for (int i = 0; i < newVertices.size(); i++)
        {
            MMGraphicsSingleton::getInstance().verticesAll[MMGraphicsSingleton::getInstance().verticesAll.size() - 96 + i + (s * 24)] = newVertices[i];
        }
        s++;
    }
}

bool MMTetrisPiece::CheckCollision(MMStone3d *mmStone, int moveX, int moveY, MMTetrisManager *mmTetrisManager)
{

    if (mmTetrisManager->GetElementAtIndex(mmStone->positionX / this->particleSize + moveX,
                                           mmStone->positionY / particleSize + moveY))
    {
        return true;
    }
    return false;
}