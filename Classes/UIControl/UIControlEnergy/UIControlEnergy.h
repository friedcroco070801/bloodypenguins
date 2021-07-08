#ifndef __UI_CONTROL_ENERGY_H__
#define __UI_CONTROL_ENERGY_H__

#include "cocos2d.h"
#include "../UIControlDefinitions.h"
#include "UIControlEnergyDefinitions.h"
#include "../UIControl.h"
#include "../../Scenes/GameScene/GSDefine.h"

class UIControlEnergy : public UIControl {
public:
	virtual void addToScene(cocos2d::Scene* scene);
    virtual void removeFromScene();
	virtual void setCellPosition(double, double);

	void touchControlEvent(Ref *sender, ui::Widget::TouchEventType type);
	void idleAnimate();
	void destroyAnimate();

private:
	ui::Button *energyButton;
	void addButton();
};

#endif // !__UI_CONTROL_ENERGY_H__