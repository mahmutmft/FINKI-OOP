#include <iostream>
#include <cstring>

using namespace std;

void test(int k);

class TennisPlayer {
private:
    char name[100];
    char username[100];
    int rank;
    int matchesPlayer;
    int matchesWon;
public:
    TennisPlayer()  = default;

//    TennisPlayer(char *name, char *username, int rank, int matchesPlayer, int matchesWon){
//        strcpy(this->name, name);
//        strcpy(this->username, username);
//        this->rank = rank;
//        this->matchesPlayer = matchesPlayer;
//        this->matchesWon = matchesWon;
//    }
    char *getName() {
        return name;
    }

    char *getSurname() {
        return username;
    }

    int getRank() const {
        return rank;
    }

    void setRank(int rank) {
        TennisPlayer::rank = rank;
    }

    int getMatchesPlayed() {
        return matchesPlayer;
    }

    void setMatchesPlayed(int matchesPlayer) {
        TennisPlayer::matchesPlayer = matchesPlayer;
    }

    int getMatchesWon() {
        return matchesWon;
    }

    void setMatchesWon(int matchesWon) {
        TennisPlayer::matchesWon = matchesWon;
    }

    void setName(char *name1) {
        strcpy(this->name, name1);
    }

    void setSurname(char *username1) {
        strcpy(this->username, username1);
    }

    float findPercentageWins() {
        float procent = (float)matchesWon / (float)matchesPlayer * 100.0;
        return procent;
    }
};


void printHighestRankedPlayerBelow50PercentWins(TennisPlayer *igrac, int n) {
    int bestIndex = -1;

    for (int i = 0; i < n; ++i) {
        if (igrac[i].findPercentageWins() < 50.0) {
            if (bestIndex == -1 || igrac[i].getRank() < igrac[bestIndex].getRank()) {
                bestIndex = i;
            }
        }
    }

    if (bestIndex != -1) {
        cout << igrac[bestIndex].getName() << " " << igrac[bestIndex].getSurname() << endl;
    } else {
        cout << "No such tennis player." << endl;
    }
}


int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0 || testCase == 1) {
        test(testCase);
        return 0;
    }

    int n;
    cin >> n;
    char name[100];
    char username[100];
    int rank;
    int matchesPlayer;
    int matchesWon;
    TennisPlayer *igrac = new TennisPlayer;
    for (int i = 0; i < n; ++i) {
        cin >> name >> username >> rank >> matchesPlayer >> matchesWon;
        igrac[i].setName(name);
        igrac[i].setSurname(username);
        igrac[i].setRank(rank);
        igrac[i].setMatchesPlayed(matchesPlayer);
        igrac[i].setMatchesWon(matchesWon);
    }
    printHighestRankedPlayerBelow50PercentWins(igrac, n);

    return 0;
}


void test(int k) {
    if (k == 0) {
        cout << "Testing default constructor and getters/setters" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5]{'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5]{'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        cout << "Full name: " << player.getName() << " " << player.getSurname() << endl;
        cout << "Rank and won matches out of total: " << player.getRank() << " " << player.getMatchesWon() << "/"
             << player.getMatchesPlayed() << endl;
    } else if (k == 1) {
        cout << "Testing findPercentageWins function" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5]{'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5]{'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        if (player.findPercentageWins() != 50) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.5 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        player.setMatchesWon(90);
        if (player.findPercentageWins() != 90) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.9 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        cout << "Passed." << endl;
    }
}
