#include <iostream>
using namespace std;

class Node 
{
    public:
        string songName;
        Node *next;
    
        Node(string name) : songName(name), next(nullptr) {}
};


class CircularLinkedList 
{
    private:
        Node *tail; 
    
    public:
        CircularLinkedList() : tail(nullptr) {}


    void addSong(const string &songName) 
    {
        Node *newNode = new Node(songName);
        if (!tail) 
        {
            tail = newNode;
            tail->next = tail; 
        } else 
        {
            newNode->next = tail->next; 
            tail->next = newNode;       
            tail = newNode;            
        }
    }

    void removeSong(const string &songName) 
    {
        if (!tail) return; 

        Node *current = tail->next; 
        Node *prev = tail;

        do {
            if (current->songName == songName) 
            {
                if (current == tail) 
                {
           
                    if (current->next == current) 
                    {
                        delete current;
                        tail = nullptr;
                    } else 
                    {
                      
                        prev->next = current->next;
                        tail = prev;
                        delete current;
                    }
                } else 
                {
           
                    prev->next = current->next;
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
    }

   
    void playAllSongs() 
    {
        if (!tail) 
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *current = tail->next; 
        do {
            cout << "Playing: " << current->songName << endl;
            current = current->next;
        } while (current != tail->next);
    }

    
    void displayPlaylist() 
    {
        if (!tail) 
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *current = tail->next; 
        do {
            cout << current->songName << " -> ";
            current = current->next;
        } while (current != tail->next);
        cout << "(back to " << tail->next->songName << ")" << endl;
    }
};


int main() 
{
    CircularLinkedList playlist;


    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");

    cout << "Current Playlist: ";
    playlist.displayPlaylist();

   
    cout << "\nPlaying all songs:" << endl;
    playlist.playAllSongs();

    
    playlist.removeSong("Song 3");
    cout << "\nPlaylist after removing 'Song 3': ";
    playlist.displayPlaylist();


    cout << "\nPlaying all songs after removal:" << endl;
    playlist.playAllSongs();

    playlist.removeSong("Song 1");
    playlist.removeSong("Song 2");
    playlist.removeSong("Song 4");
    
   
    cout << "\nPlaylist after removing all songs: ";
    playlist.displayPlaylist();

    return 0;
}



