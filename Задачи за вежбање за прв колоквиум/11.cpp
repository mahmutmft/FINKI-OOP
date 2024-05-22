#include <iostream>
#include<cstring>

using namespace std;

class Ucesnik {
private:
    char *ime;
    bool pol;
    int vozrast;
public:
    int getVozrast() const {
        return vozrast;
    }

public:
    Ucesnik(char *ime = " ", bool pol = true, int vozrast = 0) {
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }
    Ucesnik(const Ucesnik &p){
        this->ime = new char[strlen(p.ime)+1];
        strcpy(this->ime, p.ime);
        this->pol = p.pol;
        this->vozrast = p.vozrast;
    }
    Ucesnik &operator=(const Ucesnik &p){
        if(this != &p){
            delete [] ime;
            this->ime = new char[strlen(p.ime)+1];
            strcpy(this->ime, p.ime);
            this->pol = p.pol;
            this->vozrast = p.vozrast;
        }
        return *this;
    }
    bool operator>(const Ucesnik &p) const{
        return vozrast > p.vozrast;
    }
    friend ostream &operator<<(ostream &out, const Ucesnik &p){
        out<<p.ime<<endl;
        if(p.pol == 1){
            out<<"mashki"<<endl;
        }
        else
            cout<<"zhenski"<<endl;
        out<<p.vozrast<<endl;
        return out;
    }
    ~Ucesnik(){
        delete [] ime;
    }
};

class Maraton{
private:
    char lokacija[100];
    Ucesnik *niza;
    int n;
public:
    Maraton(char *lokacija = " ",int n = 0){
        strcpy(this->lokacija, lokacija);
        niza = new Ucesnik[n];
        this->n = n;
    }
    Maraton(const Maraton &p){
        strcpy(this->lokacija, p.lokacija);
        niza = new Ucesnik[p.n];
        this->n = p.n;
        for(int i=0;i<p.n;i++){
            this->niza[i] = p.niza[i];
        }
    }
    Maraton &operator=(const Maraton &p){
        if(this != &p){
            delete[]niza;
            strcpy(this->lokacija, p.lokacija);
            niza = new Ucesnik[p.n];
            this->n = p.n;
            for(int i=0;i<p.n;i++){
                this->niza[i] = p.niza[i];
            }
        }
        return *this;
    }
    Maraton &operator+=(const Ucesnik &p){
        Ucesnik *temp = new Ucesnik[n+1];
        for(int i=0;i<n;i++){
            temp[i] = niza[i];
        }
        temp[n] = p;
        n++;
        delete [] niza;
        niza = temp;
        return *this;
    }
    double prosecnoVozrast(){
        double prosek = 0;
        for(int i=0;i<n;i++){
            prosek += niza[i].getVozrast();
        }
        prosek = prosek / n;
        return prosek;
    }
    void pecatiPomladi(Ucesnik &u){
        for(int i=0;i<n;i++){
            if(niza[i].getVozrast() < u.getVozrast()){
                cout<<niza[i];
            }
        }
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik *[n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for (int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete[] u;
    return 0;
}