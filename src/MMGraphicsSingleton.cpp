#include "MMGraphicsSingleton.h"

MMGraphicsSingleton::MMGraphicsSingleton()
{
    this->entities = new std::vector<MMGraphics *>();
}

void MMGraphicsSingleton::addEntity(MMGraphics *entity)
{
    this->entities->push_back(entity);

    std::vector<float> gV = entity->GetVertices();

    this->verticesAll.insert(std::end(this->verticesAll), std::begin(gV), std::end(gV));

    std::vector<unsigned int> gI = entity->GetIndices();
    for (int ind : gI)
    {
        this->indicesAll.push_back(ind + this->indicesCount);
    }
    this->indicesCount += entity->GetIndCount();

    std::vector<float> gC = entity->GetColor();
    this->colorsAll.insert(std::end(this->colorsAll), std::begin(gC), std::end(gC));
}
std::vector<float> MMGraphicsSingleton::GetVerticesAll()
{
    return this->verticesAll;
}

std::vector<unsigned int> MMGraphicsSingleton::GetIndicesAll()
{
    return this->indicesAll;
}

std::vector<float> MMGraphicsSingleton::GetColorsAll()
{
    return this->colorsAll;
}