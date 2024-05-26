#include<iostream>
#include<string.h>

using namespace std;

class StudentKurs {
protected:
    char ime[30];
    int ocenka;
    bool daliUsno;
    static int MAX;
public:
    void setMAX(int max) {
        MAX = max;
    }

    StudentKurs(char *ime, int finalenIspit) {
        strcpy(this->ime, ime);
        this->ocenka = finalenIspit;
        this->daliUsno = false;
    }
    //дополни ја класата
};

int StudentKurs::MAX = 10;


class StudentKursUsno : public StudentKurs{
protected:

};

class KursFakultet {
private:
    char naziv[30];
    StudentKurs *studenti[20];
    int broj;

public:
    KursFakultet(char *naziv, StudentKurs **studenti, int broj) {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++) {
            //ako studentot ima usno isprashuvanje
            if (studenti[i]->getDaliUsno()) {
                this->studenti[i] = new StudentKursUsno(*dynamic_cast<StudentKursUsno *>(studenti[i]));
            } else this->studenti[i] = new StudentKurs(*studenti[i]);
        }
        this->broj = broj;
    }

    ~KursFakultet() {
        for (int i = 0; i < broj; i++) delete studenti[i];
    }

    //дополни ја класата
};

int main() {

    StudentKurs **niza;
    int n, m, ocenka;
    char ime[30], opisna[10];
    bool daliUsno;
    cin >> n;
    niza = new StudentKurs *[n];
    for (int i = 0; i < n; i++) {
        cin >> ime;
        cin >> ocenka;
        cin >> daliUsno;
        if (!daliUsno)
            niza[i] = new StudentKurs(ime, ocenka);
        else
            niza[i] = new StudentKursUsno(ime, ocenka);
    }

    KursFakultet programiranje("OOP", niza, n);
    for (int i = 0; i < n; i++) delete niza[i];
    delete[] niza;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> ime >> opisna;
        programiranje.postaviOpisnaOcenka(ime, opisna);
    }

    StudentKurs::setMAX(9);

    programiranje.pecatiStudenti();

}
