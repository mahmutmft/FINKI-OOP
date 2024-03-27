#include <iostream>
using namespace std;

struct Laptop {
    char firma[100];
    float goleminaNaMonitorot;
    bool touch;
    int cena;
};

class ITStore {
    char imeNaProdavnica[100];
    char lokacija[100];
    Laptop dostapniLaptopi[100];
    int n;
};
void print() {

}
void najeftina_ponuda(const ITStore* laptopi, int n) {

}
int main() {
    ITStore s[100];
    int n;
    cin>>n;

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv



    //pecatenje na site prodavnici




    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}