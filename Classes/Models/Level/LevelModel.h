#ifndef __LEVEL_MODEL_H__
#define __LEVEL_MODEL_H__

#include <vector>
#include "LevelModelDefinitions.h"
#include "Models/Wave/WaveModel.h"
#include "../Character/Cell/CellModel.h"
#include "../Character/Disease/DiseaseModel.h"
#include "../Character/Cell/ShootingCell/Projectile/ProjectileModel.h"

class LevelModel {
public:
    // Default constructor of LevelModel
    LevelModel(){};
    LevelModel(int level);

    // Return the map of the level
    std::vector< std::vector<MapPosition> > getMap() {return map;}

    // Return the list of waves
    std::vector<WaveModel> getWaveList() {return waveList;}

    // Reset the timeCounter to 0 and start to count
    void startCounting() {
        timeCounter = 0.0f;
        isCounting = true;
    }

    void update();
    void dumpCell(CellModel*);
    void dumpDisease(DiseaseModel*);
    void dumpProjectile(ProjectileModel*);

    // Get diseaseList of the level. Should not be used outside Models.
    std::vector<DiseaseModel*>& __getDiseaseList() {return diseaseList;}
private:
    std::vector< std::vector<MapPosition> > map;
    std::vector<WaveModel> waveList;
    std::vector<CellModel*> cellList;
    std::vector<DiseaseModel*> diseaseList;
    std::vector<ProjectileModel*> projectileList;
    float timeCounter;
    bool isCounting;

    std::vector<CellModel*> cellDump;
    std::vector<DiseaseModel*> diseaseDump;
    std::vector<ProjectileModel*> projectileDump;
    void garbageCollect();
};

#endif // !__LEVEL_MODEL_H__