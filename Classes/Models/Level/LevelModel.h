#ifndef __LEVEL_MODEL_H__
#define __LEVEL_MODEL_H__

#include <vector>
#include <list>
#include "LevelModelDefinitions.h"
#include "cocos2d.h"

class CharacterModel;
class WaveModel;
class CellModel;
class DiseaseModel;
class ProjectileModel;

class LevelModel {
public:
    // Default constructor of LevelModel
    LevelModel(){};
    LevelModel(int level, cocos2d::Scene* scene);
    ~LevelModel();

    // Return the map of the level
    std::vector< std::vector<MapPosition> > getMap() {return map;}

    // Return the list of waves
    std::vector<WaveModel> getWaveList() {return waveList;}

    // Reset the timeCounter to 0 and start to count
    void startCounting() {
        timeCounter = 0.0;
        isCounting = true;
    }

    // Return current time counter value
    double getTimeCounter() {
        return timeCounter;
    }

    void update();
    void addCell(CellModel*, int, int);
    void addDisease(DiseaseModel*);
    void addProjectile(ProjectileModel*);
    void dumpCell(CellModel*);
    void dumpDisease(DiseaseModel*);
    void dumpProjectile(ProjectileModel*);
    void printLevelState();

    // Get diseaseList of the level. Should not be used outside Models.
    std::list<DiseaseModel*>& __getDiseaseList() {return diseaseList;}

    // Get cellList of the level. Should not be used outside Models.
    std::list<CellModel*>& __getCellList() {return cellList;}
    std::vector< std::vector<int> >* __getEnemyPath();
private:
    std::vector< std::vector<MapPosition> > map;
    std::vector< std::vector< std::vector<int> > > enemyPaths;
    std::vector<WaveModel> waveList;
    std::vector<WaveModel>::iterator currentWave;
    std::list<CellModel*> cellList;
    std::list<DiseaseModel*> diseaseList;
    std::list<ProjectileModel*> projectileList;

    double timeCounter;
    bool isCounting;
    int energy;

    std::list<CellModel*> cellDump;
    std::list<DiseaseModel*> diseaseDump;
    std::list<ProjectileModel*> projectileDump;
    void garbageCollect();
    void addEnemiesOnWave();

    cocos2d::Scene* scene;
};

#endif // !__LEVEL_MODEL_H__