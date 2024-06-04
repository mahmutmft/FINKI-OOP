#include <iostream>
#include <cstring>

using namespace std;

class Product {
private:
    char nameProduct[100];
    int id;
    char kategorija[100];
    double cena;
    int kolicina;
public:
    Product() {
    }

    Product(char *nameProduct, int id, char *kategorija, double cena, int kolicina) {
        strcpy(this->nameProduct, nameProduct);
        strcpy(this->kategorija, kategorija);
        this->cena = cena;
        this->id = id;
        this->kolicina = kolicina;
    }

    char *getName() {
        return nameProduct;
    }

    int getId() const {
        return id;
    }

    char *getCategory() {
        return kategorija;
    }

    double getPrice() const {
        return cena;
    }

    int getQuantity() const {
        return kolicina;
    }

    void setName(char *name) {
        strcpy(this->nameProduct, name);
    }

    void setCategory(char *kategori) {
        strcpy(this->kategorija, kategori);
    }

    void setId(int id1) {
        this->id = id1;
    }

    void setPrice(double price1) {
        this->cena = price1;
    }

    void setQuantity(int quant) {
        this->kolicina = quant;
    }

    void print() {
        cout << "Name: " << nameProduct << ", Id: " << id << ", Price: " << cena << ", Quantity: " << kolicina << endl;
    }
};

void printByCategory(Product *products, int n, const char *category) {
    double suma = 0;
    cout << "Category: " << category << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].getCategory(), category) == 0) {
            products[i].print();
            suma += products[i].getPrice() * products[i].getQuantity();
        }

    }
    cout<<"Total sum : "<<suma<<endl;
}

int main() {
    int m;
    cin >> m;
    if (m == 0) {
        cout << "---Testing constructor with arguments and print()---" << "\n";
        char name[100] = {'B', 'o', 'o', 'k'};
        int id = 1;
        char category[100] = {'B', 'o', 'o', 'k', 's'};
        double price = 14.99;
        int quantity = 3;

        Product product = Product(name, id, category, price, quantity);

        product.print();
    } else if (m == 1) {
        cout << "---Testing get and set methods---" << "\n";
        char name[100] = {'B', 'o', 'o', 'k'};
        int id = 1;
        char category[100] = {'B', 'o', 'o', 'k', 's'};
        double price = 14.99;
        int quantity = 3;
        Product product;
        product.setName(name);
        product.setId(id);
        product.setCategory(category);
        product.setPrice(price);
        product.setQuantity(quantity);
        cout << "Name: " << product.getName() << endl;
        cout << "Id: " << product.getId() << endl;
        cout << "Category: " << product.getCategory() << endl;
        cout << "Price: " << product.getPrice() << endl;
        cout << "Quantity: " << product.getQuantity() << endl;

    } else if (m == 2) {
        const int numProducts = 8;
        Product products[numProducts];

        for (int i = 0; i < numProducts; ++i) {
            char name[100];
            int id;
            char category[100];
            double price;
            int quantity;


            cin >> name >> id >> category >> price >> quantity;

            products[i] = Product(name, id, category, price, quantity);
        }


        cout << "---Testing function---" << "\n";
        printByCategory(products, numProducts, "Electronics");
        cout << endl;
        printByCategory(products, numProducts, "Clothing");
        cout << endl;
        printByCategory(products, numProducts, "Books");
    }
    return 0;
}
