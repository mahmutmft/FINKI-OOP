#include<iostream>
#include<cstring>

using namespace std;

class UserAlreadyExistsException {
private:
    char ime[100];
public:
    UserAlreadyExistsException(char *ime = " ") {
        strcpy(this->ime, ime);
    }
    void showMessage() {
        cout << "User with username "<<ime<<" already exists!" << endl;
    }
};

class UserNotFoundException {
private:
    char ime[100];
public:
    UserNotFoundException(char *ime = " ") {
        strcpy(this->ime, ime);
    }
    void showMessage() {
        cout << "User with username "<<ime<<" was not found!" << endl;
    }
};

class FriendsLimitExceededException {
private:
    int n;
public:
    FriendsLimitExceededException(int n = 0) : n(n) {}
    void showMessage() {
        cout << "Can't have more than " << n << " friends." << endl;
    }
};

class User {
private:
    char username[50];
    int age;
    int friends;
    static int limit;
public:
    User(char *username = "", int age = 18) : age(age) {
        strcpy(this->username, username);
        friends = 0;
    }

    friend ostream &operator<<(ostream &os, const User &user) {
        os << "Username: " << user.username << " Age: " << user.age << " # of friends: " << user.friends;
        return os;
    }


    User &operator++() {
        if (friends >= limit) {
            throw FriendsLimitExceededException(limit);
        }
        ++friends;
        return *this;
    }

    static void setLimit(int limit2) {
        limit = limit2;
    }

    friend class SocialNetwork;
};

int User::limit = 3;

class SocialNetwork {
private:
    User *users;
    int n;
public:
    bool userExists(const char *username) {
        for (int i = 0; i < n; ++i) {
            if (strcmp(users[i].username, username) == 0) {
                return true;
            }
        }
        return false;
    }

    SocialNetwork() {
        n = 0;
        users = new User[n];
    }

    SocialNetwork &operator+=(User &u) {
        if (userExists(u.username)) {
            throw UserAlreadyExistsException(u.username);
        }
        User *tmp = new User[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = users[i];
        }
        tmp[n++] = u;
        delete[] users;
        users = tmp;
        return *this;
    }


    void friendRequest(char *firstUsername, char *secondUsername) {
        int firstIndex = -1, secondIndex = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(users[i].username, firstUsername) == 0) {
                firstIndex = i;
            }
            if (strcmp(users[i].username, secondUsername) == 0) {
                secondIndex = i;
            }
        }
        if (firstIndex == -1 || secondIndex == -1) {
            throw UserNotFoundException(secondUsername);
        }

        try {
            ++users[firstIndex];
            ++users[secondIndex];
        } catch (FriendsLimitExceededException &e) {
            e.showMessage();
        }
    }

    friend ostream &operator<<(ostream &os, const SocialNetwork &network) {
        os << "Users: " << endl;
        for (int i = 0; i < network.n; i++) {
            os << network.users[i] << endl;
        }
        return os;
    }
};


int main() {
    SocialNetwork sn;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char username[50];
        int age;
        cin >> username >> age;
        User u(username, age);
        try {
            sn += u;
        }
        catch (UserAlreadyExistsException &e) {
            e.showMessage();
        }

    }

    cout << "Registration of users " << endl;
    cout << sn << endl;
    cout << "Friend requests " << endl;

    int friendships;
    cin >> friendships;
    for (int i = 0; i < friendships; i++) {
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try {
            sn.friendRequest(username1, username2);
        }
        catch (UserNotFoundException &e) {
            e.showMessage();
        }


    }

    cout << sn << endl;

    cout << "CHANGE STATIC VALUE" << endl;

    int maxFriends;
    cin >> maxFriends;
    cin >> friendships;
    User::setLimit(maxFriends);
    for (int i = 0; i < friendships; i++) {
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try {
            sn.friendRequest(username1, username2);
        }
        catch (UserNotFoundException &e) {
            e.showMessage();
        }
    }
    cout << sn;
    return 0;
}