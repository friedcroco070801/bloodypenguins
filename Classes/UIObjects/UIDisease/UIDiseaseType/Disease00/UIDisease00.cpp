#include "UIObjects/uiobj.h"
#include "UIDisease00.h"

/*
Create new instance of UIDisease00
*/
UIDisease00* UIDisease00::create() {
    UIDisease00 *uidisease = new (std::nothrow) UIDisease00();
    if (uidisease && uidisease->initWithFile(DISEASE_00_FILENAME))
    {
        uidisease->autorelease();
        return uidisease;
    }
    CC_SAFE_DELETE(uidisease);
    return nullptr;
}