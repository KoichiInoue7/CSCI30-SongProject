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

void addSong(std::string title, std::string artist, int duration, std::string album);
void addPodcast(std::string title, std::string artist, int duration, int episodeNumber, std::string guest);

void swapSongs(int index1, int index2);
void showPlaylist();
};