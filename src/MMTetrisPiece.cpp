#include "MMTetrisPiece.h"

MMTetrisPiece::MMTetrisPiece(int posX, int posY, int particleSize)
{

    this->pieces = new std::vector<MMStone3d *>();

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

void MMTetrisPiece::moveDown()
{
    for (MMStone3d *stone : *this->pieces)
    {
        stone->moveDown();
    }
    this->updateVertices();
}
void MMTetrisPiece::moveLeft()
{
    for (MMStone3d *stone : *this->pieces)
    {
        stone->moveLeft();
    }
    this->updateVertices();
}
void MMTetrisPiece::moveRight()
{
    for (MMStone3d *stone : *this->pieces)
    {
        stone->moveRight();
    }
    this->updateVertices();
}
void MMTetrisPiece::rorateLeft()
{
    switch (this->pieceType)
    {
    case 1:

        switch (this->piecePhase % 4)
        {
        case 0:
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 2:
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 3:
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        default:
            break;
        }

        break;
    case 2:

        switch (this->piecePhase % 4)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveDown();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 2:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveUp();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 3:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (this->piecePhase % 4)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveDown();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 2:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 3:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveUp();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;

    case 5:
        switch (this->piecePhase % 2)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 6:
        switch (this->piecePhase % 2)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveUp();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveDown();
            this->piecePhase++;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 7:
        switch (this->piecePhase % 2)
        {
        case 0:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveRight();
            this->pieces->at(3)->moveRight();
            this->piecePhase++;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveLeft();
            this->pieces->at(3)->moveLeft();
            this->piecePhase++;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void MMTetrisPiece::rotateRight()
{
    switch (this->pieceType)
    {
    case 1:

        switch (this->piecePhase % 4)
        {
        case 0:
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase = 3;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase--;
            this->updateVertices();
            break;
        case 2:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->piecePhase--;
            this->updateVertices();
            break;
        case 3:
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->piecePhase--;
            this->updateVertices();
            break;
        default:
            break;
        }

        break;
    case 2:

        switch (this->piecePhase % 4)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveLeft();
            this->piecePhase = 3;
            this->updateVertices();
            break;
        case 3:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveDown();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase--;
            this->updateVertices();
            break;
        case 2:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveRight();
            this->piecePhase--;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveUp();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase--;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 3:

        switch (this->piecePhase % 4)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveDown();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveLeft();
            this->piecePhase = 3;
            this->updateVertices();
            break;
        case 3:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase--;
            this->updateVertices();
            break;
        case 2:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveUp();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveRight();
            this->piecePhase--;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase--;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (this->piecePhase % 2)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveRight();
            this->piecePhase = 1;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveLeft();
            this->piecePhase--;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 6:
        switch (this->piecePhase % 2)
        {
        case 0:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveUp();
            this->pieces->at(3)->moveUp();
            this->piecePhase = 1;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveDown();
            this->pieces->at(3)->moveDown();
            this->piecePhase--;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    case 7:
        switch (this->piecePhase % 2)
        {
        case 0:
            this->pieces->at(1)->moveUp();
            this->pieces->at(1)->moveLeft();
            this->pieces->at(2)->moveUp();
            this->pieces->at(2)->moveRight();
            this->pieces->at(3)->moveRight();
            this->pieces->at(3)->moveRight();
            this->piecePhase = 1;
            this->updateVertices();
            break;
        case 1:
            this->pieces->at(1)->moveDown();
            this->pieces->at(1)->moveRight();
            this->pieces->at(2)->moveDown();
            this->pieces->at(2)->moveLeft();
            this->pieces->at(3)->moveLeft();
            this->pieces->at(3)->moveLeft();
            this->piecePhase--;
            this->updateVertices();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void MMTetrisPiece::updateVertices()
{
    int s = 0;
    for (MMStone3d *stone : *this->pieces)
    {
        std::vector<float> newVertices = stone->getCube()->getVertices();
        for (int i = 0; i < newVertices.size(); i++)
        {
            MMGraphicsSingleton::getInstance().verticesAll[MMGraphicsSingleton::getInstance().verticesAll.size() - 96 + i + (s * 24)] = newVertices[i];
        }
        s++;
    }
}