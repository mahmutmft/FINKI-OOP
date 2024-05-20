#include<iostream>
#include<cstring>
using namespace std;

class UserAlreadyExistsException : public exception {
public:
    const char* what() const throw() {
        return "User already exists.";
    }
};

class UserNotFoundException : public exception {
public:
    const char* what() const throw() {
        return "User not found.";
    }
};

class FriendsLimitExceededException : public exception {
public:
    const char* what() const throw() {
        return "Friends limit exceeded.";
    }
};

class User {
private:
    char username[50];
    int age;
    int friends;
    static int maxFriends; // Static member for max friends limit

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
        if (friends + 1 > maxFriends) {
            throw FriendsLimitExceededException();
        }
        ++friends;
        return *this;
    }

    static void setLimit(int limit) {
        maxFriends = limit;
    }

    friend class SocialNetwork;
};

// Initialize static member
int User::maxFriends = 3;

class SocialNetwork {
private:
    User *users;
    int n;
public:
    SocialNetwork() {
        n = 0;
        users = new User[n];
    }

    ~SocialNetwork() {
        delete[] users;
    }

    SocialNetwork &operator+=(User &u) {
        for (int i = 0; i < n; ++i) {
            if (strcmp(users[i].username, u.username) == 0) {
                throw UserAlreadyExistsException();
            }
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
        int i, j;
        bool foundFirst = false, foundSecond = false;
        for (i = 0; i < n; i++) {
            if (strcmp(users[i].username, firstUsername) == 0) {
                foundFirst = true;
                break;
            }
        }
        for (j = 0; j < n; j++) {
            if (strcmp(users[j].username, secondUsername) == 0) {
                foundSecond = true;
                break;
            }
        }
        if (!foundFirst || !foundSecond) {
            throw UserNotFoundException();
        }
        try {
            ++users[i];
            ++users[j];
        } catch (FriendsLimitExceededException &e) {
            cout << e.what() << endl;
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
    for (int i=0;i<n;i++){
        char username[50]; int age;
        cin >> username >> age;
        User u(username, age);
        sn += u;

    }

    cout << "Registration of users " << endl;
    cout << sn << endl;
    cout << "Friend requests " << endl;

    int friendships;
    cin >> friendships;
    for (int i=0;i<friendships;i++){
        char username1[50], username2[50];
        cin >> username1 >> username2;
        sn.friendRequest(username1, username2);

    }

    cout << sn << endl;

    cout << "CHANGE STATIC VALUE" << endl;

    int maxFriends;
    cin >> maxFriends;
    cin >> friendships;
    User::setLimit(maxFriends);
    for (int i=0;i<friendships;i++){
        char username1[50], username2[50];
        cin >> username1 >> username2;
        sn.friendRequest(username1, username2);

    }
    cout << sn;
    return 0;
}