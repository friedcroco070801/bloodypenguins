#ifndef __LEVELBUTTON_H__
#define __LEVELBUTTON_H__
#include "cocos2d.h"
#include "Models/models.h"
#include "ui/CocosGUI.h"

#define PAUSE_BUTTON_FILENAME "sprites/objects/button/pause.png"
#define PAUSE_BUTTON_CLICKED_FILENAME "sprites/objects/button/pause_clicked.png"
USING_NS_CC;
class levelButton :public ui::Button
{
public:
	static levelButton* create(int number);
private:
	void touchControlEvent(Ref *sender, ui::Widget::TouchEventType type);
	virtual void onTouch();
	int level;
};

#endif // !__LEVELBUTTON_H__