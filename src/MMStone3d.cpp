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
MMCube *MMStone3d::GetCube()
{
    this->UpdateCube();
    return this->mmCube;
}
int MMStone3d::GetMaterial()
{
    return this->material;
}
void MMStone3d::UpdateCube()
{
    this->mmCube->posX = this->positionX;
    this->mmCube->posY = this->positionY;
    this->mmCube->posZ = this->positionZ;
}
void MMStone3d::Update(MMParticleMatrix *particleMatrix)
{
    this->UpdateCube();
}
void MMStone3d::MoveDown()
{
    this->positionY += this->particleSize;
    this->UpdateCube();
}
void MMStone3d::MoveUp()
{
    this->positionY -= this->particleSize;
    this->UpdateCube();
}
void MMStone3d::MoveRight()
{
    this->positionX += this->particleSize;
    this->UpdateCube();
}
void MMStone3d::MoveLeft()
{
    this->positionX -= this->particleSize;
    this->UpdateCube();
}
void MMStone3d::UpdateVertices()
{
}