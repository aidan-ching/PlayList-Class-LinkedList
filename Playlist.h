//collaborated with Jason Guan

#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include <string>
using namespace std;

class PlaylistNode {
    public:
    PlaylistNode();
    PlaylistNode(string ID, string songN, string artistN, int songL);
    void InsertAfter(PlaylistNode *abc);
    void SetNext(PlaylistNode *def);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode() const;

    private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode *nextNodePtr;
};

#endif