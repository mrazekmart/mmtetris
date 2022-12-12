#include "MMParticleMatrix.h"
#include <iostream>

MMParticleMatrix::MMParticleMatrix(int _width, int _height)
{
	this->width = _width;
	this->height = _height;
	this->matrix = new std::vector<MMParticle *>(_width * _height);
}

MMParticleMatrix::~MMParticleMatrix()
{
	if (this->matrix)
	{
		delete (this->matrix);
	}
}
MMParticle *MMParticleMatrix::Get(int x, int y)
{
	return (*this->matrix)[x + y * width];
}

void MMParticleMatrix::SetElementAtIndex(int x, int y, MMParticle *element)
{
	(*this->matrix)[x + y * width] = element;
}