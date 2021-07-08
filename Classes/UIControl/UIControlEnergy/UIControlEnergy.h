#ifndef __UI_CONTROL_ENERGY_H__
#define __UI_CONTROL_ENERGY_H__

#include "cocos2d.h"
#include "UIControlEnergyDefinitions.h"
#include "../UIControl.h"
#include "Scenes/GameScene/GSDefine.h"
#include "ui/CocosGUI.h"


using namespace cocos2d;

class UIControlEnergy : public UIControl {
public:
	virtual void addToScene(cocos2d::Scene* scene);
    virtual void removeFromScene();
	virtual void setCellPosition(double, double);
	static UIControlEnergy* create();

	void touchControlEvent(Ref *sender, ui::Widget::TouchEventType type);
	virtual void onTouch();
	void idleAnimate();
	void destroyAnimate();
};

#endif // !__UI_CONTROL_ENERGY_H__