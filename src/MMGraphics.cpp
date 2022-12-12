#include "MMGraphics.h"
MMGraphics::MMGraphics()
{
}
std::vector<float> MMGraphics::GetVertices()
{
    return this->vertices;
}
std::vector<unsigned int> MMGraphics::GetIndices()
{
    return this->indices;
}
std::vector<float> MMGraphics::GetColor()
{
    return this->color;
}
int MMGraphics::GetIndCount()
{
    return this->indCount;
}