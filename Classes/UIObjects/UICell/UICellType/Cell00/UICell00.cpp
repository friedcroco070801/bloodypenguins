#include "UIObjects/uiobj.h"
#include "UICell00.h"

/*
Create a new instance of UICell00
*/
UICell00* UICell00::create() {
    UICell00 *uicell = new (std::nothrow) UICell00();
    if (uicell && uicell->initWithFile(CELL_00_FILENAME))
    {
        uicell->autorelease();
        return uicell;
    }
    CC_SAFE_DELETE(uicell);
    return nullptr;
}