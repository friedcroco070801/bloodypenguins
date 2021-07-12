#include "UIObjects/uiobj.h"
#include "UICell00Projectile.h"

/*
Create new instance of UICell00Projectile
*/
UICell00Projectile* UICell00Projectile::create() {
    UICell00Projectile *uiprojectile = new (std::nothrow) UICell00Projectile();
    if (uiprojectile && uiprojectile->initWithFile(CELL_00_PROJECTILE_FILENAME))
    {
        uiprojectile->autorelease();
        return uiprojectile;
    }
    CC_SAFE_DELETE(uiprojectile);
    return nullptr;
}