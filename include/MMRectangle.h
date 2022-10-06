#ifndef CLASS_MM_SQUARE
#define CLASS_MM_SQUARE

#include "MMGraphics.h"

#include <vector>

class MMRectangle : public MMGraphics{
    public:
        float posX, posY, width, height;

        MMRectangle(float posX, float posY, float width, float height);

        std::vector<float> getVertices();
        std::vector<unsigned int> getIndices();
        std::vector<float> getColor();
        int getIndCount();

    private:
        int indCount = 4;
        std::vector<float> vertices;
        std::vector<unsigned int> indices = {0, 1, 2, 1, 2, 3};
        std::vector<float> color;

        std::vector<float> mmCalculateVertices();

};


#endif