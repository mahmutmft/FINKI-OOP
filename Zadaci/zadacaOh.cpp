#include <iostream>
#include <cstring>
using namespace std;

class Product {
private:
    int ProductID;
    double price;
    bool isPerishable;
public:
    ~Product(){}
    Product(int _ProductID = 0, double _price = 0, bool _isPerishable = false) {
        ProductID = _ProductID;
        price = _price;
        isPerishable = _isPerishable;
    }
    Product(const Product &other) {
        ProductID = other.ProductID;
        price = other.price;
        isPerishable = other.isPerishable;
    }
    int getProductId() const {
        return ProductID;
    }

    double getPrice() const {
        return price;
    }

    bool getIsPerishable() const {
        return isPerishable;
    }
    friend ostream& operator<<(ostream& os, const Product& p) {
        os << "Product ID: " << p.ProductID << ", Price: " << p.price << ", Perishable: ";
        if (p.isPerishable) {
            os << "Yes";
        } else {
            os << "No";
        }
        return os;
    }
    Product& operator=(const Product &other) {
        if (this != &other) {
            ProductID = other.ProductID;
            price = other.price;
            isPerishable = other.isPerishable;
        }
        return *this;

    }
};
class GroceryStore{
private:
    char* ownerName;
    double totalRevenue;
    Product* products;
    int numProducts;
public:
    GroceryStore(const char* _ownerName, double _totalRevenue, Product* _products, int _numProducts) {
        ownerName = new char[strlen(_ownerName) + 1];
        strcpy(ownerName, _ownerName);
        totalRevenue = _totalRevenue;
        products = new Product[_numProducts];
        for (int i = 0; i < _numProducts; ++i) {
            products[i] = _products[i];
        }
        numProducts = _numProducts;
    }
    GroceryStore(const GroceryStore& other) {
        ownerName = new char[strlen(other.ownerName) + 1];
        strcpy(ownerName, other.ownerName);
        totalRevenue = other.totalRevenue;
        numProducts = other.numProducts;
        products = new Product[numProducts];
        for (int i = 0; i < numProducts; ++i) {
            products[i] = other.products[i];
        }
    }
    GroceryStore& operator=(const GroceryStore& other) {
        if (this != &other) {
            delete[] ownerName;
            delete[] products;
            ownerName = new char[strlen(other.ownerName) + 1];
            strcpy(ownerName, other.ownerName);
            totalRevenue = other.totalRevenue;
            numProducts = other.numProducts;
            products = new Product[numProducts];
            for (int i = 0; i < numProducts; ++i) {
                products[i] = other.products[i];
            }
        }
        return *this;
    }
    GroceryStore& operator+=(const GroceryStore& other) {
        totalRevenue += other.totalRevenue;
        Product* cProducts = new Product[numProducts + other.numProducts];
        for (int i = 0; i < numProducts; ++i) {
            cProducts[i] = products[i];
        }
        for (int i = 0; i < other.numProducts; ++i) {
            cProducts[numProducts + i] = other.products[i];
        }
        delete[] products;
        products = cProducts;
        numProducts += other.numProducts;
        return *this;
    }
    double getRevenue() const {
        return totalRevenue;
    }
    const Product* getProductInventory() const {
        return products;
    }
    ~GroceryStore() {
        delete[] ownerName;
        delete[] products;
    }
};

int main() {
    cout << "Hello World" << endl;
    return 0;
}
