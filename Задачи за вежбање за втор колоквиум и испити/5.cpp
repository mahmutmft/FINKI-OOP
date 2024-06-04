#include <iostream>
#include <cstring>

using namespace std;

int MAX = 50;

enum vidKupuvac {
    standard, loyal, vip
};

class Customer {
private:
    char name[50];
    char eMail[50];
    int popust;
    int plusPopust;
    int n;
    vidKupuvac kupuvac;
public:
    void setKupuvac(vidKupuvac kupuvac) {
        Customer::kupuvac = kupuvac;
    }

    vidKupuvac getKupuvac() {
        return kupuvac;
    }

    int getkupenProzvod() {
        return n;
    }
    char *getName() {
        return name;
    }

    Customer(char *name = " ", char *email = " ",vidKupuvac kupuvac = vidKupuvac(standard), int n = 0, int popust = 0,
             int plustpopust = 0) {
        strcpy(this->name, name);
        strcpy(this->eMail, email);
        this->kupuvac = kupuvac;
        this->n = n;
        this->popust = popust;
        this->plusPopust = plustpopust;
    }

    int clubKarticka() {
        int popustKlub = 0;
        if (kupuvac == standard) {
            return 0;
        } else if (kupuvac == loyal) {
            popustKlub = 10;
        } else if (kupuvac == vip) {
            popustKlub = 20;
        }
        return popustKlub;
    }

    friend ostream &operator<<(ostream &os, Customer &customer) {
        os << customer.name << endl;
        os << customer.eMail << endl;
        os << customer.n << endl;
        if (customer.kupuvac == 2) {
            os << "vip";
        } else if (customer.kupuvac == 1) {
            os << "loyal";
        } else {
            os << "standard";
        }
        os << " " << customer.clubKarticka() << endl;
        return os;
    }
};

class UserExistsException {
public:
    void print() {
        cout << "The user already exists in the list" << endl;
    }
};

class FINKI_bookstore {
private:
    Customer *niza;
    int n;
public:
    FINKI_bookstore(int n = 0) {
        this->niza = new Customer[n];
        for (int i = 0; i < n; i++) {
            this->niza[i] = niza[i];
        }
        this->n = n;
    }

    FINKI_bookstore &operator+=(Customer &p) {
        Customer *tmp = new Customer[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = niza[i];
        }
        tmp[n++] = p;
        delete[] niza;
        niza = tmp;
        return *this;
    }

    void update() {
        for (int i = 0; i < n; i++) {
            if (niza[i].getkupenProzvod() > 5 && niza[i].getkupenProzvod() < 10) {
                niza[i].setKupuvac(loyal);
            } else if (niza[i].getkupenProzvod() > 10) {
                niza[i].setKupuvac(vip);
            }
        }
    }

    friend ostream &operator<<(ostream &out, FINKI_bookstore &p) {
        for (int i = 0; i < p.n; ++i) {
            cout<<p.niza[i]<<endl;
        }
        return out;
    }
};


int main() {
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1) {
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (vidKupuvac) tC, numProducts);
        cout << c;

    }

    if (testCase == 2) {
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (vidKupuvac) tC, numProducts);
        cout << c;

        //c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3) {
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (vidKupuvac) tC, numProducts);
            customers[i] = c;
        }

        //fc.setCustomers(customers, n);

        cout << fc << endl;
    }

    if (testCase == 4) {
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (vidKupuvac) tC, numProducts);
            customers[i] = c;
        }

       // fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (vidKupuvac) tC, numProducts);
        fc += c;
        cout << fc;
    }

    if (testCase == 5) {
        cout << "===== Test Case - operator+= (exception!!!) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (vidKupuvac) tC, numProducts);
            customers[i] = c;
        }

      //  fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;

       // fc += c;

        cout << fc;
    }

    if (testCase == 6) {
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (vidKupuvac) tC, numProducts);
            customers[i] = c;
        }

       // fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
