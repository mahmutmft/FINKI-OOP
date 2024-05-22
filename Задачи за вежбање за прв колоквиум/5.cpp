#include <iostream>
#include <cstring>

using namespace std;

class Gitara {
private:
    char seriskiBroj[25];
    double nabavnaCena;
    int godinaProizvedeno;
    char tip[40];
public:
    Gitara(char tip[40] = " ", char *seriskiBroj = " ", int godinaProizvedeno = 0, double nabavnaCena = 0) {
        strcpy(this->seriskiBroj, seriskiBroj);
        this->nabavnaCena = nabavnaCena;
        this->godinaProizvedeno = godinaProizvedeno;
        strcpy(this->tip, tip);
    }

    bool daliIsti(Gitara &p) {
        return strcmp(this->seriskiBroj, p.seriskiBroj);
    }

    void pecati() {
        cout << seriskiBroj << " " << tip << " " << nabavnaCena << endl;
    }
    int getGodinaProizvedeno() const {
        return godinaProizvedeno;
    }
    double getNabavnaCena() const {
        return nabavnaCena;
    }
    const char *getTip() const {
        return tip;
    }

    const char *getSeriski() const {
        return seriskiBroj;
    }

};

class Magacin {
private:
    char imeMagacin[30];
    char lokacijaMagacin[60];
    Gitara *niza;
    int n;
    int godinaOpening;
public:
    Magacin(char *imeMagacin = " ", char *lokacijaMagacin = " ", int godinaOpening = 0, int n = 0) {
        strcpy(this->imeMagacin, imeMagacin);
        strcpy(this->lokacijaMagacin, lokacijaMagacin);
        this->godinaOpening = godinaOpening;
        this->n = n;
        niza = new Gitara[n];
    }

    Magacin(const Magacin &p) {
        strcpy(this->imeMagacin, p.imeMagacin);
        strcpy(this->lokacijaMagacin, p.lokacijaMagacin);
        this->godinaOpening = p.godinaOpening;
        this->n = p.n;
        niza = new Gitara[p.n];
        for (int i = 0; i < p.n; i++) {
            this->niza[i] = p.niza[i];
        }
    }

    Magacin &operator=(const Magacin &p) {
        if (this != &p) {
            delete[]niza;
            strcpy(this->imeMagacin, p.imeMagacin);
            strcpy(this->lokacijaMagacin, p.lokacijaMagacin);
            this->godinaOpening = p.godinaOpening;
            this->n = p.n;
            niza = new Gitara[p.n];
            for (int i = 0; i < p.n; i++) {
                this->niza[i] = p.niza[i];
            }
        }
        return *this;
    }
    double vrednost(){
        double vrednost = 0;
        for(int i=0;i<n;i++){
            vrednost += niza[i].getNabavnaCena();
        }
        return vrednost;
    }
    void dodadi(Gitara & g)
    {
        Gitara * tmp = new Gitara[n +1];
        for(int i=0;i<n;i++)
            tmp[i] = niza[i];
        tmp[n++]=g;
        delete [] niza;
        niza=tmp;
    }
    void prodadi(Gitara & g)
    {
        int newBr = 0;
        for(int i=0;i<n;i++)
        {
            if(niza[i].daliIsti(g)==false)
            {
                newBr++;
            }
        }
        Gitara * tmp = new Gitara[n];
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(niza[i].daliIsti(g)==false)
            {
                tmp[j] = niza[i];
                j++;
            }
        }
        delete [] niza;
        niza = tmp;
        n = newBr;
    }
    void pecati(bool daliNovi)
    {
        cout<<imeMagacin<<" "<<lokacijaMagacin<<endl;
        for(int i=0;i<n;i++)
        {
            if(daliNovi==true&&niza[i].getGodinaProizvedeno()>godinaOpening)
            {
                niza[i].pecati();
            }
            else if(daliNovi==false){
                niza[i].pecati();
            }
        }
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodinaProizvedeno() << endl;
        cout << g.getNabavnaCena() << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    } else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    } else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}
