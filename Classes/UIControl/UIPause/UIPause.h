#ifndef __UI_PAUSE_H__
#define __UI_PAUSE_H__

#include "../UIControl.h"
#define PAUSE_BUTTON_FILENAME "sprites/objects/button/pause.png"
#define PAUSE_BUTTON_CLICKED_FILENAME "sprites/objects/button/pause_clicked.png"
#define PAUSE_BUTTON_POS_X Director::getInstance()->getVisibleSize().width - 30.0f + Director::getInstance()->getVisibleOrigin().x
#define PAUSE_BUTTON_POS_Y Director::getInstance()->getVisibleSize().height - 30.0f + Director::getInstance()->getVisibleOrigin().y

class LevelModel;

class UIPause : public UIControl {
public:
    static UIPause* create(LevelModel*);

private:
	void touchControlEvent(Ref *sender, ui::Widget::TouchEventType type);
	virtual void onTouch();
    LevelModel* level;
};

#endif // !__UI_PAUSE_H__