#include<iostream>
#include<cstring>

using namespace std;

struct Voz {
    char relacija[51];
    double km;5
    int broj_patnici;
};

struct ZeleznickaStanica {
    char grad[25];
    Voz vozovi[30];
    int broj_vozovi;
};

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad) {
    double minimumKm = 9999;
    char* najkratka_relacija;
    for (int i = 0; i < n; i++) {
        bool zname = true;
        for (int j = 0; zs[i].grad[j] != '\0' || grad[j] != '\0' ; j++) {
            if (grad[j] != zs[i].grad[j]) {
                zname = false;
                break;
            }
        }
        if (zname) {
            for (int j = 0; j < zs[i].broj_vozovi; j++) {
               if(zs[j].vozovi[i].km < minimumKm) {
                   minimumKm = zs[i].vozovi[j].km;
                   najkratka_relacija = zs[i].vozovi[j].relacija;
               }
            }
        }
    }
    if (najkratka_relacija) {
        cout << "Najkratka relacija: " << najkratka_relacija << " (" << minimumKm << " km)" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    ZeleznickaStanica zStanica[100];
    for (int i = 0; i < n; i++) {
        cin >> zStanica[i].grad;
        cin >> zStanica[i].broj_vozovi;
        for (int j = 0; j < zStanica[i].broj_vozovi; j++) {
            cin >> zStanica[i].vozovi[j].relacija;
            cin >> zStanica[i].vozovi[j].km;
            cin >> zStanica[i].vozovi[j].broj_patnici;
        }
    }
    char grad[25];
    cin >> grad;

    najkratkaRelacija(zStanica, n, grad);
    return 0;
}
