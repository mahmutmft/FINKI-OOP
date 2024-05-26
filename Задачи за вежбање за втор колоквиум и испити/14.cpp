#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class SMS{
protected:
    char pretplatnik[13];
    double osnovnaCena;
    static int danok;
public:
    SMS(char *pretpatnik = " ", double osnovnaCena = 0){
        strcpy(this->pretplatnik, pretpatnik);
        this->osnovnaCena = osnovnaCena;
    }
    virtual double SMS_cena() = 0;

    friend ostream &operator<<(ostream &out, SMS &p){
        out<<"Tel: "<<p.pretplatnik<<" - cena: "<<p.SMS_cena()<<"den."<<endl;
        return out;
    }
};

int SMS::danok = 18;

class RegularSMS : public SMS{
protected:
    char msg[1000];
    bool roaming;
    static int danok1;

public:
    static void set_rProcent(int i) {
        danok1 = i;
    }
    RegularSMS(char *pretpatnik = " ", double osnovnaCena = 0, char *msg = " ", bool roaming = false)
    : SMS(pretpatnik, osnovnaCena)
    {
        strcpy(this->msg, msg);
        this->roaming = roaming;
    }
    double SMS_cena() override {
        int n = strlen(msg);
        int m = ceil(n / 160.0); 16.19
        double cena = osnovnaCena * m;
        if (roaming) {
            return cena * (1 + danok1 / 100.0);
        } else {
            return cena * (1 + danok / 100.0);
        }
    }
};

int RegularSMS::danok1 = 300;

class SpecialSMS : public SMS{
protected:
    bool humano;
    static int danok2;
public:
    static void set_sProcent(int p) {
        danok2 = p;
    }
    SpecialSMS(char *pretpatnik = " ", double osnovnaCena = 0, bool humano = false)
    : SMS(pretpatnik, osnovnaCena){
        this->humano = humano;
    }
    double SMS_cena() override {
        if (humano) {
            return osnovnaCena;
        } else {
            return osnovnaCena * (1 + danok2 / 100.0);
        }
    }
};

int SpecialSMS::danok2 = 150;

void vkupno_SMS(SMS** poraka, int n){
    int regularni = 0;
    int specijalni = 0;
    double cenaR = 0;
    double cenaS = 0;
    for(int i=0;i<n;i++){
        RegularSMS *regularSmS = dynamic_cast<RegularSMS*>(poraka[i]);
        SpecialSMS *ssms = dynamic_cast<SpecialSMS*>(poraka[i]);
        if(regularSmS){
            regularni++;
            cenaR += regularSmS->SMS_cena();
        }
        else if(ssms){
            specijalni++;
            cenaS += ssms->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<regularni<<" regularni SMS poraki i nivnata cena e: "<<cenaR<<endl;
    cout<<"Vkupno ima "<<specijalni<<" specijalni SMS poraki i nivnata cena e: "<<cenaS<<endl;
}



int main(){

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS  **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena; //20
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam; // 0
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2){
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3){
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i<n; i++){

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;

                sms[i] = new RegularSMS(tel, cena, msg, roam);

            }
            else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4){
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;
        RegularSMS::set_rProcent(p);
        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;

        delete sms1, sms2;
    }
    if (testCase == 5){
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;
        SpecialSMS::set_sProcent(p);
        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;

        delete sms1, sms2;
    }

    return 0;
}
