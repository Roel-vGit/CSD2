#include "FmSynth.h"

FmSynth::FmSynth() : FmSynth(100, 1.0, 0, 10, 1.0)
{

}

FmSynth::FmSynth(float frequency, float amplitude, int waveform, float modRatio, float modAmount)
: Synth(frequency, amplitude)
{

    modulator = waveforms[waveform]; //set modulator waveform

    this->modRatio = modRatio; //set modulator frequency
    this->modAmount = modAmount; //set modulator amplitude (modulation depth)

    modulator->setFrequency(modRatio*frequency);
    modulator->setAmplitude(modAmount);
}

FmSynth::FmSynth(int note, float amplitude, int waveform, float modRatio, float modAmount)
: FmSynth(mtof(note), amplitude, waveform, modRatio, modAmount)
{

}

FmSynth::~FmSynth()
{

}

void FmSynth::tick()
{
    if (activeLFO) {
        modulator->setFrequency(frequency*(LFO->getSample()+1)); //Modulate the FM amount with the LFO

        LFO->tick();
    }

    if (activeEnv) {
        carrier.setAmplitude(amplitude * env.getLevel()); //Multiply envelope with amplitude
    }
    
    //modulate frequency of carrier with modulator
    carrier.setFrequency(frequency*(modulator->getSample()+1)); //modulate frequency of carrier with modulator
    
    carrier.tick();
    modulator->tick();
}

float FmSynth::getSample()
{
    sample = carrier.getSample();
    return sample;
}

void FmSynth::calculatePitch()
{
    //empty function because we made this abstract in the base class. 
    //It only needs to be implementend by SuperSynth
}