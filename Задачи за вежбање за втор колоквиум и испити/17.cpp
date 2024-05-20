#include <iostream>
#include <cstring>

using namespace std;

class FudbalskaEkipa {
protected:
    char trener[100];
    int golovi[10];
public:
    FudbalskaEkipa(char *trener = " ", int *golovi = 0) {
        strcpy(this->trener, trener);
        for (int i = 0; i < 10; i++) {
            this->golovi[i] = golovi[i];
        }
    }
    uspeh
};

class Klub : public FudbalskaEkipa {
protected:
    char ime[100];
    int tituli;
public:
    Klub(char *trener = " ", int *golovi = 0, char *ime = " ", int tituli = 0) : FudbalskaEkipa(trener,golovi) {
        strcpy(this->ime, ime);
        this->tituli = tituli;
    }
    friend ostream &operator<<(ostream &out, const Klub &p){
        out<<p.ime<<endl;
        out<<p.trener<<endl;
        return out;
    }
};

class Reprezentacija : public FudbalskaEkipa {
protected:
    char drzava[100];
    int nastapi;
public:
    Reprezentacija(char *trener = " ", int *golovi = 0, char *drzava = " ", int nastapi = 0) : FudbalskaEkipa(trener,golovi){
        strcpy(this->drzava, drzava);
        this->nastapi = nastapi;
    }
    friend ostream &operator<<(ostream &out, const Reprezentacija &p){
        out<<p.drzava<<endl;
        out<<p.trener<<endl;
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa *[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete[] ekipi;
    return 0;
}