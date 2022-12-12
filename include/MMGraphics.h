#ifndef CLASS_MM_GRAPHICS
#define CLASS_MM_GRAPHICS

#include <vector>

class MMGraphics
{

public:
    MMGraphics();
    void AddEntity(MMGraphics *entity);

private:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> color;
    int indCount;

public:
    virtual std::vector<float> GetColor();
    virtual std::vector<float> GetVertices();
    virtual std::vector<unsigned int> GetIndices();
    virtual int GetIndCount();
};

#endif