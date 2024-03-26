#include <iostream>
#include <iomanip>
using namespace std;

struct Vozenje {
    char name[100];
    int vremeMin;
    float cena;
    bool studnetskiPopust;
};

struct ZabavenPark {
    char imeNaPark[100];
    char lokacija[100];
    Vozenje vozenja[100];
    int n;
};

void print(const ZabavenPark* park, int n) {
    for(int i = 0; i < n; i++) {
        cout << park[i].imeNaPark << " " << park[i].lokacija << endl;
        for(int j = 0; j < park[i].n; j++) {
            cout <<park[i].vozenja[j].name << " " << park[i].vozenja[j].vremeMin << " " <<setprecision(2)<<(fixed)<< park[i].vozenja[j].cena << endl;
        }
    }
}

void najdobarPark(const ZabavenPark* park, int n ) {
    int max = -1; // Initialize max properly
    int maxIndex = 0, maxVreme = 0, maxVremeTraenje = 0;

    for(int i = 0; i < n; i++) {
        int brojac = 0, vreme = 0;
        for(int j = 0; j < park[i].n; j++) {
            if(park[i].vozenja[j].studnetskiPopust == 1) {
                brojac++;
            }
            vreme += park[i].vozenja[j].vremeMin;
        }
        if(brojac > max) {
            max = brojac;
            maxIndex = i;
            maxVremeTraenje = vreme;
        }
        else if(brojac == max && vreme > maxVremeTraenje) {
            maxIndex = i;
            maxVremeTraenje = vreme;
        }
    }
    cout << "Najdobar park: " << park[maxIndex].imeNaPark << " " << park[maxIndex].lokacija << endl;
}

int main() {
    int n;
    //kreiraj niza od maksimum 100 zabavni parkovi
    ZabavenPark ff[100];
    cin >> n; // Input the number of parks

    //citanje na podatocite
    for (int i = 0; i < n; i++) {
        //ime na parkot
        cin >> ff[i].imeNaPark;
        //lokacija
        cin >> ff[i].lokacija;
        //broj na vozenja
        cin >> ff[i].n;

        for (int j = 0; j < ff[i].n; j++) {
            cin >> ff[i].vozenja[j].name; // Ime na vozenjeto
            cin >> ff[i].vozenja[j].vremeMin; // Vremetraenje
            cin >> ff[i].vozenja[j].cena; // Cena
            cin >> ff[i].vozenja[j].studnetskiPopust; // Popust
        }
    }
    print(ff, n);
    najdobarPark(ff, n);
    return 0;
}
