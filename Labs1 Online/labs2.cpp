#include <iostream>
using namespace std;

struct Engine {
    int konjskaSila;
    int vrtezenMoment;
};

struct Car {
    char ime[100];
    int godinaNaProizvodstvo;
    Engine motor;
};

void printCars(Car kola[], int n) {
    int minKonjskaSila1 = 0;
    int minKonjskaSila2 = 1;

    for (int i = 1; i < n; i++) {
        if (kola[i].motor.konjskaSila < kola[minKonjskaSila1].motor.konjskaSila) {
            minKonjskaSila2 = minKonjskaSila1;
            minKonjskaSila1 = i;
        } else if (kola[i].motor.konjskaSila < kola[minKonjskaSila2].motor.konjskaSila) {
            minKonjskaSila2 = i;
        }
    }

    int maxVrtezenMoment;
    if (kola[minKonjskaSila1].motor.vrtezenMoment > kola[minKonjskaSila2].motor.vrtezenMoment) {
        maxVrtezenMoment = minKonjskaSila1;
    } else {
        maxVrtezenMoment = minKonjskaSila2;
    }

    cout << "Manufacturer: " << kola[maxVrtezenMoment].ime << endl;
    cout << "Horsepower: " << kola[maxVrtezenMoment].motor.konjskaSila << endl;
    cout << "Torque: " << kola[maxVrtezenMoment].motor.vrtezenMoment << endl;
}

int main() {
    int n;
    cin >> n;
    Car kola[100];
    for (int i = 0; i < n; i++) {
        cin >> kola[i].ime;
        cin >> kola[i].godinaNaProizvodstvo;
        cin >> kola[i].motor.konjskaSila;
        cin >> kola[i].motor.vrtezenMoment;
    }
    printCars(kola, n);
    return 0;
}