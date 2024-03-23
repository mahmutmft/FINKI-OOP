#include <iostream>
#include <cstring>
using namespace std;

int ZNACI = 30;

class Rabotnik {
private:
    char ime[ZNACI];
    char prezime[ZNACI];
    int plata;
public:
    Rabotnik(){}
    Rabotnik(char *_ime, char *_prezime, int _plata) {
        strcpy(ime, _ime);
        strcpy(prezime,_prezime);
        plata = _plata;
    }
    int getPlata() {
        return plata;
    }
    void pecati(){

    }
};
class Fabrika {
    Rabotnik vraboteni[100];
    int brojVraboteni;
public:
    void pecatiVraboteni() {

    }
    void pecatiSoPlata(int plata) {

    }
};
int main() {

}