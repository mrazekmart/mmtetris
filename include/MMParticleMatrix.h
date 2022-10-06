#ifndef CLASS_MM_PARTICLE_MATRIX
#define CLASS_MM_PARTICLE_MATRIX

#include<vector>

class MMParticle;

class MMParticleMatrix{
    private:
        std::vector<MMParticle*> *matrix;
        int width;
        int height;
    public:
        MMParticleMatrix(int _width, int _height);
        ~MMParticleMatrix();

        MMParticle* get(int x, int y);

        void setElementAtIndex(int x, int y, MMParticle* element);

};

#endif