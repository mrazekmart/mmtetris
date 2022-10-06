#include "MMStone3d.h"

MMStone3d::MMStone3d(int posX, int posY, int posZ, int particleSize)
{
    this->positionX = posX;
    this->positionY = posY;
    this->positionZ = posZ;
    this->particleSize = particleSize;
    this->mmCube = new MMCube(posX, posY, posZ, particleSize, particleSize, particleSize);
}
MMStone3d::~MMStone3d()
{
    delete (this->mmCube);
}
MMCube *MMStone3d::getCube()
{
    this->updateCube();
    return this->mmCube;
}
int MMStone3d::getMaterial()
{
    return this->material;
}
void MMStone3d::updateCube()
{
    this->mmCube->posX = this->positionX;
    this->mmCube->posY = this->positionY;
    this->mmCube->posZ = this->positionZ;
}
void MMStone3d::update(MMParticleMatrix *particleMatrix)
{
    this->updateCube();
}
void MMStone3d::moveDown()
{
    this->positionY += this->particleSize;
    this->updateCube();
}
void MMStone3d::moveUp()
{
    this->positionY -= this->particleSize;
    this->updateCube();
}
void MMStone3d::moveRight()
{
    this->positionX += this->particleSize;
    this->updateCube();
}
void MMStone3d::moveLeft()
{
    this->positionX -= this->particleSize;
    this->updateCube();
}
void MMStone3d::updateVertices()
{
}