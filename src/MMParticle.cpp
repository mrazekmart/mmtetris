#include "MMParticle.h"

void MMParticle::Update(MMParticleMatrix *particleMatrix){};
int MMParticle::GetMaterial()
{
    return this->material;
}
bool MMParticle::GetSkipUpdate()
{
    return this->skipUpdate;
}
