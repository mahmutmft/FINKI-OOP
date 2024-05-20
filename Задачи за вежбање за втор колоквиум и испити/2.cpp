#include <iostream>

using namespace std;

class Vozac {
protected:
    string ime;
    int vozrast;
    int brojTrki;
    bool isVeteran;
public:
    Vozac(const string ime = " ", int vozrast = 0, int brojTrki = 0, bool isVeteran = false) {
        this->ime = ime;
        this->vozrast = vozrast;
        this->brojTrki = brojTrki;
        this->isVeteran = isVeteran;
    }

    virtual float zarabotuvachka() const = 0;

    virtual float danok() const = 0;

    bool operator==(const Vozac &p) const {
        return this->zarabotuvachka() == p.zarabotuvachka();
    }

    friend ostream &operator<<(ostream &o, const Vozac &p) {
        o << p.ime << endl;
        o << p.vozrast << endl;
        o << p.brojTrki << endl;
        if (p.isVeteran) {
            o << "VETERAN" << endl;
        }
        return o;
    }
};

class Avtomobilist : public Vozac {
protected:
    float cenaNaAvtomobil;
public:
    Avtomobilist(const string ime = " ", int vozrast = 0, int brojTrki = 0, bool isVeteran = false,
                 float cenaNaAvtomobil = 0)
            : Vozac(ime, vozrast, brojTrki, isVeteran) {
        this->cenaNaAvtomobil = cenaNaAvtomobil;
    }

    float zarabotuvachka() const{
        return cenaNaAvtomobil / 5;
    }

    float danok() const{
        if(brojTrki > 10){
            return zarabotuvachka() * 0.15;
        }
        else{
            return zarabotuvachka() * 0.1;
        }
    }
};

class Motociklist : public Vozac {
protected:
    int hp;
public:
    Motociklist(const string ime = " ", int vozrast = 0, int brojTrki = 0, bool isVeteran = false, int hp = 0)
            : Vozac(ime, vozrast, brojTrki, isVeteran) {
        this->hp = hp;
    }

    float zarabotuvachka() const {
        return hp * 20;
    }

    float danok() const {

        if(isVeteran){
            return zarabotuvachka() * 0.25;
        }
        else{
            return zarabotuvachka() * 0.2;
        }
    }
};

int soIstaZarabotuvachka(Vozac **vozaci, int broj, Vozac *vozac){
    int index = 0;
    for(int i=0;i<broj;i++){
        if(*vozaci[i] == *vozac){
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