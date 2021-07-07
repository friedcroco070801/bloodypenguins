#include "Models/models.h"
#include "LevelModel.h"
#include <random>
#include <ctime>
#include <cmath>
#include <iostream>
#include "UIObjects/uiobj.h"
using namespace std;
USING_NS_CC;

/*
Constructor of LevelModel
*/
LevelModel::LevelModel(int level, Scene* scene) {
    srand(time(NULL));
    this->scene = scene;

    // Temporary data
    energy.changeValue(400);
    gold.changeValue(400);

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

    int p1[] = {6, 4, 6, 3, 6, 2, 6, 1, 5, 1, 4, 1, 3, 1, 2, 1, 1, 1, 0, 1};
    int p2[] = {7, 3, 6, 3, 5, 3, 4, 3, 3, 3, 2, 3, 1, 3, 0, 3};
    vector< vector<int> > temp1;
    vector< vector<int> > temp2;
    for (int i = 0; i < sizeof(p1) / sizeof(int); i += 2) {
        vector<int> t;
        t.push_back(p1[i]);
        t.push_back(p1[i + 1]);
        temp1.push_back(t);
    }
    enemyPaths.push_back(temp1);
    for (int i = 0; i < sizeof(p2) / sizeof(int); i += 2) {
        vector<int> t;
        t.push_back(p2[i]);
        t.push_back(p2[i + 1]);
        temp2.push_back(t);
    }
    enemyPaths.push_back(temp2);

    WaveModel wave1;
    waveList.push_back(wave1);
    waveList[0].add(DISEASE_00_RABIES);
    waveList[0].setTime(5.0);
    WaveModel wave2;
    waveList.push_back(wave2);
    waveList[1].add(DISEASE_00_RABIES);
    waveList[1].setTime(10.0);
    WaveModel wave3;
    waveList.push_back(wave3);
    waveList[2].add(DISEASE_00_RABIES);
    waveList[2].setTime(15.0);

    currentWave = waveList.begin();

    cellBarList.push_back(CellBarModel(CELL_00_EOSINOPHILS));
    cellBarList.push_back(CellBarModel(CELL_01_ERYTHROCYTES));

    // Initialize properties
    timeCounter = 0.0;
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
        for (auto it = cellList.begin(); it != cellList.end();) {
            (*(it++))->update();
        }
        for (auto it = diseaseList.begin(); it != diseaseList.end();) {
            (*(it++))->update();
        }
        for (auto it = projectileList.begin(); it != projectileList.end();) {
            (*(it++))->update();
        }
        for (auto it = cellBarList.begin(); it != cellBarList.end();) {
            (*(it++)).update();
        }

        // Garbage collect
        garbageCollect();

        // Add enemies on current wave
        if (currentWave != waveList.end()) {
            if (abs(timeCounter - currentWave->getTime()) <= ACCEPTING_TIME_ERROR) {
                addEnemiesOnWave();
            }
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
            auto cellX = (int) obj->getPositionCellX();
            auto cellY = (int) obj->getPositionCellY();
            map[cellX][cellY] = (MapPosition) ((EMPTY_CAN_PUT - EMPTY_CAN_PUT_OCCUPIED) + (int) map[cellX][cellY]);
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
void LevelModel::addCell(CellModel* obj, int cellX, int cellY) {
    if (obj->getCost() > energy.getValue()) {
        delete obj;
        return;
    }
    if (obj->canPutOn(this, cellX, cellY)) {
        obj->setPosition(cellX, cellY);
        cellList.push_back(obj);
        obj->__setLevel(this);
        map[cellX][cellY] = (MapPosition) ((EMPTY_CAN_PUT_OCCUPIED - EMPTY_CAN_PUT) + (int) map[cellX][cellY]);

        // Draw UIObject on scene
        auto ui = UICell::create(obj->getCellId());
        obj->setUIObject(ui);
        ui->addToScene(this->scene);
        ui->setCellPosition(cellX, cellY);

        // Change value of energy
        addEnergyValue(0 - obj->getCost());
    }
    else {
        delete obj;
    }
}
/*
Add a DiseaseModel to diseaseList
*/
void LevelModel::addDisease(DiseaseModel* obj) {
    diseaseList.push_back(obj);
    obj->__setLevel(this);

    // Draw UIObject on scene
    auto ui = UIDisease::create(obj->getDiseaseId());
    obj->setUIObject(ui);
    ui->addToScene(this->scene);
    ui->setCellPosition(obj->getPositionCellX(), obj->getPositionCellY());
}

/*
Add a ProjectileModel to projectileList
*/
void LevelModel::addProjectile(ProjectileModel* obj) {
    projectileList.push_back(obj);
    obj->__setLevel(this);

    // Draw UIObject on scene
    auto ui = UIProjectile::create(obj->getProjectileId());
    obj->setUIObject(ui);
    ui->addToScene(this->scene);
    ui->setCellPosition(obj->getPositionCellX(), obj->getPositionCellY());
}

/*
Add enemies in the current wave
*/
void LevelModel::addEnemiesOnWave() {
    auto enemies = currentWave->getEnemies();
    for (auto it = enemies.begin(); it != enemies.end(); it++) {
        addDisease(DiseaseModel::create(*it));
    }
    currentWave++;
}

/*
Print the current state of the level
*/
void LevelModel::printLevelState() {
    cout << "================= TIME: " << timeCounter << endl;
    for (auto it = cellList.begin(); it != cellList.end(); it++) {
        cout << "==== CELL\n";
        cout << "X: " << (*it)->getPositionCellX() << endl;
        cout << "Y: " << (*it)->getPositionCellY() << endl;
    }
    for (auto it = diseaseList.begin(); it != diseaseList.end(); it++) {
        cout << "==== DISEASE\n";
        cout << "X: " << (*it)->getPositionCellX() << endl;
        cout << "Y: " << (*it)->getPositionCellY() << endl;
    }
    for (auto it = projectileList.begin(); it != projectileList.end(); it++) {
        cout << "==== PROJECTILE\n";
        cout << "X: " << (*it)->getPositionCellX() << endl;
        cout << "Y: " << (*it)->getPositionCellY() << endl;
    }
    cout << "================================================\n\n";
}

/*
Add a energy to scene
*/
void LevelModel::addEnergyObject(double cellX, double cellY) {
    if (scene != NULL) {
        // Add to scene a energy at (cellX, cellY)
    }
}

/* 
Add more to the value of energy model
*/
void LevelModel::addEnergyValue(int add) {
    energy.changeValue(energy.getValue() + add);
}

/* 
Add more to the value of gold model
*/
void LevelModel::addGoldValue(int add) {
    gold.changeValue(gold.getValue() + add);
}