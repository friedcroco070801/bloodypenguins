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
		break;
	case DISEASE_01_SMALLPOX:
		return UIDisease01::create();
		break;
	case DISEASE_02_INFLUENZA:
		return UIDisease02::create();
		break;
	case DISEASE_03_MEASLES:
		return UIDisease03::create();
		break;
	case DISEASE_04_POLIO:
		return UIDisease04::create();
		break;
	case DISEASE_05_MALARIA:
		return UIDisease05::create();
		break;
	//case DISEASE_06_EBOLA:
		//return UIDisease06::create();
		//break;
    }

    return nullptr;
}