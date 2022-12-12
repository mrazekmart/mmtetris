#include "MMRectangle.h"

const int SIZE = 800;

MMRectangle::MMRectangle(float _posX, float _posY, float _width, float _heigh)
{
    this->posX = _posX;
    this->posY = _posY;
    this->width = _width;
    this->height = _heigh;
    this->color = {
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f};
}

std::vector<float> MMRectangle::MmCalculateVertices()
{
    std::vector<float> vertices;

    float x, y;

    x = this->posX < SIZE / 2 ? -(1 - (this->posX / (SIZE / 2))) : (this->posX - (SIZE / 2)) / (SIZE / 2);
    y = this->posY < SIZE / 2 ? (1 - (this->posY / (SIZE / 2))) : -(this->posY - (SIZE / 2)) / (SIZE / 2);

    // lef-top
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(0.f);

    float xBackUp = x;
    x += this->width / (SIZE / 2);

    // right-top
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(0.f);

    y -= this->height / (SIZE / 2);

    // left-bottom
    vertices.push_back(xBackUp);
    vertices.push_back(y);
    vertices.push_back(0.f);

    // right-bottom
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(0.f);

    return vertices;
}

std::vector<float> MMRectangle::GetVertices()
{
    this->vertices.clear();
    return MmCalculateVertices();
}

std::vector<unsigned int> MMRectangle::GetIndices()
{
    return this->indices;
}

std::vector<float> MMRectangle::GetColor()
{
    return this->color;
}
int MMRectangle::GetIndCount()
{
    return this->indCount;
}