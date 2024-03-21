#include<iostream>
#include<cstring>
using namespace std;

class StockRecord {
private:
    char id[12];
    char name[50];
    double cenaAkcija;
    double momentalnaCena;
    int brojNaAkcii;

public:
    StockRecord(){}
    StockRecord(char _id[], char _name[], double _cenaAkcija, double _momentalnaCena, int _brojNaAkacii) {
        strcpy(id, _id);
        strcpy(name, _name);
        cenaAkcija = _cenaAkcija;
        momentalnaCena = _momentalnaCena;
        brojNaAkcii = _brojNaAkacii;
    }

    void setId(char _id[12]) {
        strcpy(id, _id);
    }

    void setName(char _name[50]) {
        strcpy(name, _name);
    }

    void setPrice(double price) {
        cenaAkcija = price;
    };

    double setNewPrice(double c) {
        momentalnaCena = c;
    }

    void setBrojNaAkcii(int akcii) {
        brojNaAkcii = akcii;
    }

    double value() {
        return brojNaAkcii * setNewPrice(momentalnaCena);
    }

    double profit() {
        return brojNaAkcii * (setNewPrice(momentalnaCena)-cenaAkcija);
    }
    int getBrojNaAkcii() {
        return brojNaAkcii;
    }

    ~StockRecord() {
    }
};

class Client {
private:
    char user[60];
    int id;
    StockRecord company[100];
    int objekti;
public:
    Client(char _user[],int _ajdi, StockRecord _company[], int _objekt) {
        strcpy(user, _user);
        id = _ajdi;
        objekti = _objekt;
        for(int i=0;i<_objekt;i++) {
            company[i] = _company[i];
        }
    }
    double totalValue() {
        double sum = 0;
        for(int i=0;i<objekti;i++) {
            sum += company[i].value();
        }
        return sum;
    }

    ~Client(){}
};

int main() {
    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    } else if (test == 2) {
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if (flag) {
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;
}
