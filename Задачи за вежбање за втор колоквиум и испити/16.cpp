#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Transport {
protected:
    char destinacija[30];
    int osnovnaCena;
    int km;
public:
    int getKm() const {
        return km;
    }

public:
    Transport(char *destinacija = " ", int osnovnaCena = 0, int km = 0) {
        strcpy(this->destinacija, destinacija);
        this->osnovnaCena = osnovnaCena;
        this->km = km;
    }

    virtual double cenaTransport() = 0;

    bool operator<(const Transport &p) {
        return destinacija < p.destinacija;
    }

    virtual void pecati() = 0;
};

class AvtomobilTransport : public Transport {
protected:
    bool platenShofer;
public:
    AvtomobilTransport(char *destinacija = " ", int osnovnaCena = 0, int km = 0, bool platenShofer = false)
            : Transport(destinacija, osnovnaCena, km) {
        this->platenShofer = platenShofer;
    }

    double cenaTransport() override {
        if (platenShofer) {
            return osnovnaCena * 1.2;
        } else {
            return osnovnaCena;
        }
    }

    void pecati() override {
        cout << destinacija << " " << km << " " << cenaTransport() << endl;
    }
};

class KombeTransport : public Transport {
protected:
    int brojLudje;
public:
    KombeTransport(char *destinacija = " ", int osnovnaCena = 0, int km = 0, int brojLudje = 0)
            : Transport(destinacija, osnovnaCena, km) {
        this->brojLudje = brojLudje;
    }

    double cenaTransport() override {
        double cena = osnovnaCena;
        for (int i = 0; i < brojLudje; i++) {
            cena -= 200;
        }
        return cena;
    }

    void pecati() override {
        cout << destinacija << " " << km << " " << cenaTransport() << endl;
    }
};

void pecatiPoloshiPonudi(Transport **ponudi, int n, Transport &t) {
    Transport **poloshiPonudi = new Transport *[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (ponudi[i]->cenaTransport() > t.cenaTransport()) {
            poloshiPonudi[count++] = ponudi[i];
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (*poloshiPonudi[j] < *poloshiPonudi[j + 1]) {
                Transport *temp = poloshiPonudi[j];
                poloshiPonudi[j] = poloshiPonudi[j + 1];
                poloshiPonudi[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        poloshiPonudi[i]->pecati();
    }

    delete[] poloshiPonudi;
}

int main() {

    char destinacija[20];
    int tip, cena, rastojanie, lugje;
    bool shofer;
    int n;
    cin >> n;
    Transport **ponudi;
    ponudi = new Transport *[n];

    for (int i = 0; i < n; i++) {

        cin >> tip >> destinacija >> cena >> rastojanie;
        if (tip == 1) {
            cin >> shofer;
            ponudi[i] = new AvtomobilTransport(destinacija, cena, rastojanie, shofer);

        } else {
            cin >> lugje;
            ponudi[i] = new KombeTransport(destinacija, cena, rastojanie, lugje);
        }


    }

    AvtomobilTransport nov("Ohrid", 2000, 600, false);
    pecatiPoloshiPonudi(ponudi, n, nov);

    for (int i = 0; i < n; i++) delete ponudi[i];
    delete[] ponudi;
    return 0;
}
