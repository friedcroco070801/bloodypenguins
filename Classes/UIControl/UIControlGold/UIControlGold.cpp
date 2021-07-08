#include "UIControlGold.h"
#include "Scenes/GameScene/GSDefine.h"

USING_NS_CC;

/*
Add to Scene
*/
void UIControlGold::addToScene(Scene* scene) {
	scene->addChild(this, GOLD_LAYER_ZORDER);
}

/*
Remove from Scene
*/
void UIControlGold::removeFromScene() {
	removeFromParent();
}

void UIControlGold::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		CCLOG("Touch");
		break;
	case ui::Widget::TouchEventType::ENDED:
		CCLOG("Energy update");
		//update gold
		removeFromScene();
		break;
	default:
		break;
	}
};
