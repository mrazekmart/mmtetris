#include "MMSand3d.h"
#include "MMGraphicsSingleton.h"

MMSand3d::MMSand3d(int posX, int posY, int posZ, int particleSize, int id)
{
    this->positionX = posX;
    this->positionY = posY;
    this->particleSize = particleSize;
    this->matPosX = posX / particleSize;
    this->matPosY = posY / particleSize;
    this->mmCube = new MMCube(posX, posY, posZ, particleSize, particleSize, particleSize);
    this->id = id;
}
MMSand3d::~MMSand3d()
{
    delete (this->mmCube);
}
MMCube *MMSand3d::GetCube()
{
    this->UpdateCube();
    return this->mmCube;
}
bool MMSand3d::GetSkipUpdate()
{
    return this->skipUpdate;
}
int MMSand3d::GetMaterial()
{
    return this->material;
}
void MMSand3d::UpdateCube()
{
    this->mmCube->posX = this->positionX;
    this->mmCube->posY = this->positionY;
}
void MMSand3d::Update(MMParticleMatrix *particleMatrix)
{

    if (this->skipUpdate)
        return;
    if (0 < this->matPosX < 800 / particleSize - 20 && 0 < this->matPosY < 800 / particleSize - 20)
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
    this->UpdateCube();

    // rewrite this
    std::vector<float> newVertices = this->GetCube()->GetVertices();
    for (int i = 0; i < newVertices.size(); i++)
    {
        MMGraphicsSingleton::getInstance().verticesAll[i + ((id - 1) * 24)] = newVertices[i];
    }
}