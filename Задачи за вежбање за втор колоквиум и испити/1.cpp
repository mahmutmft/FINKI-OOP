#include <iostream>
#include <cstring>

using namespace std;

class Book {
protected:
    char ISBN_number[20];
    char title[50];
    char author[30];
    double defaultPrice;
public:
    double getDefaultPrice() {
        return defaultPrice;
    }

    void setISBN(char isbn[20]) {
        strcpy(this->ISBN_number, isbn);
    }

public:
    Book(char *ISBN_number = " ", char *title = " ", char *author = " ", double defaultPrice = 0) {
        strcpy(this->ISBN_number, ISBN_number);
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->defaultPrice = defaultPrice;
    }

    Book(const Book &p) {
        strcpy(this->ISBN_number, p.ISBN_number);
        strcpy(this->title, p.title);
        strcpy(this->author, p.author);
        this->defaultPrice = p.defaultPrice;
    }

    Book &operator=(const Book &p) {
        if (this != &p) {
            strcpy(this->ISBN_number, p.ISBN_number);
            strcpy(this->title, p.title);
            strcpy(this->author, p.author);
            this->defaultPrice = p.defaultPrice;
        }
        return *this;
    }

    virtual double bookPrice() = 0;

    bool operator>(const Book &p) const {
        return this->defaultPrice > p.defaultPrice;
    }

    friend ostream &operator<<(ostream &out, Book &p) {
        out << p.ISBN_number << ": " << p.title << ", " << p.author << " " << p.bookPrice() << endl;
        return out;
    }
};

class OnlineBook : public Book {
protected:
    char *url;
    int mb;
public:
    OnlineBook(char *ISBN_number = " ", char *title = " ", char *author = " ", double defaultPrice = 0, char *url = " ",
               int mb = 0)
            : Book(ISBN_number, title, author, defaultPrice) {
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
        this->mb = mb;
    }

    OnlineBook(const OnlineBook &p) : Book(p) {
        strcpy(this->ISBN_number, p.ISBN_number);
        strcpy(this->title, p.title);
        strcpy(this->author, p.author);
        this->defaultPrice = p.defaultPrice;
        this->url = new char[strlen(p.url) + 1];
        this->mb = p.mb;
        strcpy(this->url, url);
        for (int i = 0; i < strlen(p.url); i++) {
            this->url[i] = p.url[i];
        }
    }

    OnlineBook &operator=(const OnlineBook &p) {
        if (this != &p) {
            strcpy(this->ISBN_number, p.ISBN_number);
            strcpy(this->title, p.title);
            strcpy(this->author, p.author);
            this->defaultPrice = p.defaultPrice;
            this->url = new char[strlen(p.url) + 1];
            strcpy(this->url, url);
            this->mb = p.mb;
        }
        return *this;
    }

    double bookPrice() override {
        if (mb > 20) {
            return defaultPrice * 1.20;
        }
        return defaultPrice;
    }
    ~OnlineBook(){
        delete[]url;
    }
};

class PrintBook : public Book {
protected:
    double kg;
    bool stock;
public:
    PrintBook(char *ISBN_number = " ", char *title = " ", char *author = " ", double defaultPrice = 0, double kg = 0,
              bool stock = false)
            : Book(ISBN_number, title, author, defaultPrice) {
        this->kg = kg;
        this->stock = stock;
    }

    PrintBook(const PrintBook &p) : Book(p) {
        strcpy(this->ISBN_number, p.ISBN_number);
        strcpy(this->title, p.title);
        strcpy(this->author, p.author);
        this->kg = p.kg;
        this->stock = p.stock;
    }

    PrintBook &operator=(const PrintBook &p) {
        if (this != &p) {
            strcpy(this->ISBN_number, p.ISBN_number);
            strcpy(this->title, p.title);
            strcpy(this->author, p.author);
            this->kg = p.kg;
            this->stock = p.stock;
        }
        return *this;
    }

    double bookPrice() override {
        if (kg > 0.7) {
            return defaultPrice * 1.15;
        }
        return 0;
    }
};

void mostExpensiveBook(Book **books, int n) {
    int onlineCounter = 0;
    int printCounter = 0;
    int indeks = 0;
    double max = books[0]->getDefaultPrice();
    for (int i = 0; i < n; i++) {
        OnlineBook *online = dynamic_cast<OnlineBook *>(books[i]);
        PrintBook *print = dynamic_cast<PrintBook *>(books[i]);
        if (online) {
            onlineCounter++;
        } else if (print) {
            printCounter++;
        }
    }
    for (int i = 1; i < n; i++) {
        if (books[i]->getDefaultPrice() > max) {
            max = books[i]->getDefaultPrice();
            indeks = i;
        }
    }
    cout << "FINKI-Education" << endl;
    cout << "Total number of online books: " << onlineCounter << endl;
    cout << "Total number of print books: " << printCounter << endl;
    cout << "The most expensive book is:" << endl;
    cout << *books[indeks] << endl;

}

int main(){

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
    delete[] books;
    return 0;
}
