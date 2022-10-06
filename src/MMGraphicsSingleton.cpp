#include "MMGraphicsSingleton.h"

MMGraphicsSingleton::MMGraphicsSingleton(){
        this->entities = new std::vector<MMGraphics *>();
}

void MMGraphicsSingleton::addEntity(MMGraphics *entity)
{
    this->entities->push_back(entity);

    std::vector<float> gV = entity->getVertices();

    this->verticesAll.insert(std::end(this->verticesAll), std::begin(gV), std::end(gV));
    
    std::vector<unsigned int> gI = entity->getIndices();
    for (int ind : gI)
    {
        this->indicesAll.push_back(ind + this->indicesCount);
    }
    this->indicesCount += entity->getIndCount();
    
    std::vector<float> gC = entity->getColor();
    this->colorsAll.insert(std::end(this->colorsAll), std::begin(gC), std::end(gC));
}
std::vector<float> MMGraphicsSingleton::getVerticesAll()
{
    return this->verticesAll;
}

std::vector<unsigned int> MMGraphicsSingleton::getIndicesAll()
{
    return this->indicesAll;
}

std::vector<float> MMGraphicsSingleton::getColorsAll()
{
    return this->colorsAll;
}