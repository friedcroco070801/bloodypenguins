#ifndef __UI_DISEASE_H__
#define __UI_DISEASE_H__

#include "UIDiseaseDefinitions.h"
#include "cocos2d.h"

class UIObjects;

class UIDisease : public UIObjects {
public:
    static UIDisease* create(DiseaseId);
    virtual void addToScene(cocos2d::Scene*);
};

#endif // !__UI_DISEASE_H__