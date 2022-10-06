#ifndef CLASS_MM_CUBE
#define CLASS_MM_CUBE

#include "MMGraphics.h"
#include <vector>

class MMCube : public MMGraphics{
    public:
        float posX, posY, posZ, width, height, depth;

        MMCube(float posX, float posY, float posZ, float width, float height, float depth);

        std::vector<float> getVertices();
        std::vector<unsigned int> getIndices();
        std::vector<float> getColor();
        int getIndCount();

    private:
        int indCount = 8;
        std::vector<float> vertices;
        std::vector<unsigned int> indices = 
        {
            0, 1, 2,
            1, 2, 3,
            0, 4, 2,
            4, 6, 2,
            4, 5, 6,
            5, 7, 6,
            5, 1, 7,
            1, 7, 3, 
            2, 6, 3,
            6, 3, 7,
            0, 4, 1,
            5, 1, 4
        };

        std::vector<float> color;
        std::vector<float> mmCalculateVertices();

};


#endif