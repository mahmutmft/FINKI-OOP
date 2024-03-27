#include <iostream>
using namespace std;

struct Igrac {
    char ime[15];
    int nivo;
    int osvieniPoeni;
};

struct KompjuterskaIgra {
    char imeIgra[20];
    Igrac igraci[30];
    int brojNaIgraci;
};

void najdobarIgrac(const KompjuterskaIgra *lista, int n) {
    int maxIgra = 0;
    for (int i = 1; i < n; i++) {
        if (lista[i].brojNaIgraci > lista[maxIgra].brojNaIgraci) {
            maxIgra = i;
        }
    }
    int max = 0;
    for (int i = 1; i < lista[maxIgra].brojNaIgraci; i++) {
        if (lista[maxIgra].igraci[i].osvieniPoeni > lista[maxIgra].igraci[max].osvieniPoeni) {
            max = i;
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime ";
    cout << lista[maxIgra].igraci[max].ime;
    cout<<" koj ja igra igrata ";
    cout << lista[maxIgra].imeIgra;
}

int main() {
    int n, m;
    char ime[20];
    cin >> n;
    KompjuterskaIgra poleigri[100];
    for (int i = 0; i < n; i++) {
        KompjuterskaIgra nova;
        cin >> nova.imeIgra >> nova.brojNaIgraci;
        Igrac pole[30];
        for (int j = 0; j < nova.brojNaIgraci; j++) {
            Igrac nov;
            cin >> nov.ime >> nov.nivo >> nov.osvieniPoeni;
            nova.igraci[j] = nov;
        }
        poleigri[i] = nova;
    }

    najdobarIgrac(poleigri, n);
    return 0;
}
