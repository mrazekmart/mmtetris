#include "MMGraphics.h"
MMGraphics::MMGraphics()
{
}
std::vector<float> MMGraphics::getVertices()
{
    return this->vertices;
}
std::vector<unsigned int> MMGraphics::getIndices()
{
    return this->indices;
}
std::vector<float> MMGraphics::getColor()
{
    return this->color;
}
int MMGraphics::getIndCount()
{
    return this->indCount;
}