#ifndef __SHOOTING_CELL_MODEL_H__
#define __SHOOTING_CELL_MODEL_H__

#include "../../CharacterModel.h"
#include "Projectile/ProjectileModel.h"

class ShootingCellModel {
protected:
    ProjectileId projectileId;
public:
    ShootingCellModel();
    virtual ~ShootingCellModel();
    virtual void shoot(CharacterModel* source, CharacterModel* target);
};

#endif // !__SHOOTING_CELL_MODEL_H__