#ifndef CLASS_MM_STONE_3D
#define CLASS_MM_STONE_3D

#include "MMParticle.h"
#include "MMCube.h"
#include "MMParticleMatrix.h"

class MMStone3d : public MMParticle
{
public:
    MMStone3d(int posX, int posY, int posZ, int particleSize);
    ~MMStone3d();
    MMCube *GetCube();
    int GetMaterial();
    void Update(MMParticleMatrix *particleMartix);
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void UpdateVertices();
    int positionX, positionY, positionZ, particleSize;

private:
    int material = 5;
    MMCube *mmCube;
    void UpdateCube();
};

#endif