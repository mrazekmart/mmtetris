#ifndef CLASS_MM_SAND
#define CLASS_MM_SAND

#include "MMParticle.h"
#include "MMRectangle.h"
#include "MMParticleMatrix.h"
#include <cmath>

class MMSand : public MMParticle
{
public:
    MMSand(int posX, int posY, int particleSize, int id);
    ~MMSand();
    MMRectangle *getRect();
    void update(MMParticleMatrix *particleMartix);
    bool getSkipUpdate();
    int getMaterial();

private:
    int positionX, positionY, particleSize;
    int matPosX, matPosY;
    int id;
    int material = 1;
    bool skipUpdate = false;
    MMRectangle *mmRectangle;
    void updateRectangle();
};

#endif