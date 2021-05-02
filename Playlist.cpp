//collaborated with Jason Guan

#include <iostream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode()
{
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string ID, string songN, string artistN, int songL)
{
    uniqueID = ID;
    songName = songN;
    artistName = artistN;
    songLength = songL;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode *abc)
{
    PlaylistNode *temp = this->nextNodePtr;
    this->nextNodePtr = abc;
    abc->nextNodePtr = temp;

}

string PlaylistNode::GetArtistName() const
{
    return artistName;
}

void PlaylistNode::SetNext(PlaylistNode *def)
{
    this->nextNodePtr = def;
}


string PlaylistNode::GetID() const
{
    return uniqueID;
}

string PlaylistNode::GetSongName() const
{
    return songName;
}

int PlaylistNode::GetSongLength() const
{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const
{
    return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

