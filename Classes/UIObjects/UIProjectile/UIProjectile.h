#ifndef __UI_PROJECTILE_H__
#define __UI_PROJECTILE_H__

#include "UIProjectileDefinitions.h"
#include "cocos2d.h"

class UIObjects;

class UIProjectile : public UIObjects {
public:
    static UIProjectile* create(ProjectileId);
    virtual void addToScene(cocos2d::Scene*);
};

#endif // !__UI_PROJECTILE_H__