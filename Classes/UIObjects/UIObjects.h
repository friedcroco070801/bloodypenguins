#ifndef __UI_OBJECTS_H__
#define __UI_OBJECTS_H__

#include "cocos2d.h"
#include "UIObjectsDefinitions.h"

class UIObjects : public cocos2d::Sprite {
public:
    virtual void setCellPosition(double, double);
    virtual void addToScene(cocos2d::Scene*);
    virtual void removeFromScene();
};

#endif // !__UI_OBJECTS_H__