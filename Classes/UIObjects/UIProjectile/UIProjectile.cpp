#include "UIObjects/uiobj.h"
#include "UIProjectile.h"
#include "ProjectileType/UIProjectileType.h"
USING_NS_CC;

/*
Add UIProjectile to scene
*/
void UIProjectile::addToScene(Scene* scene) {
    scene->addChild(this, PROJECTILE_LAYER_ZORDER);
}

/*
Create a new instance of UIProjectile with ProjectileId
*/
UIProjectile* UIProjectile::create(ProjectileId id) {
    switch (id) {
    // Case id 00: Rabies
    case CELL_00_PROJECTILE:
        return UICell00Projectile::create();
    }
    return nullptr;
}

/*
Destroy animation
*/
void UIProjectile::destroyAnimate() {
    removeFromParent();
}