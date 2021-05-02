//collaborated with Jason Guan

#include <iostream>
#include "Playlist.h"
using namespace std;

void PrintMenu(string title);

int main()
{   
    cout << "Enter playlist's title:" << endl;
    string name;
    getline(cin, name);
    cout << endl;
    PrintMenu(name);
    return 0;
}

void PrintMenu(string title)
{
    PlaylistNode *head = nullptr;
    PlaylistNode *tail = nullptr;
    char option;
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:";
    cin >> option;
    cout << endl;
    bool test = false;
    while(option != 'q')
    {
    if(option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o')
    {
    test = true;
    } 
    while(test == false && option != 'q')
    {
        cout << "Choose an option: " << endl;
        cin >> option;

    if(option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o')
    {
    test = true;
    }
    }

    if(test == true)
    {

    if(option == 'a')
    {
    string unique;
    string sName;
    string aName;
    int sLength;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> unique;
    cout << "Enter song's name:" << endl;
    cin.ignore();
    getline(cin, sName);
    cout << "Enter artist's name:" << endl;
    getline(cin, aName);
    cout << "Enter song's length (in seconds):" << endl;
    cout << endl;
    cin >> sLength;
    if(head == nullptr){
        head = new PlaylistNode(unique, sName, aName, sLength);
        tail = head;
    } else {
        PlaylistNode *temp = new PlaylistNode(unique, sName, aName, sLength);
        tail->InsertAfter(temp);
        tail = temp;
    }
    }
    
    else if(option == 'd')
    {
    string unique;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> unique;
    if (head == nullptr)
    {
        cout << "empty list"  << endl << endl;
       
    } else {
        PlaylistNode *temp = head;
        PlaylistNode *tailcheck = nullptr;
        PlaylistNode *asd = nullptr;
        if(temp->GetID() == unique)
        {
            PlaylistNode *abc = temp->GetNext();
            cout << "\"" << temp->GetSongName() << "\" removed." << endl;
            delete temp;
            head = abc;
        } else if(tail->GetID() == unique){
            while(temp != nullptr){
                if(temp->GetNext() == tail){
                    tailcheck = temp;
                }
                temp = temp->GetNext();
            }
            cout << "\"" << tail->GetSongName() << "\" removed." << endl;
            delete tail;
            tail = tailcheck;
            tail->SetNext(asd);
            
        } else { 
            while(temp != nullptr && temp->GetNext() != nullptr){
                PlaylistNode *next = temp->GetNext();
                if(next->GetID() == unique){
                    PlaylistNode *check = next->GetNext();
                    temp->SetNext(check);
                    cout << "\"" << next->GetSongName() << "\" removed." << endl;
                    cout << endl;
                    delete next;
                }
                temp = temp->GetNext();
            }
        }
    }
    }

    else if(option == 'c')
    {
       int currP;
       int newP;
       cout << "CHANGE POSITION OF SONG" << endl;
       cout << "Enter song's current position:" << endl;
       cin >> currP;
       cout << "Enter new position for song:" << endl;
       cin >> newP;
       int counter = 1;
       PlaylistNode *hold = head;
       PlaylistNode *curr = nullptr;
       PlaylistNode *next1 = nullptr;
       PlaylistNode *curr2 = nullptr;
       PlaylistNode *next2 = nullptr;
       PlaylistNode *nullptrholder = nullptr;
       PlaylistNode *prev1 = nullptr;
       PlaylistNode *prev2 = nullptr;

     while(hold != nullptr)
       {
           if(counter+1 == newP){
               prev1 = hold;
           }
           if(counter == newP){
               curr2 = hold;
               next2 = hold->GetNext();
           }
           if(counter == currP){
               next1 = hold->GetNext();
               curr = hold;
           }
           if(counter+1 == currP){
               prev2 = hold;
           }
           counter++;
           hold = hold->GetNext();
       }
       counter--;

        if(newP == 1){
            curr->SetNext(curr2);
            prev2->SetNext(next1);
            head = curr;
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
    }else if(currP == counter){
            prev1->InsertAfter(curr);
            curr->SetNext(curr2);
            tail = next2;
            next2->SetNext(nullptrholder);
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
    }else if(currP == 1){
            if(newP == counter){
            head = next1;
            tail->InsertAfter(curr);
            tail = curr;
            curr->SetNext(nullptrholder);
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
            } else {
            head = next1;
            curr2->SetNext(curr);
            curr->SetNext(next2);
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
            }
    }else if(newP == counter){
            prev2->SetNext(next1);
            curr2->InsertAfter(curr);
            curr->SetNext(nullptrholder);
            tail = curr;
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
    }else if(currP > newP) {
            prev1->SetNext(curr);
            curr->SetNext(curr2);
            curr2->SetNext(next1);
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
    }else if(currP < newP){
            prev2->SetNext(next1);
            next1->SetNext(curr2);
            curr2->SetNext(curr);
            curr->SetNext(next2);
            cout << "\"" << curr->GetSongName() << "\" " << "moved to position " << newP << endl << endl;
    }
    
    }
    else if(option == 's')
    {
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl << endl;
        cin.ignore();
        string name;
        getline(cin, name);
        PlaylistNode *temp = head;
        int counter = 1;
        while(temp != nullptr){
            if(temp->GetArtistName() == name){
                cout << counter << "." << endl;
                cout << "Unique ID: " << temp->GetID() << endl;
                cout << "Song Name: " << temp->GetSongName() << endl;
                cout << "Artist Name: " << temp->GetArtistName() << endl;
                cout << "Song Length (in seconds): " << temp->GetSongLength() << endl;
                cout << endl;
            }
            temp = temp->GetNext();
            counter++;
        }

    }

    else if(option == 't')
    {
       cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
       int sum = 0;
       PlaylistNode *temp = head;
       while(temp != nullptr){
           sum += temp->GetSongLength();
           temp = temp->GetNext();
       }
       cout << "Total time: " << sum << " seconds" << endl << endl;
    }

    else if(option == 'o')
    {
        cout << title << " - OUTPUT FULL PLAYLIST" << endl;
        if(head == nullptr)
        {
            cout << "Playlist is empty" << endl << endl;
        } 
        else 
        {
        PlaylistNode *temp = head;
        int counter = 1;
         while(temp != nullptr)
        {
            cout << counter << "." << endl;
            temp->PrintPlaylistNode();
            temp = temp->GetNext();
            cout << endl;
            counter++;
        }
        }
       
    }
    else if (option == 'q')
    {
        return;
    }
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:";
    cin >> option;
    cout << endl;


    }

    
}
}

