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
MMCube *MMSand3d::getCube()
{
    this->updateCube();
    return this->mmCube;
}
bool MMSand3d::getSkipUpdate()
{
    return this->skipUpdate;
}
int MMSand3d::getMaterial(){
    return this->material;
}
void MMSand3d::updateCube()
{
    this->mmCube->posX = this->positionX;
    this->mmCube->posY = this->positionY;
}
void MMSand3d::update(MMParticleMatrix *particleMatrix)
{

    if (this->skipUpdate)
        return;
	if (0 < this->matPosX < 800/particleSize - 20 && 0 < this->matPosY < 800/particleSize - 20) {
		int r = rand() % 2;
        MMParticle* nextParticle = particleMatrix->get(this->matPosX, this->matPosY + 1);
        if (nextParticle == nullptr)
        {
            particleMatrix->setElementAtIndex(this->matPosX, this->matPosY + 1, this);
            particleMatrix->setElementAtIndex(this->matPosX, this->matPosY, nullptr);
            this->positionY += this->particleSize;
            this->matPosY += 1;
        }
        else
        {
            if(nextParticle->getMaterial() == 1 || nextParticle->getMaterial() == 5){
                bool left = particleMatrix->get(this->matPosX - 1, this->matPosY + 1) == nullptr;
                bool right = particleMatrix->get(this->matPosX + 1, this->matPosY + 1) == nullptr;

                if(left || right){
                    if(left && right){
                        int side = rand() % 2;
                        if (side == 1) {
                            particleMatrix->setElementAtIndex(this->matPosX - 1, this->matPosY + 1, this);
                            particleMatrix->setElementAtIndex(this->matPosX, this->matPosY, nullptr);
                            this->positionX -= this->particleSize;
                            this->positionY += this->particleSize;
                            this->matPosX -= 1;
                            this->matPosY += 1;
                        }
                        else {
                            particleMatrix->setElementAtIndex(this->matPosX + 1, this->matPosY + 1, this);
                            particleMatrix->setElementAtIndex(this->matPosX, this->matPosY, nullptr);
                            this->positionX += this->particleSize;
                            this->positionY += this->particleSize;
                            this->matPosX += 1;
                            this->matPosY += 1;
                        }
                    }else if(left){
                        particleMatrix->setElementAtIndex(this->matPosX - 1, this->matPosY + 1, this);
                        particleMatrix->setElementAtIndex(this->matPosX, this->matPosY, nullptr);
                        this->positionX -= this->particleSize;
                        this->positionY += this->particleSize;
                        this->matPosX -= 1;
                        this->matPosY += 1;
                    }else if(right){
                        particleMatrix->setElementAtIndex(this->matPosX + 1, this->matPosY + 1, this);
                        particleMatrix->setElementAtIndex(this->matPosX, this->matPosY, nullptr);
                        this->positionX += this->particleSize;
                        this->positionY += this->particleSize;
                        this->matPosX += 1;
                        this->matPosY += 1;
                    }
                }
                else{
                    this->skipUpdate = true;
                }
            }
        }
    }
    this->updateCube();


    //rewrite this
    std::vector<float> newVertices = this->getCube()->getVertices();
    for (int i = 0; i < newVertices.size(); i++)
    {
        MMGraphicsSingleton::getInstance().verticesAll[i + ((id-1) * 24)] = newVertices[i];
    }
    
}