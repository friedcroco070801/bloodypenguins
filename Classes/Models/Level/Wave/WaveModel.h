#ifndef __WAVE_MODEL_H__
#define __WAVE_MODEL_H__

class WaveModel {
public:
    WaveModel();
    bool isHugeWave() {return hugeWave;}
private:
    bool hugeWave;
};

#endif // !__WAVE_MODEL_H__