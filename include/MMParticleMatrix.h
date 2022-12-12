#ifndef CLASS_MM_PARTICLE_MATRIX
#define CLASS_MM_PARTICLE_MATRIX

#include <vector>

class MMParticle;

class MMParticleMatrix
{
private:
    std::vector<MMParticle *> *matrix;
    int width;
    int height;

public:
    MMParticleMatrix(int _width, int _height);
    ~MMParticleMatrix();

    MMParticle *Get(int x, int y);

    void SetElementAtIndex(int x, int y, MMParticle *element);
};

#endif