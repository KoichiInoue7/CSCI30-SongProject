#include <iostream>
#include "AudioStream.h"
#include <string>
#pragma once

class Podcast: public AudioStream{
private:
int episodeNumber;
std::string guest;

public:
Podcast(std::string t, std::string a, int d, int eN, std::string g);

~Podcast();

int getEpisodeNumber()const;

std::string getGuest()const;

void play() const;



};