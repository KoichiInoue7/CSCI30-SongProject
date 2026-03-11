#include "AudioStream.h"
#include <iostream>
using namespace std;

AudioStream::AudioStream(string t,string a,int d)
{
    title = t;
    artist = a;
    duration = d;
}


AudioStream::~AudioStream()
{
   // cout << "Destorying AudioStream" << endl;
}

void AudioStream::setTitle(string t)
{
    title = t;
}


void AudioStream::setArtist(string a)
{
    artist = a;
}


void AudioStream::setDuration(int d)
{
    duration = d;
}


void AudioStream:: print() const
{
    cout << "The stream " << title << " is " 
    << duration << " seconds, performed by " 
    << artist << " .\n";
}

string AudioStream:: getTitle() const
{
    return title;
}



string AudioStream:: getArtist() const
{
    return artist;
}




