#ifndef __DISEASE_MODEL_H__
#define __DISEASE_MODEL_H__

#include "../CharacterModel.h"
#include "DiseaseModelDefinitions.h"
#include "../Cell/CellModel.h"
#include <vector>

class DiseaseModel : public CharacterModel {
protected:
    DiseaseId id;
    DiseaseAction action;
    Direction dir;
    float speed;
    int damage;
    float hitRechargeTime;
    std::vector< std::vector<int> >* path;
    std::vector< std::vector<int> >::iterator currentPath;
    std::vector< std::vector<int> >::iterator nextPath;
    virtual void changeDirectionOnPath();
    virtual void changeDirectionToTarget(CellModel*);
public:
    DiseaseModel(LevelModel*, DiseaseId);
    virtual ~DiseaseModel();
    virtual void update();
    virtual void hitTarget(CellModel* target);
};

#endif // !__DISEASE_MODEL_H__