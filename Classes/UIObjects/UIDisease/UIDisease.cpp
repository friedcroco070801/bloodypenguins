#include "UIObjects/uiobj.h"
#include "UIDisease.h"
USING_NS_CC;

/*
Add UIDisease to scene
*/
void UIDisease::addToScene(Scene* scene) {
    scene->addChild(this, DISEASE_LAYER_ZORDER);
}

/*
Create a new instance of UIDisease with DiseaseId
*/
UIDisease* UIDisease::create(DiseaseId id) {
    switch (id) {
    // Case id 00: Rabies
    case DISEASE_00_RABIES:
        UIDisease *uidisease = new (std::nothrow) UIDisease();
        if (uidisease && uidisease->initWithFile(DISEASE_00_FILENAME))
        {
            uidisease->autorelease();
            return uidisease;
        }
        CC_SAFE_DELETE(uidisease);
        return nullptr;
    }
    return nullptr;
}