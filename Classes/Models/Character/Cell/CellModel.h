#ifndef __CELL_MODEL_H__
#define __CELL_MODEL_H__

#include "../CharacterModel.h"
#include "CellModelDefinitions.h"
#include "../../Level/LevelModel.h"
#include "ShootingCell/ShootingCellModel.h"

class CellModel : public CharacterModel {
protected:
    CellId id;
    int cost;
    float distance;
public:
    static CellModel* create(CellId id);
    CellModel(CellId id);
    virtual ~CellModel(){};

    // Return the distance 
    virtual float getDistance() {return distance;}
    virtual bool canPutOn(LevelModel* level, int cellX, int cellY){};
    virtual void update();
};

#endif // !__CELL_MODEL_H__