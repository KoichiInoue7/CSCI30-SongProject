#include "Podcast.h"

#include <iostream>

using namespace std;

Podcast::Podcast(string t, string a, int d, int eN, string g): AudioStream(t, a, d)
{
    episodeNumber = eN;
    guest = g;
}

Podcast::~Podcast()
{
   // cout << "Destroying Podcast" <<endl;
}

int Podcast::getEpisodeNumber() const
{
    return episodeNumber;
}

string Podcast::getGuest() const
{
    return guest;
}

void Podcast::play() const
{
    cout << "Now playing Podcast: " << getTitle() << " Episode #" 
    << getEpisodeNumber() << " ,featuring " 
    << getGuest() << "." <<endl;
}