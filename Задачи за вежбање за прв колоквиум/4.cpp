#include<iostream>
#include<cstring>

using namespace std;

class Patnik {
private:
    char ime[100];
    int klasa;
public:
    int getKlasa() const {
        return klasa;
    }

private:
    bool velosiped;
public:
    bool isVelosiped() const {
        return velosiped;
    }

public:
    Patnik(char *ime = " ", int klasa = 0, bool velosiped = false) {
        strcpy(this->ime, ime);
        this->klasa = klasa;
        this->velosiped = velosiped;
    }

    friend ostream &operator<<(ostream &out, const Patnik &p) {
        out << p.ime << endl;
        out << p.klasa << endl;
        return out;
    }
};

class Voz {
private:
    char krajnaDes[100];
    Patnik *niza;
    int n;
    int dozvoleniVelosipedi;
public:
    Voz(char *krajnaDes = " ", int dozvoleniVelosipedi = 0, int n = 0) {
        strcpy(this->krajnaDes, krajnaDes);
        this->dozvoleniVelosipedi = dozvoleniVelosipedi;
        this->n = n;
        niza = new Patnik[n];
    }
    Voz(const Voz &p){
        strcpy(this->krajnaDes, p.krajnaDes);
        this->dozvoleniVelosipedi = p.dozvoleniVelosipedi;
        this->n = p.n;
        niza = new Patnik[p.n];
        for(int i=0;i<p.n;i++){
            this->niza[i] = p.niza[i];
        }
    }
    Voz &operator=(const Voz &p){
        if(this != &p){
            delete [] niza;
            strcpy(this->krajnaDes, p.krajnaDes);
            this->dozvoleniVelosipedi = p.dozvoleniVelosipedi;
            this->n = p.n;
            niza = new Patnik[p.n];
            for(int i=0;i<p.n;i++){
                this->niza[i] = p.niza[i];
            }
        }
        return *this;
    }
    Voz &operator+=(const Patnik &p){
        Patnik *temp = new Patnik[n+1];
        for(int i=0;i<n;i++){
            temp[i] = niza[i];
        }
        temp[n] = p;
        n++;
        delete [] niza;
        niza = temp;
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Voz &p){
        out<<p.krajnaDes<<endl;
        for(int i=0;i<p.n;i++){
            out<<p.niza[i];
        }
        return out;
    }
    void patniciNemaMesto() const {
        int velosipediCount = 0;
        int firstClassWithoutPlace = 0;
        int secondClassWithoutPlace = 0;

        for (int i = 0; i < n; i++) {
            if (niza[i].isVelosiped()) {
                if (velosipediCount < dozvoleniVelosipedi) {
                    velosipediCount++;
                } else {
                    if (niza[i].getKlasa() == 1) {
                        firstClassWithoutPlace++;
                    } else {
                        secondClassWithoutPlace++;
                    }
                }
            }
        }
        cout << "First class without place: " << firstClassWithoutPlace << endl;
        cout << "Second class without place: " << secondClassWithoutPlace << endl;
    }
};


int main() {
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++) {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
