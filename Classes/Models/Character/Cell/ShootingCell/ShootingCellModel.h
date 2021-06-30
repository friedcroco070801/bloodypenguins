#ifndef __SHOOTING_CELL_MODEL_H__
#define __SHOOTING_CELL_MODEL_H__

#include "../CellModel.h"
#include "Projectile/ProjectileModel.h"
#include "Shooter/Shooter.h"

class ShootingCellModel : public CellModel, public Shooter {
protected:

public:
    ShootingCellModel(LevelModel* level, CellId cellId);
    virtual ~ShootingCellModel();
    virtual void shoot(CharacterModel* target);
    virtual void update();
};

#endif // !__SHOOTING_CELL_MODEL_H__