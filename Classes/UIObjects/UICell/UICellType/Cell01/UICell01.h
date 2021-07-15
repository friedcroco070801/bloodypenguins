#ifndef __UI_CELL_01_H__
#define __UI_CELL_01_H__

class UICell;
class UICell01 : public UICell {
public:
    static UICell01* create();
	virtual void addToScene(cocos2d::Scene*);
	virtual void idleAnimate();
	virtual void effectAnimate();
	virtual void hitAnimate();
	virtual void dieAnimate();
};

#endif // !__UI_CELL_01_H__