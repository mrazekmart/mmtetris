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
MMRectangle *MMStone::GetRect()
{
    this->UpdateRectangle();
    return this->mmRectangle;
}
int MMStone::GetMaterial()
{
    return this->material;
}
void MMStone::UpdateRectangle()
{
    this->mmRectangle->posX = this->positionX;
    this->mmRectangle->posY = this->positionY;
}
void MMStone::Update(MMParticleMatrix *particleMatrix)
{
    this->UpdateRectangle();
}