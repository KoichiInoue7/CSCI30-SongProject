#include "Song.h"
#include "supportFunctions.h"
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
    << " by " << getArtist() << " [Album: " 
    << getAlbumName() << "]\n";
    m_buff.play();
}


 string Song:: getAlbumName() const
{
    return albumName;
}
