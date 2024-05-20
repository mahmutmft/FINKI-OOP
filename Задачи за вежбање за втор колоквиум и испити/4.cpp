#include <cstring>
#include <iostream>

using namespace std;
enum Size {
    mala, golema, familijarna
};

class Pizza {
protected:
    string ime;
    string sostojki;
    double cena;
public:
    Pizza(const string ime = "", const string sostojki = " ", double cena = 0) {
        this->ime = ime;
        this->sostojki = sostojki;
        this->cena = cena;
    }

    virtual double price() const = 0;
};

class FlatPizza : virtual public Pizza {
protected:
    Size picaSize;
public:
    FlatPizza(const string ime = "", const string sostojki = " ", double cena = 0, Size picaSize = Size(mala))
            : Pizza(ime, sostojki, cena) {
        this->picaSize = picaSize;
    }

    double price() {
        if (picaSize == 0) {
            return cena * 0.1;
        } else if (picaSize == 1) {
            return cena * 0.2;
        } else {
            return cena * 0.3;
        }
    }

    friend ostream &operator<<(ostream &o, const FlatPizza &p) {
        o << p.ime << ": " << p.sostojki << ", " << p.picaSize << " - " << p.cena;
        return o;
    }

};

class FoldedPizza : public Pizza {
protected:
    bool isBeloBrashno;
public:
    FoldedPizza(const string ime = "", const string sostojki = " ", double cena = 0)
            : Pizza(ime, sostojki, cena) {
    }

    void setWhiteFlour(bool isBeloBrashno) {
        FoldedPizza::isBeloBrashno = isBeloBrashno;
    }

    double price() {
        if (isBeloBrashno) {
            return cena * 0.1;
        } else {
            return cena * 0.3;
        }
    }

    friend ostream &operator<<(ostream &out, const FoldedPizza &p) {
        out << p.ime << ": " << p.sostojki << ", ";
        if (isBeloBrashno) {
            out << "wf";
        } else {
            out << "nwf";
        }
        out << " - " << p.cena;
        return out;
    }

};
bool operator<(const FoldedPizza &p1, const FlatPizza &p2) {
    return p1.price()
}

bool operator<(const FlatPizza *p1, const FlatPizza *p2){
    return p1->price() < p2->price();
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
