#include<stdio.h>
#include <iostream>
using namespace std;

struct Pacient {
    char ime[100];
    bool osiguran;
    int preglediMesec;
};

struct MaticenDoktor {
    char imeNaDoktor[100];
    int pacienti;
    Pacient lista[200];
    float cenaNaPregled;
};

void najuspesen_doktor(MaticenDoktor *m, int n) {
    int maxSuma = 0;
    int maxIndex=0;
    int maxIndex2=0;
    for (int i = 0; i < n; i++) {
        int suma=0;
        for (int j = 0; j < m[i].pacienti; j++) {
            if(m[i].lista[j].osiguran == 0) {
                suma += m[i].cenaNaPregled;
            }
        }
        if(suma<maxSuma) {
            maxSuma = suma;
            maxIndex = i;
        }
    }
    cout<<maxSuma;
}

int main() {
    int n, broj;
    MaticenDoktor md[200];
    cin>>n;
    for (int i = 0; i < n; i++) {
        //ime na doktor
        scanf("%s", &md[i].imeNaDoktor);
        //broj na pacienti
        scanf("%d", &md[i].pacienti);
        //cena na pregled
        scanf("%f", &md[i].cenaNaPregled);

        for (int j = 0; j < md[i].pacienti; j++) {
            scanf("%s", &md[i].lista[j].ime);
            scanf("%d", &md[i].lista[j].osiguran);
            scanf("%d", &md[i].lista[j].preglediMesec);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}
