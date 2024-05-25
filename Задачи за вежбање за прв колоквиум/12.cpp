#include <iostream>
#include <cstring>

using namespace std;
//neraboti
class Pica {
private:
    char imePica[15];
    int cena;
    char *sostojki;
    int popust;
public:
    Pica(char *ime = " ", int cena = 0, char *sostojki = " ", int popust = 0) {
        strcpy(this->imePica, imePica);
        this->cena = cena;
        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
        this->popust = popust;
    }

    Pica(const Pica &p) {
        strcpy(this->imePica, p.imePica);
        this->cena = p.cena;
        this->sostojki = new char[strlen(p.sostojki) + 1];
        strcpy(this->sostojki, p.sostojki);
        this->popust = p.popust;
    }

    Pica &operator=(const Pica &p) {
        if (this != &p) {
            delete[] sostojki;
            strcpy(this->imePica, p.imePica);
            this->cena = p.cena;
            strcpy(this->sostojki, p.sostojki);
            this->sostojki = new char[strlen(p.sostojki) + 1];
            this->popust = p.popust;
        }
        return *this;
    }

    void pecati() {
        cout << imePica << "-" << sostojki << ", " << cena;
    }

    bool istiSe(Pica p) {
        return strcmp(sostojki, p.sostojki) == 0;
    }

    ~Pica() {
        delete[] sostojki;
    }
    bool naPromocija() const {
        return popust > 0;
    }
};

class Picerija{
private:
    char ime[15];
    Pica *niza;
    int n;
public:
    void setIme(const char *imePicerij){
        strcpy(this->ime , imePicerij);
    }
    Picerija(char *ime = " ", int n = 0){
        this->niza = new Pica[n];
        strcpy(this->ime, ime);
        this->n = n;
    }
    Picerija(const Picerija &p){
        this->niza = new Pica[p.n];
        strcpy(this->ime, p.ime);
        this->n =p.n;
        for(int i=0;i<n;i++){
            this->niza[i] = p.niza[i];
        }
    }
    Picerija &operator=(const Picerija &p){
        if(this != &p){
            delete [] niza;
            this->niza = new Pica[p.n];
            strcpy(this->ime, p.ime);
            this->n =p.n;
            for(int i=0;i<n;i++){
                this->niza[i] = p.niza[i];
            }
        }
        return *this;
    }
    Picerija &operator+=(const Pica &p){
        Pica *temp = new Pica[n+1];
        for(int i=0;i<n;i++){
            temp[i] = niza[i];
        }
        temp[n] = p;
        n++;
        delete [] niza;
        niza = temp;
        return *this;
    }
    const char *getIme() const {
        return ime;
    }
    void dodadi(const Pica &p) {
        for (int i = 0; i < n; i++) {
            if (niza[i].istiSe(p)) {
                return;
            }
        }
        Pica *temp = new Pica[n + 1];
        for (int i = 0; i < n; i++) {
            temp[i] = niza[i];
        }
        temp[n] = p;
        delete[] niza;
        niza = temp;
        n++;
    }
    void piciNaPromocija() const {
        for (int i = 0; i < n; i++) {
            if (niza[i].naPromocija()) {
                niza[i].pecati();
            }
        }
    }
};

int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1 += p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2 += p;

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
