#include<iostream>
#include<cstring>
using namespace std;

struct Tanc {
    char imeNaTanc[15];
    char zemjaNaPoteklo[15];
};
struct Tancer {
    char ime[15];
    char prezime[15];
    Tanc niza[5];
};

void tancuvanje(Tancer *t, int n, char *zemja) {

    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            if(strcmp(t[i].niza[j].zemjaNaPoteklo, zemja) == 0) {
                cout<<t[i].ime <<" "<<t[i].prezime<<", "<<t[i].niza[j].imeNaTanc<<endl;
                return;
            }
        }
    }
}
int main()
{
    int i, j, n;
    char zemja[15];
    Tancer tanceri[5];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tanceri[i].ime;
        cin >> tanceri[i].prezime;
        for(j = 0; j < 3; j++){
            cin >> tanceri[i].niza[j].imeNaTanc;
            cin >> tanceri[i].niza[j].zemjaNaPoteklo;
        }
    }
    cin >> zemja;
    tancuvanje(tanceri, n, zemja);
    return 0;
}