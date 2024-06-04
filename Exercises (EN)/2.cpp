#include<iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class ExistingBill{
public:
    void print(){
        cout<<"The bill already exists"<<endl;
    }
};

class Bill{
private:
    char *billNumber;
    int expense;
    char yearM[30];
    bool payed;
public:
    bool isPayed() const {
        return payed;
    }

public:
    Bill(char *billNumber = " ", int expense = 0, char *yearM = " ", bool payed = false) {
        this->billNumber = new char[strlen(billNumber) + 1];
        strcpy(this->billNumber , billNumber);
        this->expense = expense;
        strcpy(this->yearM , yearM);
        this->payed = payed;
    }
    Bill (const Bill &p){
        this->billNumber = new char[strlen(p.billNumber) + 1];
        strcpy(this->billNumber , p.billNumber);
        this->expense = p.expense;
        strcpy(this->yearM , p.yearM);
        this->payed = p.payed;
    }
    Bill &operator=(const Bill &p){
        if(this != &p){
            delete [] billNumber;
            this->billNumber = new char[strlen(p.billNumber) + 1];
            strcpy(this->billNumber , p.billNumber);
            this->expense = p.expense;
            strcpy(this->yearM , p.yearM);
            this->payed = p.payed;
        }
        return *this;
    }
    bool operator==(const Bill &p){
        return strcmp(this->billNumber, p.billNumber) == 0;
    }
    friend ostream &operator<<(ostream &out, Bill &p){
        out<<p.billNumber<<"("<<p.yearM<<")"<<" - "<<p.expense<<endl;
        return out;
    }
};
class UserProfile{
private:
    char username[30];
    Bill *niza;
    int n;
public:
    UserProfile(char *username = " ", int n = 0){
        this->niza = new Bill[n];
        strcpy(this->username, username);
        for(int i=0;i<n;i++){
            this->niza[i] = niza[i];
        }
    }
    UserProfile (const UserProfile &p){
        strcpy(this->username, p.username);
        this->niza = new Bill[p.n];
        for(int i=0;i<p.n;i++){
            this->niza[i] = p.niza[i];
        }
    }
    UserProfile &operator+=(Bill &p){
        Bill *tmp = new Bill[n+1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = niza[i];
        }
        tmp[n++] = p;
        delete [] niza;
        niza = tmp;
        return *this;

    }
    friend ostream &operator<<(ostream &out, UserProfile &p) {
        out<<"Unpaid bills of user "<<p.username<<" are:"<<endl;
        for(int i=0;i<p.n;i++){
            if(!p.niza[i].isPayed()){
                out<<p.niza[i];
            }
        }
        return out;
    }
};

int main() {
    char number[50], month[8], name[50];
    int price, n;
    bool status;


    int type;
    cin >> type;

    if (type == 1) {
        cout << "-----Test Bill & operator <<-----" << endl ;
        cin >> number >> price >> month >> status;
        Bill b(number, price, month, status);
        cout << b;
    } else if (type == 2) {
        cout << "-----Test Bill & operator == -----" << endl ;
        cin >> number >> price >> month >> status;
        Bill b1(number, price, month, status);
        cin >> number >> price >> month >> status;
        Bill b2(number, price, month, status);
        if (b1 == b2) cout << "Equal" << endl;
        else cout << "Not equal" << endl;

    } else if (type == 3) {
        cout << "-----Test UserProfile & operator += & << -----" << endl ;
        cin >> name >> n;
        UserProfile up(name);
        for (int i = 0; i < n; i++) {
            cin >> number >> price >> month >> status;
            Bill s(number, price, month, status);
            up += s;
        }
        cout << up;
    } else if (type == 4) {
        cout << "-----Test UserProfile & operator += & totalDue -----" << endl ;
        cin >> name >> n;
        UserProfile up(name);
        for (int i = 0; i < n; i++) {
            cin >> number >> price >> month >> status;
            Bill s(number, price, month, status);
            up += s;
        }
        int m, y;
        cin >> m >> y;
        cout << "Total due for month " << m << " and year " << y << " is:";
        cout << up.totalDue(m, y) << endl;
    } else if (type == 5) {
        cout << "-----Test all -----" << endl ;
        cin >> name >> n;
        UserProfile up(name);
        for (int i = 0; i < n; i++) {
            cin >> number >> price >> month >> status;
            Bill s(number, price, month, status);
            up += s;
        }
        cout << up;
        int m, y;
        cin >> m >> y;
        cout << "Total due for month " << m << " and year " << y << " is:";
        cout << up.totalDue(m, y) << endl;
    }

    return 0;
}
