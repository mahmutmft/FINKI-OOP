#include <iostream>
#include <cstring>
using namespace std;

class InvalidSeatNumberException{
public:
    void pecati(){
        cout<<"Invalid Seat Number Exception";
    }
};

class Flight {
protected:
    char codeLet[40];
    char gradZaminuvanje[100];
    char gradPristap[100];
    float cenaLet;
    float cenaBagaz;
public:
    Flight(const char *codeLet = " ", const char *gradZaminuvanje = " ", const char *gradPristap = " ", float cenaLet = 0, float cenaBagaz = 0) {
        strcpy(this->codeLet, codeLet);
        strcpy(this->gradZaminuvanje, gradZaminuvanje);
        strcpy(this->gradPristap, gradPristap);
        this->cenaLet = cenaLet;
        this->cenaBagaz = cenaBagaz;
    }
    virtual float calculateTotalPrice() const {
        return cenaLet + cenaBagaz;
    }
    virtual void displayInfo() const {
       cout<<codeLet;
    }
};

class EconomyFlight : public Flight {
protected:
    char brojSedishte[4];
    static float LOYAL_DISCOUNT;
public:
    EconomyFlight(Flight &f, char *brojSedishte = " "): Flight(f){
        strcpy(this->brojSedishte, brojSedishte);
    }
    static void setLoyaltyDiscount(float discount) {
        LOYAL_DISCOUNT = discount;
    }
    float calculateTotalPrice() const override {
        if (brojSedishte[0] != 'A' && brojSedishte[0] != 'B' && brojSedishte[0] != 'C' &&
            brojSedishte[0] != 'D' && brojSedishte[0] != 'E' && brojSedishte[0] != 'F') {
            throw InvalidSeatNumberException();
        }
        float cena = 0;
        if (brojSedishte[0] == 'C' || brojSedishte[0] == 'F') {
            cena += cenaLet * 0.3;
        }
        return cena + cenaBagaz;
    }
    void displayInfo() const override {
        Flight::
    }
};

float EconomyFlight::LOYAL_DISCOUNT = 0.2;

int main() {
    int testCase;
    cin>>testCase;
    char code[100];
    char from[100];
    char to[100];
    double price;
    double baggagePrice;
    char seatNumber[4];

    if(testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        int n;
        cin>>n;
        for(int i=0; i<n;i++){
            cin>>code>>from>>to>>price>>baggagePrice>>seatNumber;
            Flight f = Flight(code, from, to, price, baggagePrice);
            EconomyFlight ec = EconomyFlight(f, seatNumber);
            ec.displayInfo();
        }
    }
    if(testCase == 2){
        cout << "===== Testiranje na isklucoci ======" << endl;
        int n;
        cin>>n;
        for(int i=0; i<n;i++){
            cin>>code>>from>>to>>price>>baggagePrice>>seatNumber;
            Flight f = Flight(code, from, to, price, baggagePrice);
            EconomyFlight ec = EconomyFlight(f, seatNumber);
            ec.displayInfo();
        }
    }
    if(testCase == 3){
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>code>>from>>to>>price>>baggagePrice>>seatNumber;
        Flight f = Flight(code, from, to, price, baggagePrice);
        EconomyFlight ec = EconomyFlight(f, seatNumber);
        ec.displayInfo();
        EconomyFlight::setLoyaltyDiscount(50);
        ec.displayInfo();
    }

    return 0;
}
