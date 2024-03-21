#include <iostream>
#include <cstring>
using namespace std;

enum tip {
	pop, rok, rap
};

class Pesna {
private:
	char ime[50];
	int minuti;
	tip kojTip;
public:
	Pesna(){}
	Pesna(char *_ime, int _minuti, tip _kojTip) {
		strcpy(ime, _ime);
		minuti = _minuti;
		kojTip = _kojTip;
	}
	char *getIme() {
		return ime;
	}
	int getMinuti() {
		return minuti;
	}
	tip getKojTip() {
		return kojTip;
	}
	char *setIme(char *_ime) {
		strcpy(ime, _ime);
	}
	int setMinuti(int _minuti) {
		minuti = _minuti;
	}
	tip setKojTip(tip _kojTip) {
		kojTip = _kojTip;
	}
	~Pesna(){}
public:
	void pecati() {
		cout<<'"'<< ime <<"-"<< minuti <<"minuti"<<endl;
	}
};
class CD {
private:
	Pesna *pesniSnimeni;
	int pesni;
	int vremeNaPesni;
public:
	CD(int maxVremeNaPesni): vremeNaPesni(maxVremeNaPesni), pesni(0) {
		vremeNaPesni = maxVremeNaPesni;
	}
	Pesna *getPesniSnimeni(){
		return pesniSnimeni;
	}
	int getPesni() {
		return pesni;
	}
	int getVreme() {
		return vremeNaPesni;
	}
	void setPesni(int _pesni) {
		pesni = _pesni;
	}
	void setVreme(int _vremeNaPesni) {
		vremeNaPesni = _vremeNaPesni;
	}
	~CD(){}
public:
	void dodadiPesna(Pesna p) {
		if(pesni<vremeNaPesni) {
			pesniSnimeni[pesni] = p;
		}
		else {
			cout<<"Nema Mesto"<<endl;
		}
	}
	void pecatiPesniPoTip(tip t) {
		for(int i=0;i<pesni;i++) {
			if(pesniSnimeni[i].getKojTip() == t) {
				pesniSnimeni[i].pecati();
			}
		}
	}
};
int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
        		omileno.getPesni()[i].pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getPesni(); i++)
				omileno.getPesniSnimeni()[i].pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
    }
return 0;
}