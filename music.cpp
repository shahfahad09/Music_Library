#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Playlist {
private:
    string name;
    vector<string> songs;
    vector<string> recentlyPlayed;
    string lastPlayed;

public:
    Playlist(const string& playlistName) : name(playlistName) {}

    void add() {
        string song;
        cout << "Enter the name of the song to add: ";
        cin.ignore();
        getline(cin, song);
        songs.push_back(song);
        cout << "Song added: " << song << "\n";
    }

    void remove() {
        string song;
        cout << "Enter the name of the song to delete: ";
        cin.ignore();
        getline(cin, song);
        auto it = find(songs.begin(), songs.end(), song);
        if (it != songs.end()) {
            songs.erase(it);
            cout << "Song deleted: " << song << "\n";
        } else {
            cout << "Song not found!\n";
        }
    }

    void display() {
        cout << "Current Playlist (" << name << "):\n";
        if (songs.empty()) {
            cout << "No songs in the playlist.\n";
        } else {
            for (const auto& song : songs) {
                cout << " - " << song << "\n";
            }
        }
    }

    void total() {
        cout << "Total number of songs in " << name << ": " << songs.size() << "\n";
    }

    void search() {
        string song;
        cout << "Enter the name of the song to search: ";
        cin.ignore();
        getline(cin, song);
        if (find(songs.begin(), songs.end(), song) != songs.end()) {
            cout << "Song found: " << song << "\n";
        } else {
            cout << "Song not found!\n";
        }
    }

    void play() {
        string song;
        cout << "Enter the name of the song to play: ";
        cin.ignore();
        getline(cin, song);
        if (find(songs.begin(), songs.end(), song) != songs.end()) {
            lastPlayed = song;
            recentlyPlayed.push_back(song);
            cout << "Now playing: " << song << "\n";
        } else {
            cout << "Song not found!\n";
        }
    }

    void recentlyPlayedList() {
        cout << "Recently Played Songs:\n";
        if (recentlyPlayed.empty()) {
            cout << "No songs have been played yet.\n";
        } else {
            for (const auto& song : recentlyPlayed) {
                cout << " - " << song << "\n";
            }
        }
    }

    void lastPlayedSong() {
        if (!lastPlayed.empty()) {
            cout << "Last Played Song: " << lastPlayed << "\n";
        } else {
            cout << "No song has been played yet.\n";
        }
    }

    void sorted() {
        vector<string> sortedSongs = songs;
        sort(sortedSongs.begin(), sortedSongs.end());
        cout << "Sorted Playlist:\n";
        for (const auto& song : sortedSongs) {
            cout << " - " << song << "\n";
        }
    }

    void addFromFile() {
        string filename;
        cout << "Enter the filename to read songs from: ";
        cin >> filename;
        ifstream file(filename);
        if (file.is_open()) {
            string song;
            while (getline(file, song)) {
                songs.push_back(song);
            }
            file.close();
            cout << "Songs added from " << filename << "\n";
        } else {
            cout << "Could not open file.\n";
        }
    }
};

int main() {
    string playlistName;
    cout << "Enter your playlist name: ";
    getline(cin, playlistName);
    Playlist playlist(playlistName);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add New Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Entered Playlist\n";
        cout << "4. Total Songs\n";
        cout << "5. Search Song\n";
        cout << "6. Play Song\n";
        cout << "7. Recently Played List\n";
        cout << "8. Last Played\n";
        cout << "9. Sorted Playlist\n";
        cout << "10. Add From File\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: playlist.add(); break;
            case 2: playlist.remove(); break;
            case 3: playlist.display(); break;
            case 4: playlist.total(); break;
            case 5: playlist.search(); break;
            case 6: playlist.play(); break;
            case 7: playlist.recentlyPlayedList(); break;
            case 8: playlist.lastPlayedSong(); break;
            case 9: playlist.sorted(); break;
            case 10: playlist.addFromFile(); break;
            case 11: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
    } while (choice != 11);

    return 0;
}
