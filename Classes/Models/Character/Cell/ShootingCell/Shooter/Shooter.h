#ifndef __SHOOTER_H__
#define __SHOOTER_H__

#include "../../../CharacterModel.h"
#include "../Projectile/ProjectileModel.h"

class Shooter {
protected:
    ProjectileId projectileId;
public:
    Shooter(ProjectileId);
    virtual ~Shooter();
    virtual void shoot(CharacterModel* target);
};

#endif // !__SHOOTER_H__