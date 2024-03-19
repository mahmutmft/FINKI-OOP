#include <iostream>
using namespace std;
struct FootballPlayer{
    char ime[100];
    int brojNaDres;
    int dadeniGolovi;
};
struct FootballTeam{
    char imeNaTimot[100];
    FootballPlayer igraci[11];
};
void bestTeam(FootballTeam *teams, int n) {
    int maxGolovi = -1;
    int najdobarTim = -1;
    for (int i = 0; i < n; i++) {
        int golovi = 0;
        for (int j = 0; j < 11; j++) {
            golovi += teams[i].igraci[j].dadeniGolovi;
        }
        if (golovi > maxGolovi) {
            maxGolovi = golovi;
            najdobarTim = i;
        }
    }
    if (najdobarTim != -1) {
        cout << "Najdobar tim e: " << teams[najdobarTim].imeNaTimot << endl;
    }
}

int main(){
    int n;
    cin>>n;
    FootballTeam timovi[11];
    for(int i=0;i<n;i++){
        cin>>timovi[i].imeNaTimot;
        for(int j=0;j<11;j++){
            cin>>timovi[i].igraci[j].ime;
            cin>>timovi[i].igraci[j].brojNaDres;
            cin>>timovi[i].igraci[j].dadeniGolovi;
        }
    }
    bestTeam(timovi,n);
}