#include "UIObjects/uiobj.h"
#include "UICell01.h"

/*
Create a new instance of UICell00
*/
UICell01* UICell01::create() {
    UICell01 *uicell = new (std::nothrow) UICell01();
    if (uicell && uicell->initWithFile(CELL_01_FILENAME))
    {
        uicell->autorelease();
        return uicell;
    }
    CC_SAFE_DELETE(uicell);
    return nullptr;
}