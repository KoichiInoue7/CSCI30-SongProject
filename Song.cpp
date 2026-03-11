#include "Song.h"
#include <iostream>

using namespace std;

Song::Song(string t, string a, int d, string aN) : AudioStream (t, a, d) 
{
    albumName = aN;
}

Song::~Song()
{
    //cout << "Destroying Song:" <<endl;
}

void Song::play () const
{ 
    cout << "Now playing Song: " << getTitle() 
    << " by " << getArtist() << " from the album " 
    << getAlbumName() << ".\n";
}
 

 string Song:: getAlbumName() const
{
    return albumName;
}
