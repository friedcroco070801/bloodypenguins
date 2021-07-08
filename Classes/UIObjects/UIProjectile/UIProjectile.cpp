#include "UIObjects/uiobj.h"
#include "UIProjectile.h"
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
        UIProjectile *uiprojectile = new (std::nothrow) UIProjectile();
        if (uiprojectile && uiprojectile->initWithFile(CELL_00_PROJECTILE_FILENAME))
        {
            uiprojectile->autorelease();
            return uiprojectile;
        }
        CC_SAFE_DELETE(uiprojectile);
        return nullptr;
    }
    return nullptr;
}