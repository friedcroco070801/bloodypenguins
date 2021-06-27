#include "WaveModel.h"

/*
WaveModel destructor
*/
WaveModel::~WaveModel() {
    for (auto it = enemies.begin(); it != enemies.end(); it++) {
        delete (*it);
    }
}

/*
Return if the wave is a huge wave
*/
bool WaveModel::isHugeWave() {
    return hugeWave;
}

/*
Set if the wave is a huge wave
*/
void WaveModel::setHugeWave(bool _hugeWave) {
    hugeWave = _hugeWave;
}

/*
Add a DiseaseModel to list of enemies
*/
void WaveModel::add(DiseaseModel* enemy) {
    enemies.push_back(enemy);
}