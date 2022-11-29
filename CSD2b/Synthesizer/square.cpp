#include "square.h"

#include <cmath>

Square::Square() : Oscillator(1000, 1.0, 0, 48000)
{

}

Square::Square(float frequency, float amplitude, float phase, float samplerate) : Oscillator(frequency, amplitude, phase, samplerate)
{

}

Square::Square(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
    phase = 0;
    samplerate = 48000;
}

Square::~Square()
{

}

float Square::process()
{
    phase += frequency / samplerate;

    if(phase > 1.0f)
    {
        phase -= 1.0f;
    }

    if(phase < 0.5)
    {
        sample = amplitude;
    } else {
        sample = amplitude*-1.0f;
    }
    return sample;
}