#include <iostream>
#include "AudioStream.h"
#include <string>
#pragma once

class Playlist{
private:
AudioStream *m_list[100];

int m_count;

public:
Playlist();
~Playlist();
void addStream(AudioStream *s);
void playAll();

void swapSongs(int index1, int index2);
void showPlaylist();
};