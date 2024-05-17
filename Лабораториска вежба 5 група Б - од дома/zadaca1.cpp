#include <iostream>
#include <cstring>

using namespace std;
enum tip {
    person, company
};
class Account {
private:
    string ime;
    int id;
    static int TOTAL;
    const static int ID_init;
    tip eTip;
    double saldo;
public:
    double getSaldo() const;

public:
    tip getETip() const;
    Account(string ime = " ", int eTip = 1, double saldo = 0) {
        TOTAL++;
        id = ID_init + TOTAL;
        this->ime = ime;
        this->eTip = (tip) eTip;
        this->saldo = saldo;
    }

    friend ostream &operator<<(ostream &o, Account &p) {
        cout << p.id << "-" << p.ime;
        if (p.eTip == person) {
            o << "person ";
        } else {
            o << "company ";
        }
        cout << p.saldo << endl;
        return o;
    }

    Account &operator-=(float vrednost) {
        saldo -= vrednost;
        return *this;
    }

    bool isSame(const Account& p){
        return id==p.id;
    }
};

int Account::TOTAL=0;
const int Account::ID_init=111110;

tip Account::getETip() const {
    return eTip;
}

double Account::getSaldo() const {
    return saldo;
}

class Bank {
private:
    string imeBanka;
    Account *smetki;
    int n = 0;
public:
    Bank(string imeBanka = " ") {
        this->imeBanka = imeBanka;
        smetki = nullptr;
        n = 0;
    }
    Bank(const Bank& p){
        this->imeBanka = p.imeBanka;
        this->n = p.n;
        smetki= new Account[n];
        for(int i=0;i<n;i++){
            smetki[i] = p.smetki[i];
        }
    }
    Bank& operator=(const Bank& p){
        if(this != &p){
            delete[] smetki;
            this->imeBanka = p.imeBanka;
            this->n = p.n;
            smetki= new Account[n];
            for(int i=0;i<n;i++){
                smetki[i] = p.smetki[i];
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &o, Bank &p) {
        o << p.imeBanka << endl;
        for (int i = 0; i < p.n; i++) {
            o << p.smetki[i];
        }
        return o;
    }
    Bank& operator+=(const Account& p){
        for(int i=0;i<n;i++){
            if(smetki[i].isSame(p)){
                return *this;
            }
        }
        Account *tmp=new Account[n+1];
        for(int i=0;i<n;i++){
            tmp[i] = smetki[i];
        }
        tmp[n++]=p;
        delete [] smetki;
        smetki = tmp;
        return *this;
    }
    bool operator<(const Bank& p){
        return n<p.n;
    }
    void bankFee(){
        for(int i =0;i<n;i++){
            if(smetki[i].getETip() == person){
                float fee = smetki[i].getSaldo()*0.008;
                smetki[i]-=fee;
            }
            else{
                float fee = smetki[i].getSaldo()*0.015;
                smetki[i] -= fee;
            }
        }
    }
    ~Bank(){
        delete [] smetki;
    }
};

int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 0) {
        cout << "TESTING ACCOUNT CONSTRUCTOR" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex", 1, 500000);
        Account account3("Anna", 0, 8700);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "TESTING ACCOUNT OPERATOR <<" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex", 1, 500000);
        Account account3("Anna", 0, 8700);
        cout << account1;
        cout << account2;
        cout << account3;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING ACCOUNT OPERATOR -=" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        cout << account1;
        cout << account2;
        cout << account3;
        account1 -= 350;
        account2 -= 20000;
        account3 -= 500;
        cout << "===== DECREASE =====" << endl;
        cout << account1;
        cout << account2;
        cout << account3;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING BANK CONSTRUCTOR and <<" << endl;
        Bank bank1("Capital One Bank");
        cout << bank1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 4) {
        cout << "TESTING BANK OPERATOR += and <<" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        cout << bank1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING BANK OPERATOR += and <<" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        bank1 += account1;
        cout << bank1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 6) {
        cout << "TESTING BANK COPY-CONSTRUCTOR and OPERATOR =" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Account account4("Umbrella Corporation", 1, 300000);
        Account account5("Theo", 0, 15500);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        Bank bank2(bank1);
        Bank bank4;
        {
            Bank bank3("First National Bank");
            bank3 += account4;
            bank3 += account5;
            bank4 = bank3;
        }
        cout << bank2;
        cout << bank4;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 7) {
        cout << "TESTING BANK OPERATOR < " << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Account account4("Umbrella Corporation", 1, 300000);
        Account account5("Theo", 0, 15500);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        Bank bank3("First National Bank");
        bank3 += account4;
        bank3 += account5;
        if (bank1 < bank3) {
            cout << "TEST FAILED" << endl;
        } else {
            cout << "TEST PASSED" << endl;
        }
    } else if (testCase == 8) {
        cout << "TESTING METHOD bankFee()" << endl;
        char name[30], name1[30];
        int type, numberOfBanks, numberOfAccounts;
        float money;
        cin >> numberOfBanks;
        cin.ignore();
        Bank banks[10];
        for (int i = 0; i < numberOfBanks; i++) {
            cin.getline(name, 20);
            banks[i] = Bank(name);
            cin >> numberOfAccounts;
            cin.ignore();
            Account accounts[10];
            for (int j = 0; j < numberOfAccounts; j++) {
                cin >> name1 >> type >> money;
                cin.ignore();
                accounts[j] = Account(name1, type, money);
                banks[i] += accounts[j];
            }
        }
        for (int i = 0; i < numberOfBanks; i++) {
            cout << banks[i];
            cout << "FEE-PAID" << endl;
            banks[i].bankFee();
            cout << banks[i];
        }
    } else if (testCase == 9) {
        cout << "TESTING METHOD leastLiquid()" << endl;
        char name[30], name1[30];
        int type, numberOfBanks, numberOfAccounts;
        float money;
        cin >> numberOfBanks;
        cin.ignore();
        Bank banks[10];
        for (int i = 0; i < numberOfBanks; i++) {
            cin.getline(name, 20);
            banks[i] = Bank(name);
            cin >> numberOfAccounts;
            cin.ignore();
            Account accounts[10];
            for (int j = 0; j < numberOfAccounts; j++) {
                cin >> name1 >> type >> money;
                cin.ignore();
                accounts[j] = Account(name1, type, money);
                banks[i] += accounts[j];
            }
        }
        //cout << leastLiquid(banks, numberOfBanks);
    }
    return 0;
}