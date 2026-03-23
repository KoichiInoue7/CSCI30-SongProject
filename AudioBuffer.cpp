#include "AudioBuffer.h"
#include "supportFunctions.h"
#include <iostream>
using namespace std;

AudioBuffer::AudioBuffer(int d, string t)
{
    duration = d;
    title = t;
    data = loadAudioResource(d, t);
}

AudioBuffer::~AudioBuffer()
{
    if(data != nullptr)
    {
        freeAudioResource(data);
    }
}


void AudioBuffer::play() const
{
    playAudioResource(data);
}