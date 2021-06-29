#ifndef __PROJECTILE_MODEL_H__
#define __PROJECTILE_MODEL_H__

#include "../../../CharacterModel.h"
#include "ProjectileModelDefinitions.h"

class ProjectileModel {
protected:
    LevelModel* level;
    ProjectileId id;
    float cellX;
    float cellY;
    float directionVectorX;
    float directionVectorY;
    float targetX;
    float targetY;
    float speed;
    float damage;
    CharacterModel* target;
    virtual void effectOnHit();
public:
    ProjectileModel(LevelModel* level, ProjectileId id, CharacterModel* source, CharacterModel* target);
    virtual void update();
    virtual float getPositionCellX();
    virtual float getPositionCellY();
    virtual CellPosition getPosition();
    virtual void hitTarget();
};

#endif // !__PROJECTILE_MODEL_H__