#ifndef __LEVEL_MODEL_H__
#define __LEVEL_MODEL_H__

#include <vector>
#include "LevelModelDefinitions.h"

class LevelModel {
public:
    LevelModel(){};
    LevelModel(int level);
    std::vector< std::vector<MapPosition> > getMap() {return map;} 
private:
    std::vector< std::vector<MapPosition> > map;
};

#endif // !__LEVEL_MODEL_H__