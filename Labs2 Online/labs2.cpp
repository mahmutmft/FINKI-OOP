#include <iostream>
#include <cstring>
using namespace std;

class Country {
private:
    char name[100], capital[100];
    float area, population;
public:
    Country(){}
    char *getCapital() {
        return capital;
    }
    char *getName() {
        return name;
    }
    float getArea() {
        return area;
    }
    float getPopulation() {
        return population;
    }
    const char *setName(char _ime[100]) {
        strcpy(name, _ime);
        return _ime;
    }
    const char *setCapital(char _glavenGrad[100]) {
        strcpy(capital, _glavenGrad);
        return _glavenGrad;
    }
    char setArea(float _area1) {
        area = _area1;
        return _area1;
    }
    char setPopulation(float _populacija) {
        population = _populacija;
        return _populacija;
    }
    Country(char _name[100], char _capital[100], float _area, float _popilation) {
        strcpy(name, _name);
        strcpy(capital, _capital);
        area = _area;
        population = _popilation;
    }
    void display() {
        cout << "Country: " << name << endl;
        cout << "Capital: " << capital << endl;
        cout << "Area: " << area << endl;
        cout << "Population: " << population << endl;
    }
    ~Country() {
    }
};
 void sortCountries(Country *countries, int n){
     for(int i=0;i<n;i++) {
         for(int j=i+1;j<n;j++) {
             Country temp;
             if(countries[i].getArea() > countries[j].getArea()) {
                 temp = countries[i];
                 countries[i] = countries[j];
                 countries[j] = temp;
             }
         }
     }
     for(int i=0;i<n;i++) {
         countries[i].display();
     }
 }
int main() {
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin>> capital;
        cin>> area;
        cin>>population;
        countries[i] = Country(name, capital, area, population);
    }
    cin>>name;
    cin >> capital;
    cin >> area;
    cin>>population;
    countries[n-1].setName(name);
    countries[n-1].setCapital(capital);
    countries[n-1].setArea(area);
    countries[n-1].setPopulation(population);

    cout<<"-->Testing set methods and display()"<<endl;
    countries[n-1].display();
    cout<<endl;

    cout<<"-->Testing sortCountries()"<<endl;
    sortCountries(countries,n);
    return 0;
}