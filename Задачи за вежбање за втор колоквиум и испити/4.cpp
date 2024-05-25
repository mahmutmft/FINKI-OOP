#include <iostream>
#include <cstring>

using namespace std;


class Pizza {
protected:
    char ime[20];
    char sostojki[100];
    double cena;
public:
    double getCena() {
        return cena;
    }

public:
    Pizza(char *ime = " ", char *sostojki = " ", int cena = 0) {
        strcpy(this->ime, ime);
        strcpy(this->sostojki, sostojki);
        this->cena = cena;
    }

    virtual double price() = 0;

    bool operator<(Pizza &p) {
        return this->price() < p.price();
    }

    friend ostream &operator<<(ostream &out, Pizza &p);
};

enum Size {
    mala, golema, familijarna
};

class FlatPizza : public Pizza {
protected:
    Size golemina;
public:
    FlatPizza(char *ime = " ", char *sostojki = " ", int cena = 0, Size golemina = Size(mala))
            : Pizza(ime, sostojki, cena) {
        this->golemina = golemina;
    }

    double price() override {
        if (golemina == 0) {
            return cena * 1.10;
        } else if (golemina == 1) {
            return cena * 1.20;
        } else {
            return cena * 1.30;
        }
    }

    friend ostream &operator<<(ostream &out, FlatPizza &p) {
        out << p.ime << ": " << p.sostojki << ", ";
        if (p.golemina == 0) {
            out << "small" << " - ";
        } else if (p.golemina == 1) {
            out << "large" << " - ";
        } else {
            out << "family" << " - ";
        }
        out << p.price() << endl;
        return out;
    }

};

class FoldedPizza : public Pizza {
protected:
    bool isBeloBrashno;
public:
    void setWhiteFlour(bool brashno) {
        this->isBeloBrashno = brashno;
    }

    FoldedPizza(char *ime = " ", char *sostojki = " ", int cena = 0)
            : Pizza(ime, sostojki, cena) {
        this->isBeloBrashno = true;
    }

    double price() override {
        double belo = 0;
        if (isBeloBrashno) {
            belo = cena * 1.10;
        } else {
            belo = cena * 1.30;
        }
        return belo;
    }

    friend ostream &operator<<(ostream &out, FoldedPizza &p) {
        out << p.ime << ": " << p.sostojki << ", ";
        if (p.isBeloBrashno) {
            out << "wf";
        } else {
            out << "nwf";
        }
        out << " - " << p.price();
        out << endl;
        return out;
    }

};

void expensivePizza(Pizza **niza, int n) {
    int index = 0;
    double max = niza[0]->price();
    for (int i = 1; i < n; i++) {
        if (niza[i]->price() > max) {
            max = niza[i]->price();
            index = i;
        }
    }
    cout << *niza[index];
}

ostream &operator<<(ostream &out, Pizza &p) {
    if (FoldedPizza *fold = dynamic_cast<FoldedPizza *>(&p)) {
        out << *fold;
    } else if (FlatPizza *flat = dynamic_cast<FlatPizza *>(&p)) {
        out << *flat;
    }
    return out;
}

int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        int s;
        cin >> s;
        FlatPizza fp(name, ingredients, inPrice, (Size) s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp1;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp2;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout << "Lower price: " << endl;
        if (*fp1 < *fp2)
            cout << fp1->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp1 < *fp3)
            cout << fp1->price() << endl;
        else cout << fp3->price() << endl;

        if (*fp4 < *fp2)
            cout << fp4->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp3 < *fp4)
            cout << fp3->price() << endl;
        else cout << fp4->price() << endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name, 20);

                cin.getline(ingredients, 100);
                cin >> inPrice;
                int s;
                cin >> s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size) s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name, 20);
                cin.getline(ingredients, 100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza(name, ingredients, inPrice);
                if (j % 2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi, num_p);


    }
    return 0;
}
