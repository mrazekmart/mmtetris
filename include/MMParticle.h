#ifndef CLASS_MM_PARTICLE
#define CLASS_MM_PARTICLE

#include "MMParticleMatrix.h"
#include "MMGraphics.h"

class MMParticle
{
public:
    int positionX, positionY;
    int material;
    bool skipUpdate = false;

public:
    virtual bool GetSkipUpdate();
    virtual int GetMaterial();
    virtual void Update(MMParticleMatrix *particleMatrix);
};

#endif