#include "MMSand.h"
#include "MMGraphicsSingleton.h"

MMSand::MMSand(int posX, int posY, int particleSize, int id)
{
    this->positionX = posX;
    this->positionY = posY;
    this->particleSize = particleSize;
    this->matPosX = posX / particleSize;
    this->matPosY = posY / particleSize;
    this->mmRectangle = new MMRectangle(posX, posY, particleSize, particleSize);
    this->id = id;
}
MMSand::~MMSand()
{
    delete (this->mmRectangle);
}
MMRectangle *MMSand::GetRect()
{
    this->UpdateRectangle();
    return this->mmRectangle;
}
bool MMSand::GetSkipUpdate()
{
    return this->skipUpdate;
}
int MMSand::GetMaterial()
{
    return this->material;
}
void MMSand::UpdateRectangle()
{
    this->mmRectangle->posX = this->positionX;
    this->mmRectangle->posY = this->positionY;
}
void MMSand::Update(MMParticleMatrix *particleMatrix)
{

    if (this->skipUpdate)
        return;
    if (0 < this->matPosX < 800 / particleSize && 0 < this->matPosY < 800 / particleSize)
    {
        int r = rand() % 2;
        MMParticle *nextParticle = particleMatrix->Get(this->matPosX, this->matPosY + 1);
        if (nextParticle == nullptr)
        {
            particleMatrix->SetElementAtIndex(this->matPosX, this->matPosY + 1, this);
            particleMatrix->SetElementAtIndex(this->matPosX, this->matPosY, nullptr);
            this->positionY += this->particleSize;
            this->matPosY += 1;
        }
        else
        {
            if (nextParticle->GetMaterial() == 1 || nextParticle->GetMaterial() == 5)
            {
                bool left = particleMatrix->Get(this->matPosX - 1, this->matPosY + 1) == nullptr;
                bool right = particleMatrix->Get(this->matPosX + 1, this->matPosY + 1) == nullptr;

                if (left || right)
                {
                    if (left && right)
                    {
                        int side = rand() % 2;
                        if (side == 1)
                        {
                            particleMatrix->SetElementAtIndex(this->matPosX - 1, this->matPosY + 1, this);
                            particleMatrix->SetElementAtIndex(this->matPosX, this->matPosY, nullptr);
                            this->positionX -= this->particleSize;
                            this->positionY += this->particleSize;
                            this->matPosX -= 1;
                            this->matPosY += 1;
                        }
                        else
                        {
                            particleMatrix->SetElementAtIndex(this->matPosX + 1, this->matPosY + 1, this);
                            particleMatrix->SetElementAtIndex(this->matPosX, this->matPosY, nullptr);
                            this->positionX += this->particleSize;
                            this->positionY += this->particleSize;
                            this->matPosX += 1;
                            this->matPosY += 1;
                        }
                    }
                    else if (left)
                    {
                        particleMatrix->SetElementAtIndex(this->matPosX - 1, this->matPosY + 1, this);
                        particleMatrix->SetElementAtIndex(this->matPosX, this->matPosY, nullptr);
                        this->positionX -= this->particleSize;
                        this->positionY += this->particleSize;
                        this->matPosX -= 1;
                        this->matPosY += 1;
                    }
                    else if (right)
                    {
                        particleMatrix->SetElementAtIndex(this->matPosX + 1, this->matPosY + 1, this);
                        particleMatrix->SetElementAtIndex(this->matPosX, this->matPosY, nullptr);
                        this->positionX += this->particleSize;
                        this->positionY += this->particleSize;
                        this->matPosX += 1;
                        this->matPosY += 1;
                    }
                }
                else
                {
                    this->skipUpdate = true;
                }
            }
        }
    }
    this->UpdateRectangle();

    std::vector<float> newVertices = this->GetRect()->GetVertices();
    for (int i = 0; i < newVertices.size(); i++)
    {
        MMGraphicsSingleton::getInstance().verticesAll[i + ((id - 1) * 12)] = newVertices[i];
    }
}