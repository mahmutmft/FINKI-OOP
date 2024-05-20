#include <iostream>
#include <cstring>

using namespace std;
enum tip {
    pop, rap, rok
};

class Pesna {
private:
    char *ime;
    int vreme;
    tip tipPesna;
public:
    tip getTipPesna() const {
        return tipPesna;
    }

public:
    int getVreme() const {
        return vreme;
    }

public:
    Pesna(char *ime = " ", int vreme = 0, tip tipPesna = tip(rap)) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->vreme = vreme;
        this->tipPesna = tipPesna;
    }

    Pesna(Pesna &p) {
        this->ime = new char[strlen(p.ime) + 1];
        strcpy(this->ime, p.ime);
        this->vreme = p.vreme;
        this->tipPesna = p.tipPesna;
    }

    Pesna &operator=(const Pesna &p) {
        if (this != &p) {
            delete[] ime;
            this->ime = new char[strlen(p.ime) + 1];
            strcpy(this->ime, p.ime);
            this->vreme = p.vreme;
            this->tipPesna = p.tipPesna;
        }
        return *this;
    }

    void pecati() {
        cout << '"' << ime << '"' << "-" << vreme << "min" << endl;
    }

    ~Pesna() {
        delete[] ime;
    }
};

class CD {
private:
    Pesna niza[10];
    int brojPesni;
public:
    int getBroj() const {
        return brojPesni;
    }

private:
    int maxVreme;

    int vremeSum() {
        int sum = 0;
        for (int i = 0; i < brojPesni; i++) {
            sum += niza[i].getVreme();
        }
        return sum;
    }

public:
    Pesna getPesna(int i) {
        return niza[i];
    }

    CD(int maxVreme = 0, int brojPesni = 0) {
        this->maxVreme = maxVreme;
        this->brojPesni = brojPesni;
    }

    CD(const CD &p) {
        this->maxVreme = p.maxVreme;
        this->brojPesni = p.brojPesni;
        for (int i = 0; i < p.brojPesni; i++) {
            this->niza[i] = p.niza[i];
        }
    }

    CD &operator=(const CD &p) {
        if (this != &p) {
            this->maxVreme = p.maxVreme;
            this->brojPesni = p.brojPesni;
            for (int i = 0; i < p.brojPesni; i++) {
                this->niza[i] = p.niza[i];
            }
        }
        return *this;
    }

    bool dodadiPesna(Pesna p) {
        if (brojPesni < 10 && vremeSum() + p.getVreme() <= maxVreme) {
            niza[brojPesni] = p;
            brojPesni++;
            return true;
        } else {
            return false;
        }
    }

    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < brojPesni; i++) {
            if (niza[i].getTipPesna() == t) {
                niza[i].pecati();
            }
        }
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}