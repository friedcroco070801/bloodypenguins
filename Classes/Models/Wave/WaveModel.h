#ifndef __WAVE_MODEL_H__
#define __WAVE_MODEL_H__

#include <vector>
#include "../Chacracter/Disease/DiseaseModel.h"

class WaveModel {
public:
    WaveModel(){};
    ~WaveModel();
    bool isHugeWave() {return hugeWave;}
    void add(DiseaseModel*);
private:
    bool hugeWave;
    std::vector<DiseaseModel*> enemies;
};

#endif // !__WAVE_MODEL_H__