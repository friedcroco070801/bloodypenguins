#ifndef __UI_CONTROL_ENERGY_H__
#define __UI_CONTROL_ENERGY_H__

#include "cocos2d.h"
#include "UIControlEnergyDefinitions.h"
#include "../UIControl.h"
#include "Scenes/GameScene/GSDefine.h"
#include "ui/CocosGUI.h"
class LevelModel;

using namespace cocos2d;

class UIControlEnergy : public UIControl {
public:
	virtual void addToScene(cocos2d::Scene* scene);
    virtual void removeFromScene();
	virtual void setCellPosition(double, double);
	static UIControlEnergy* create(LevelModel*);

	void touchControlEvent(Ref *sender, ui::Widget::TouchEventType type);
	virtual void onTouch();
	void idleAnimate();
	void destroyAnimate();
private:
	LevelModel* level;
};

#endif // !__UI_CONTROL_ENERGY_H__