#ifndef __PROJECTILE_MODEL_H__
#define __PROJECTILE_MODEL_H__

#include "../../../CharacterModel.h"
#include "ProjectileModelDefinitions.h"

class ProjectileModel {
protected:
    float cellX;
    float cellY;
    float targetX;
    float targetY;
    float speed;
    CharacterModel* target;
    ProjectileId id;
public:
    ProjectileModel(ProjectileId id, float cellX, float cellY, CharacterModel* target);
    virtual void update();
    virtual float getPositionCellX();
    virtual float getPositionCellY();
    virtual CellPosition getPosition();
};

#endif // !__PROJECTILE_MODEL_H__