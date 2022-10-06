#include "MMStone.h"

MMStone::MMStone(int posX, int posY, int particleSize)
{
    this->positionX = posX;
    this->positionY = posY;
    this->particleSize = particleSize;
    this->mmRectangle = new MMRectangle(posX, posY, particleSize, particleSize);
}
MMStone::~MMStone()
{
    delete (this->mmRectangle);
}
MMRectangle *MMStone::getRect()
{
    this->updateRectangle();
    return this->mmRectangle;
}
int MMStone::getMaterial()
{
    return this->material;
}
void MMStone::updateRectangle()
{
    this->mmRectangle->posX = this->positionX;
    this->mmRectangle->posY = this->positionY;
}
void MMStone::update(MMParticleMatrix *particleMatrix)
{
    this->updateRectangle();
}