#include <iostream>
#include <cstring>

using namespace std;

class AlcoholicDrink {
protected:
    char name[100];
    char country[100];
    float alcoTest;
    float basePrice;
    static int discount;

public:
    AlcoholicDrink(float alcoTest = 0, const char *name = "", const char *country = "", float basePrice = 0) {
        strcpy(this->name, name);
        strcpy(this->country, country);
        this->alcoTest = alcoTest;
        this->basePrice = basePrice;
    }

    friend ostream &operator<<(ostream &os, const AlcoholicDrink &drink) {
        os << drink.name << " " << drink.country << " " << drink.alcoTest << " " << drink.computePrice();
        return os;
    }

    bool operator<(const AlcoholicDrink &p) const {
        return computePrice() < p.computePrice();
    }

    virtual float computePrice() const = 0;

    static void changeDiscount(int d) {
        discount = d;
    }

    static void total(AlcoholicDrink **ad, int n) {
        float totalPrice = 0;
        for (int i = 0; i < n; i++) {
            totalPrice += ad[i]->computePrice();
        }
        cout << "Total price: " << totalPrice << endl;
        cout << "Total price with discount: " << totalPrice * (1 - discount / 100.0) << endl;
    }
};

int AlcoholicDrink::discount = 5;

class Beer : public AlcoholicDrink {
protected:
    bool isNeshto;

public:
    Beer(float alcoTest = 0, const char *name = "", const char *country = "", float basePrice = 0, bool isNeshto = false)
            : AlcoholicDrink(alcoTest, name, country, basePrice), isNeshto(isNeshto) {}

    float computePrice() const override {
        float price = basePrice;
        if (strcmp(country, "Germany") == 0) {
            price *= 1.05;
            if (isNeshto) {
                price *= 1.1;
            }
        }
        return price;
    }
};

class Wine : public AlcoholicDrink {
protected:
    int year;
    char grapesType[20];

public:
    Wine(float alcoTest = 0, const char *name = "", const char *country = "", float basePrice = 0, int year = 0,
         const char *grapesType = "") : AlcoholicDrink(alcoTest, name, country, basePrice), year(year) {
        strcpy(this->grapesType, grapesType);
    }

    float computePrice() const override {
        float price = basePrice;
        if (strcmp(country, "Italy") == 0) {
            price *= 1.05;
            if (year > 2005) {
                price *= 1.15;
            }
        }
        return price;
    }
};

void lowestPrice(AlcoholicDrink **a, int n) {
    int index = 0;
    float minPrice = a[0]->computePrice();
    for (int i = 1; i < n; i++) {
        if (a[i]->computePrice() < minPrice) {
            minPrice = a[i]->computePrice();
            index = i;
        }
    }
    cout << "Alcoholic drink with the lowest price: " << *a[index] << endl;
}

int main() {
    int testCase;
    cin >> testCase;
    float p;
    char name[100];
    char country[100];
    float price;
    bool mainI;
    int year;
    char grape[20];
    if (testCase == 1) {
        cout << "===== TESTING CONSTRUCTORS ======" << endl;
        cin >> p;
        cin >> name;
        cin >> country;
        cin >> price;
        cin >> mainI;
        Beer b(p, name, country, price, mainI);
        cout << b << endl;
        cin >> p;
        cin >> name;
        cin >> country;
        cin >> price;
        cin >> year;
        cin >> grape;
        Wine w(p, name, country, price, year, grape);
        cout << w << endl;

    } else if (testCase == 2) {
        cout << "===== TESTING LOWEST PRICE ======" << endl;
        int n;
        cin >> n;
        AlcoholicDrink **ad = new AlcoholicDrink *[n];
        for (int i = 0; i < n; ++i) {
            cin >> p;
            cin >> name;
            cin >> country;
            cin >> price;

            if (i % 2 == 1) {
                cin >> mainI;
                ad[i] = new Beer(p, name, country, price, mainI);
            } else {
                cin >> year;
                cin >> grape;
                ad[i] = new Wine(p, name, country, price, year, grape);
            }
        }

        lowestPrice(ad, n);
        for (int i = 0; i < n; ++i) {
            delete ad[i];
        }
        delete[] ad;
    } else if (testCase == 3) {
        cout << "===== TESTING DISCOUNT STATIC ======" << endl;
        int n;
        cin >> n;
        AlcoholicDrink **ad = new AlcoholicDrink *[n];
        for (int i = 0; i < n; ++i) {
            cin >> p;
            cin >> name;
            cin >> country;
            cin >> price;
            if (i % 2 == 1) {
                cin >> mainI;
                ad[i] = new Beer(p, name, country, price, mainI);
            } else {
                cin >> year;
                cin >> grape;
                ad[i] = new Wine(p, name, country, price, year, grape);
            }
        }
        AlcoholicDrink::total(ad, n);
        int d;
        cin >> d;
        AlcoholicDrink::changeDiscount(d);
        AlcoholicDrink::total(ad, n);
        for (int i = 0; i < n; ++i) {
            delete ad[i];
        }
        delete[] ad;
    }

}

