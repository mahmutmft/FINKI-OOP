//
// Created by PeceG.
//
#include <iostream>
#include <cstring>
using namespace std;
class UserProfile;


class Achievement {
private:
    char name[100];
    char description[100];
    static int totalUserAchievements;

public:
    Achievement() = default;
    Achievement(const char* name, const char* description) {
        strcpy(this->name, name);
        strcpy(this->description, description);
    }
    Achievement(const Achievement& a) {
        strcpy(this->name, a.name);
        strcpy(this->description, a.description);
    }

    void print() const {
        cout << name << endl << description << endl;
    }

    static void incrementTotalUserAchievements() {
        ++totalUserAchievements;
    }

    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
};
int Achievement::totalUserAchievements = 0;


class UserProfile {
private:
    char name[100];
    Achievement achievements[50];
    int n;

public:
    UserProfile() {
        this->n = 0;
    }
    UserProfile(const char* name) {
        strcpy(this->name, name);
        this->n = 0;
    }

    void addAchievement(const Achievement& achievement) {
        achievements[n++] = achievement;
        Achievement::incrementTotalUserAchievements();
    }

    void print() {
        cout << "User: " << name << endl;
        cout << "Achievements: " << endl;
        for (int i = 0; i < n; ++i)
            achievements[i].print();
    }

    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
};


void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m) {
    for (int i = 0; i < m; ++i) {  // for each achievement
        int numberOfUsersThatHaveAchievement = 0;
        for (int j = 0; j < n; ++j) {  // for each user
            bool has_achievement = false;
            for (int k = 0; k < profiles[j].n; ++k) { // try to match any of user achievements with outermost achievement
                if (strcmp(achievements[i].name, profiles[j].achievements[k].name) == 0) {
                    has_achievement = true;
                    break;
                }
            }
            numberOfUsersThatHaveAchievement += (has_achievement ? 1 : 0);
        }
        achievements[i].print();
        cout << "---Percentage of users who have this achievement: " << numberOfUsersThatHaveAchievement * 100.0 / n << "%" << endl;
    }
    cout << "------Average completion rate of the game: " << Achievement::totalUserAchievements * 100.0 / (n * m) << "%" << endl;
}


// Don't modify
int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {  // Testing Achievement methods.
        for (int i = 0; i < m; ++i) {
            achievements[i].print();
        }
        Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {  // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}