#ifndef CLASS_MM_GRAPHICS_SINGLETON
#define CLASS_MM_GRAPHICS_SINGLETON

#include <vector>
#include "MMGraphics.h"

class MMGraphicsSingleton
{
public:
    static MMGraphicsSingleton &getInstance()
    {
        static MMGraphicsSingleton instance;
        return instance;
    }
    void addEntity(MMGraphics *entity);
    std::vector<float> getVerticesAll();
    std::vector<unsigned int> getIndicesAll();
    std::vector<float> getColorsAll();
    std::vector<float> verticesAll;
    std::vector<unsigned int> indicesAll;
    std::vector<float> colorsAll;

private:
    std::vector<MMGraphics *> *entities;
    int indicesCount = 0;

    MMGraphicsSingleton();
    MMGraphicsSingleton(MMGraphicsSingleton const &);
    void operator=(MMGraphicsSingleton const &);
};

#endif