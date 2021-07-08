#ifndef __UI_CONTROL_CELLBAR_H__
#define __UI_CONTROL_CELLBAR_H__

#include "cocos2d.h"
#include "UIControlCellBarDefinitions.h"
#include "../UIControl.h"
#include "Models/models.h"

class UIControlCellBar : public UIControl {
public:
	virtual void addToScene(cocos2d::Scene* scene);
	virtual void onTouch();
	void touchControlEvent(Ref *sender, ui::Widget::TouchEventType type); 
	static UIControlCellBar* create();

};

#endif // !__UI_CONTROL_CELLBAR_H__