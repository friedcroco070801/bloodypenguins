#ifndef __DISEASE_06_MODEL_H__
#define __DISEASE_06_MODEL_H__

class DiseaseModel;

class Disease06Model : public DiseaseModel {
public:
    Disease06Model();
    virtual ~Disease06Model(){}
    virtual void hitTarget(CellModel* target);
    virtual void update();
protected:
    double distance;
    double waitingUntilNextMove;
};

#endif // !__DISEASE_06_MODEL_H__