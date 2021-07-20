#ifndef __UI_CELL_06_H__
#define __UI_CELL_06_H__

class UICell;
class UICell06 : public UICell {
public:
	static UICell06* create();
	virtual void addToScene(cocos2d::Scene*);
	virtual void idleAnimate();
	virtual void effectAnimate();
	//virtual void hitAnimate();
	virtual void dieAnimate() {};
};
#endif // !__UI_CELL_05_H__L_H__