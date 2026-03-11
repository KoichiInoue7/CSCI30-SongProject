#include <iostream>
#include <string>
#include "Playlist.h"
using namespace std;


Playlist ::Playlist()
{
    m_count = 0;
    for (int i = 0; i < 100; i ++)
    {
        m_list[i] = nullptr;
    }
}

Playlist:: ~Playlist()
{
    for (int i= 0; i < m_count ; i++)
    {
       // cout << "Deleting from playlist";
        delete m_list[i];
    }
}

void Playlist ::addStream(AudioStream *s)
{
    m_list[m_count] = s;
    m_count++;
}


void Playlist :: playAll()
{
    cout << "--- Playing Your Playlist ---" << endl;

    
    for (int i = 0; i < m_count; i++)
    {
        m_list[i]->play();
    }
    
}


void Playlist :: swapSongs(int index1, int index2)
{
    AudioStream *temp = m_list[index1];
    m_list[index1] = m_list[index2];
    m_list[index2] = temp;
}

void Playlist ::showPlaylist()
{

    cout << "---  Listing Your Playlist ---" <<endl;
    for (int i = 0; i < m_count; i++)
    {
        cout << i << ":";
        m_list[i]->print();
    }
}
