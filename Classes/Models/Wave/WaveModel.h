#ifndef __WAVE_MODEL_H__
#define __WAVE_MODEL_H__

#include <vector>
enum DiseaseId;

class WaveModel {
public:
    // Constructor of waveModel
    WaveModel(){
        hugeWave = false;
    }
    ~WaveModel();
    bool isHugeWave();
    void setHugeWave(bool);
    void add(DiseaseId);
    float getTime();
    void setTime(float time);
    std::vector<DiseaseId>& getEnemies();
private:
    float time;
    bool hugeWave;
    std::vector<DiseaseId> enemies;
};

#endif // !__WAVE_MODEL_H__