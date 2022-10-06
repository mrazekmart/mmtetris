#ifndef CLASS_MM_GRAPHICS
#define CLASS_MM_GRAPHICS

#include <vector>

class MMGraphics
{

public:
    MMGraphics();
    void addEntity(MMGraphics *entity);
private:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> color;
    int indCount;

public:
    virtual std::vector<float> getColor();
    virtual std::vector<float> getVertices();
    virtual std::vector<unsigned int> getIndices();
    virtual int getIndCount();
};

#endif