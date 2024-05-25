#include <iostream>
#include <cstring>

using namespace std;

class Vozac {
protected:
    char ime[100];
    int vozrast;
    int brTrki;
    bool isVeteran;
public:
    Vozac(char *ime = " ", int vozrast = 0, int brTrki = 0, bool isVeteran = false) {
        strcpy(this->ime, ime);
        this->vozrast = vozrast;
        this->brTrki = brTrki;
        this->isVeteran = isVeteran;
    }

    friend ostream &operator<<(ostream &out, const Vozac &p) {
        out << p.ime << endl;
        out << p.vozrast << endl;
        out << p.brTrki << endl;
        if (p.isVeteran) {
            out << "VETERAN" << endl;
        }
        return out;
    }

    virtual double zarabotuvacka() const = 0;

    virtual double danok() const = 0;

    bool operator==(const Vozac &p){
        return this->zarabotuvacka() == p.zarabotuvacka();
    }
};

class Avtomobilist : public Vozac {
protected:
    double cenaAvtomobil;
public:
    Avtomobilist(char *ime = " ", int vozrast = 0, int brTrki = 0, bool isVeteran = false, double cenaAvtomobil = 0)
            : Vozac(ime, vozrast, brTrki, isVeteran) {
        this->cenaAvtomobil = cenaAvtomobil;
    }

    double zarabotuvacka() const {
        return cenaAvtomobil / 5;
    }

    double danok() const {
        if (brTrki > 10)  {
            return zarabotuvacka() * 0.15;
        } else {
            return zarabotuvacka() * 0.1;
        }
    }
};

class Motociklist : public Vozac {
protected:
    int moknosMotor;
public:
    Motociklist(char *ime = " ", int vozrast = 0, int brTrki = 0, bool isVeteran = false, int moknosMotor = 0)
            : Vozac(ime, vozrast, brTrki, isVeteran) {
        this->moknosMotor = moknosMotor;
    }

    double zarabotuvacka() const {
        return moknosMotor * 20;
    }

    double danok() const {
        if (isVeteran) {
            return zarabotuvacka() * 0.25;
        } else {
            return zarabotuvacka() * 0.2;
        }
    }
};

int soIstaZarabotuvachka(Vozac **niza , int n, Vozac *b){
    int index = 0;
    for(int i=0;i<n;i++){
        if(*niza[i] == *b){
            index++;
        }
    }
    return index;
}

int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac *[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for (int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if (i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
      cout << soIstaZarabotuvachka(v, n, vx);
    for (int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete[] v;
    delete vx;
    return 0;
}