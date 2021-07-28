#ifndef __UI_REMOVE_H__
#define __UI_REMOVE_H__

#include "UIControl/UIControl.h"
#define REMOVE_BUTTON_FILENAME "sprites/objects/button/remove.png"
#define REMOVE_BUTTON_CLICKED_FILENAME "sprites/objects/button/remove_clicked.png"
#define REMOVE_BUTTON_POS_X Director::getInstance()->getVisibleSize().width - 85.0f + Director::getInstance()->getVisibleOrigin().x
#define REMOVE_BUTTON_POS_Y Director::getInstance()->getVisibleSize().height - 30.0f + Director::getInstance()->getVisibleOrigin().y

class LevelModel;

class UIRemove : public UIControl {
public:
    static UIRemove* create(LevelModel*);

private:
	virtual void onTouch();
    LevelModel* level;
};

#endif // !__UI_REMOVE_H__