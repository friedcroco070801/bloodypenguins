#ifndef __LEVEL_MODEL_H__
#define __LEVEL_MODEL_H__

#include <vector>
#include "LevelModelDefinitions.h"
#include "Models/Wave/WaveModel.h"

class LevelModel {
public:
    LevelModel(){};
    LevelModel(int level);

    // Return the map of the level
    std::vector< std::vector<MapPosition> > getMap() {return map;}

    // Return the list of waves
    std::vector<WaveModel> getWaveList() {return waveList;} 
private:
    std::vector< std::vector<MapPosition> > map;
    std::vector<WaveModel> waveList;
};

#endif // !__LEVEL_MODEL_H__