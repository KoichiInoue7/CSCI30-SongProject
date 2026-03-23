#include <iostream>
#include <string>
#pragma once
class AudioBuffer{
private:
void *data;
int duration;
std::string title;


public:
AudioBuffer(int d, std::string t);
~AudioBuffer();

void play() const;
};
