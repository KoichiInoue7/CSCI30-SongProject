#include <iostream>
#include "AudioStream.h"
#include <string>
#pragma once

class Song : public AudioStream{
private:
    std::string albumName;
public:
    Song(std::string t, std::string a, int d, std::string aN); 

    ~Song();

    void play() const;

    std::string getAlbumName() const;

};
