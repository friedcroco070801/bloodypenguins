#include "LevelModel.h"
using namespace std;

/*
Constructor of LevelModel
*/
LevelModel::LevelModel(int level) {
    int arr[10][5] = {
        {0, 2, 0, 2, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0}
    };
    map = vector< vector<MapPosition> >();
    for (int i = 0; i < 8; i++) {
        vector<MapPosition> temp;
        for (int j = 0; j < 5; j++) {
            temp.push_back((MapPosition) arr[i][j]);
        }
        map.push_back(temp);
    }

    // Initialize properties
    timeCounter = 0.0f;
    isCounting = false;
}

/*
Update state of level on updating
*/
void LevelModel::update() {
    if (this->isCounting) {
        // Update timeCounter
        timeCounter += UPDATING_FREQUENCY;

        // Update objects
        for (auto it = cellList.begin(); it != cellList.end(); it++) {
            (*it)->update();
        }
        for (auto it = diseaseList.begin(); it != diseaseList.end(); it++) {
            (*it)->update();
        }
        for (auto it = projectileList.begin(); it != projectileList.end(); it++) {
            (*it)->update();
        }
    }
}

/* 
Destructor of LevelModel
*/
LevelModel::~LevelModel() {
    for (auto it = cellList.begin(); it != cellList.end(); it++) {
        delete (*it);
    }
    for (auto it = diseaseList.begin(); it != diseaseList.end(); it++) {
        delete (*it);
    }
    for (auto it = projectileList.begin(); it != projectileList.end(); it++) {
        delete (*it);
    }
}

/* 
Collect garbage after each updating
*/
void LevelModel::garbageCollect() {
    for (auto it = cellDump.begin(); it != cellDump.end(); it++) {
        delete (*it);
    }
    cellDump.clear();
    for (auto it = diseaseDump.begin(); it != diseaseDump.end(); it++) {
        delete (*it);
    }
    diseaseDump.clear();
    for (auto it = projectileDump.begin(); it != projectileDump.end(); it++) {
        delete (*it);
    }
    projectileDump.clear();
}

/*
Send a CellModel to dump list
*/
void LevelModel::dumpCell(CellModel* obj) {
    for (auto it = cellList.begin(); it != cellList.end(); it++) {
        if (*it == obj) {
            cellList.erase(it);
            cellDump.push_back(obj);
            break;
        }
    }
}

/*
Send a DiseaseModel to dump list
*/
void LevelModel::dumpDisease(DiseaseModel* obj) {
    for (auto it = diseaseList.begin(); it != diseaseList.end(); it++) {
        if (*it == obj) {
            diseaseList.erase(it);
            diseaseDump.push_back(obj);
            break;
        }
    }
}

/*
Send a ProjectileModel to dump list
*/
void LevelModel::dumpProjectile(ProjectileModel* obj) {
    for (auto it = projectileList.begin(); it != projectileList.end(); it++) {
        if (*it == obj) {
            projectileList.erase(it);
            projectileDump.push_back(obj);
            break;
        }
    }
}