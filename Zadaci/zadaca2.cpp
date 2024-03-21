#include <iostream>
using namespace std;

class List {
private:
    int deliteli[60];
    int brojNaDeliteli;

public:
    List(int *_deliteli, int _brojNaDeliteli) {
        for (int i = 0; i < _brojNaDeliteli; i++) {
            deliteli[i] = _deliteli[i];
        }
        brojNaDeliteli = _brojNaDeliteli;
    }

    List(const List &other) {
        for (int i = 0; i < brojNaDeliteli; i++) {
            deliteli[i] = other.deliteli[i];
        }
        brojNaDeliteli = other.brojNaDeliteli;cout << " copy " << endl;

    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < brojNaDeliteli; i++) {
            sum += deliteli[i];
        }
        return sum;
    }

    double avrage() {
        return double(sum()) / double(brojNaDeliteli);
    }

    void print() {
        cout << deliteli << ":";
        for (int i = 0; i < brojNaDeliteli; i++) {
            cout << deliteli[i] << " ";
        }
        cout << "sum: " << sum() << " average:" << avrage() << endl;
    }

    ~List() {
    }
};

class ListContainer {
    List nizaOdListi[50];
    int brojNaElementi;
    int obidi;

public:
    ListContainer() {
    }
    ListContainer(const ListContainer &other) {
        brojNaElementi = other.brojNaElementi;
        obidi = other.obidi;
        for (int i = 0; i < brojNaElementi; i++) {
            nizaOdListi[i] = other.nizaOdListi[i];
        }
    }
    int sum() {
        int suma = 0;
        for (int i = 0; i < brojNaElementi; i++) {
            suma += nizaOdListi[i].sum();
        }
        return suma;
    }

    float average() {
        return ((double) sum() / brojNaElementi);
    }

    void print() {
        for (int i = 0; i < brojNaElementi; i++) {
            cout << "List number: " << i + 1 << " " << "List info: ";
            nizaOdListi[i].print();
            cout << endl;
            cout << "Sum:" << sum() << " Average: " << average();
        }
    }

    ~ListContainer() {
        delete[] nizaOdListi;
    }
};

int main() {
    ListContainer lc;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> niza[j];
        }
        List l = List(niza, n);
        lc.addNewList(l);
    }
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();
    } else {
        lc.print();
    }
}
