#ifndef __CELL_MODEL_H__
#define __CELL_MODEL_H__

class CharacterModel;
class LevelModel;
#include "CellModelDefinitions.h"

class CellModel : public CharacterModel {
protected:
    CellId id;
    int cost;
    double distance;
public:
    static CellModel* create(CellId id);
    CellModel(CellId id);
    virtual ~CellModel(){};

    // Return the distance 
    virtual double getDistance() {return distance;}
    virtual bool canPutOn(LevelModel* level, int cellX, int cellY){return false;}
    virtual void update();
};

#endif // !__CELL_MODEL_H__