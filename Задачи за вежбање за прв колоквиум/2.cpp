#include <iostream>
#include <cstring>

using namespace std;

class List {
private:
    int *delivi;
    int brojNaBroevi;
public:
    List(int *delivi = 0, int brojNaBroevi = 0) {
        this->delivi = new int[brojNaBroevi + 1];
        for (int i = 0; i < brojNaBroevi; i++) {
            this->delivi[i] = delivi[i];
        }
        this->brojNaBroevi = brojNaBroevi;
    }

    List(const List &p) {
        this->delivi = new int[p.brojNaBroevi + 1];
        for (int i = 0; i < p.brojNaBroevi; i++) {
            this->delivi[i] = p.delivi[i];
        }
        this->brojNaBroevi = p.brojNaBroevi;
    }

    List &operator=(const List &p) {
        if (this != &p) {
            delete[] delivi;
            this->delivi = new int[p.brojNaBroevi + 1];
            for (int i = 0; i < p.brojNaBroevi; i++) {
                this->delivi[i] = p.delivi[i];
            }
            this->brojNaBroevi = p.brojNaBroevi;
        }
        return *this;
    }

    int sum() const {
        int sum = 0;
        for (int i = 0; i < brojNaBroevi; i++) {
            sum += delivi[i];
        }
        return sum;
    }

    double average() const {
        return ((float) sum() / (float) brojNaBroevi);
    }

    void pecati() {
        cout << brojNaBroevi << ": ";
        for (int i = 0; i < brojNaBroevi; i++) {
            cout << delivi[i] << " ";
        }
        cout << "sum: " << sum() << " average: " << average();
    }

    ~List() {
        delete[] delivi;
    }
};

class ListContainer {
private:
    List *niza;
    int brojElementi;
    int obidi;
public:
    ListContainer(List *niza = 0, int brojElementi = 0, int obidi = 0) {
        this->niza = new List[brojElementi + 1];
        for (int i = 0; i < brojElementi; i++) {
            this->niza[i] = niza[i];
        }
        this->brojElementi = brojElementi;
        this->obidi = 0;
    }

    ListContainer(ListContainer &p) {
        this->niza = new List[p.brojElementi + 1];
        for (int i = 0; i < p.brojElementi; i++) {
            this->niza[i] = p.niza[i];
        }
        this->brojElementi = p.brojElementi;
        this->obidi = p.obidi;
    }

    ListContainer &operator=(const ListContainer &p) {
        if (this != &p) {
            delete[] niza;
            this->niza = new List[p.brojElementi + 1];
            for (int i = 0; i < p.brojElementi; i++) {
                this->niza[i] = p.niza[i];
            }
            this->brojElementi = p.brojElementi;
            this->obidi = p.obidi;
        }
        return *this;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < brojElementi; i++) {
            sum += niza[i].sum();
        }
        return sum;
    }

    double average() {
        double avg = 0;
        for (int i = 0; i < brojElementi; i++) {
            avg += niza[i].average();
        }
        return avg;
    }

    void print() {
        if (sum() == 0) {
            cout << "The list is empty" << endl;
        } else {
            for (int i = 0; i < brojElementi; i++) {
                cout << "List number: " << i + 1 << " List info: ";
                niza[i].pecati();
                cout << endl;

            }
            cout << "Sum: " << sum() << " Average: " << average() << endl;
        }
    }

    void addNewList(const List &l) {
        bool differentSum = true;
        int fail = 0;
        int yes = 0;

        for (int i = 0; i < brojElementi; i++) {
            if (niza[i].sum() == l.sum()) {
                differentSum = false;
                fail++;
                break;
            }
        }
        if (differentSum) {
            yes++;
            List *temp = new List[brojElementi + 1];
            for (int i = 0; i < brojElementi; i++) {
                temp[i] = niza[i];
            }
            temp[brojElementi] = l;

            delete[] niza;
            niza = temp;

            brojElementi++;
        }
    }
    ~ListContainer() {
        delete[] niza;
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