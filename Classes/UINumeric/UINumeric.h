#ifndef __UI_NUMERIC_H__
#define __UI_NUMERIC_H__

#include "cocos2d.h"
#include "UINumericDefinitions.h"
#include "../Models/models.h"


class UINumeric : public cocos2d::Sprite {
public:
	virtual void addToScene(cocos2d::Scene* scene);
    virtual void setPosition(double, double);
    virtual void removeFromScene();
	virtual void changeValue(int);

private:
	LevelModel *level;
};

#endif // !__UI_NUMERIC_H__