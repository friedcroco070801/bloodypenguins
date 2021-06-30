#include "LevelModel.h"
#include <random>
#include <ctime>
using namespace std;

/*
Constructor of LevelModel
*/
LevelModel::LevelModel(int level) {
    srand(time(NULL));

    // Temporary data
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
Get a enemy path of the level randomly. Should not be used outside Models.
*/
vector< vector<int> >* LevelModel::__getEnemyPath() {
    int index = rand() % enemyPaths.size();
    return &enemyPaths[index];
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
    for (auto it = cellDump.begin(); it != cellDump.end(); it++) {
        delete (*it);
    }
    for (auto it = diseaseDump.begin(); it != diseaseDump.end(); it++) {
        delete (*it);
    }
    for (auto it = projectileDump.begin(); it != projectileDump.end(); it++) {
        delete (*it);
    }
}

/* 
Collect garbage after each updating
*/
void LevelModel::garbageCollect() {
    if (cellDump.size() >= DUMP_CAPACITY) {
        auto it = cellDump.begin();
        for (int i = 0; i < cellDump.size() / 2; i++, it++) {
            delete (*it);
        }
        cellDump.erase(cellDump.begin(), it);
    }

    if (diseaseDump.size() >= DUMP_CAPACITY) {
        auto it = diseaseDump.begin();
        for (int i = 0; i < diseaseDump.size() / 2; i++, it++) {
            delete (*it);
        }
        diseaseDump.erase(diseaseDump.begin(), it);
    }

    if (projectileDump.size() >= DUMP_CAPACITY) {
        auto it = projectileDump.begin();
        for (int i = 0; i < projectileDump.size() / 2; i++, it++) {
            delete (*it);
        }
        projectileDump.erase(projectileDump.begin(), it);
    }
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

/*
Add a CellModel to cellList
*/
void LevelModel::addCell(CellModel* obj) {
    cellList.push_back(obj);
    obj->__setLevel(this);
}
/*
Add a DiseaseModel to diseaseList
*/
void LevelModel::addDisease(DiseaseModel* obj) {
    diseaseList.push_back(obj);
    obj->__setLevel(this);
}

/*
Add a ProjectileModel to projectileList
*/
void LevelModel::addProjectile(ProjectileModel* obj) {
    projectileList.push_back(obj);
    obj->__setLevel(this);
}