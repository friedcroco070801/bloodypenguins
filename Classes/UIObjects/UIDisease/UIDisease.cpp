#include "UIObjects/uiobj.h"
#include "UIDisease.h"
#include "UIDiseaseType/UIDiseaseType.h"
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
        return UIDisease00::create();
    }
    return nullptr;
}