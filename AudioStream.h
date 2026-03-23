#include <iostream>
#include "AudioBuffer.h"
#include <string>
#pragma once

class AudioStream
{
private:
std::string title;
std::string artist;
int duration;

protected:
void *buffer;
AudioBuffer m_buff;


public:
AudioStream(std::string t, std::string a, int d);

virtual ~AudioStream();

//setter functions
void setTitle(std::string t);

void setArtist(std::string a);

void setDuration (int d);


//getter functions
void print() const;

std::string getTitle() const;

std::string getArtist() const;

virtual void play() const = 0;


};