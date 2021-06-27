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
Add a DiseaseModel to list of enemies
*/
void WaveModel::add(DiseaseModel* enemy) {
    enemies.push_back(enemy);
}