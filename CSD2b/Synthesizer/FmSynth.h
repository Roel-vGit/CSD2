#pragma once

#include "synth.h"

class FmSynth : public Synth {
    public:
        FmSynth();
        FmSynth(float frequency, float amplitude, std::string waveform, float modFrequency, float modAmount);
        ~FmSynth();
    
    void tick();
    float getSample();

    void setLFO(std::string waveform, float freqLFO, float depthLFO);


    protected:
        Sine carrier = Sine(frequency, amplitude);
        Oscillator* modulator;
        Oscillator* waveforms[3] = {new Sine, new AntiAliasedSquare, new AntiAliasedSaw};
        Oscillator* LFO;
        Oscillator* LFOwave[3] = {new Sine, new AntiAliasedSquare, new AntiAliasedSaw};
        float modFrequency;
        float modAmount;
        bool activeLFO = false;
};