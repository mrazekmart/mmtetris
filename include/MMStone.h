#ifndef CLASS_MM_STONE
#define CLASS_MM_STONE

#include "MMParticle.h"
#include "MMRectangle.h"
#include "MMParticleMatrix.h"

class MMStone : public MMParticle
{
public:
    MMStone(int posX, int posY, int particleSize);
    ~MMStone();
    MMRectangle *getRect();
    void update(MMParticleMatrix *particleMartix);
    int getMaterial();

private:
    int positionX, positionY, particleSize;
    int material = 5;
    MMRectangle *mmRectangle;
    void updateRectangle();
};

#endif