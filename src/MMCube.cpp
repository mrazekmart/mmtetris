#include "MMCube.h"
const int SIZE = 800;

MMCube::MMCube(float _posX, float _posY, float _posZ, float _width, float _heigh, float _depth)
{
    this->posX = _posX;
    this->posY = _posY;
    this->posZ = _posZ;
    this->width = _width;
    this->height = _heigh;
    this->depth = _depth;
    this->color = {
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f,
        0.0f, 1.f, 0.02f};
}

std::vector<float> MMCube::mmCalculateVertices()
{
    std::vector<float> vertices;

    float x, y, z;

    x = this->posX < SIZE / 2 ? -(1 - (this->posX / (SIZE / 2))) : (this->posX - (SIZE / 2)) / (SIZE / 2);
    y = this->posY < SIZE / 2 ? (1 - (this->posY / (SIZE / 2))) : -(this->posY - (SIZE / 2)) / (SIZE / 2);
    z = this->posZ < SIZE / 2 ? -(1 - (this->posZ / (SIZE / 2))) : (this->posZ - (SIZE / 2)) / (SIZE / 2);

    // lef-top-front
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);

    float xBackUp = x;
    float yBackUp = y;
    float zBackUp = z;

    x += this->width / (SIZE / 2);
    y -= this->height / (SIZE / 2);
    z += this->depth / (SIZE / 2);

    // right-top-front
    vertices.push_back(x);
    vertices.push_back(yBackUp);
    vertices.push_back(zBackUp);

    // left-bottom-front
    vertices.push_back(xBackUp);
    vertices.push_back(y);
    vertices.push_back(zBackUp);

    // right-bottom-front
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(zBackUp);

    // left-top-back
    vertices.push_back(xBackUp);
    vertices.push_back(yBackUp);
    vertices.push_back(z);

    // right-top-back
    vertices.push_back(x);
    vertices.push_back(yBackUp);
    vertices.push_back(z);

    // left-bottom-back
    vertices.push_back(xBackUp);
    vertices.push_back(y);
    vertices.push_back(z);

    // right-bottom-back
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);

    return vertices;
}

std::vector<float> MMCube::getVertices()
{
    this->vertices.clear();
    return mmCalculateVertices();
}

std::vector<unsigned int> MMCube::getIndices()
{
    return this->indices;
}

std::vector<float> MMCube::getColor()
{
    return this->color;
}
int MMCube::getIndCount()
{
    return this->indCount;
}