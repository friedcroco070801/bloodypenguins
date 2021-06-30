#ifndef __SHOOTER_H__
#define __SHOOTER_H__

#include "../../../CharacterModel.h"
#include "../Projectile/ProjectileModel.h"

class Shooter {
protected:
    ProjectileId projectileId;
    float shootRechargeTime;
public:
    Shooter();
    virtual ~Shooter(){};
    virtual void shoot(CharacterModel* target){};

    // Set projectile Id
    virtual void setProjectileId(ProjectileId id) {
        projectileId = id;
    }
};

#endif // !__SHOOTER_H__