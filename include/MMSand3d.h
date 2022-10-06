#ifndef CLASS_MM_SAND_3D
#define CLASS_MM_SAND_3D

#include "MMParticle.h"
#include "MMCube.h"
#include "MMParticleMatrix.h"
#include <cmath>

class MMSand3d : public MMParticle{
    public:
        MMSand3d(int posX, int posY, int posZ, int particleSize, int id);
        ~MMSand3d();
        MMCube* getCube();
        void update(MMParticleMatrix* particleMartix);
        bool getSkipUpdate();
        int getMaterial();

    private:
        int positionX, positionY, particleSize;
        int matPosX, matPosY;
        int id;
        int material = 1;
        bool skipUpdate = false;
        MMCube* mmCube;
        void updateCube();

};


#endif