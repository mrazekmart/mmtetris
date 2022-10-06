#include "MMParticle.h"

void MMParticle::update(MMParticleMatrix* particleMatrix) {
};
int MMParticle::getMaterial(){
    return this->material;
}
bool MMParticle::getSkipUpdate(){
    return this->skipUpdate;
}
