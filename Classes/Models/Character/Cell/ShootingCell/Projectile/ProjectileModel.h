#ifndef __PROJECTILE_MODEL_H__
#define __PROJECTILE_MODEL_H__

#include "ProjectileModelDefinitions.h"
class LevelModel;
class CharacterModel;
struct CellPosition;

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
    bool isDestroyed;
    virtual void effectOnHit(){};
public:
    static ProjectileModel* create(ProjectileId id, CharacterModel* source, CharacterModel* target);
    ProjectileModel(ProjectileId id, CharacterModel* source, CharacterModel* target);
    virtual void update();
    virtual float getPositionCellX();
    virtual float getPositionCellY();
    virtual CellPosition getPosition();
    virtual void hitTarget();
    virtual void __setLevel(LevelModel*);
};

#endif // !__PROJECTILE_MODEL_H__