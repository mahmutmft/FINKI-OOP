#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class BasketballPlayer {
private:
    char imeNaKosharkar[20]{};
    char prezimeNaKosharka[20]{};
    int dresBroj;
    float poeniNatprevar;
    float vtorNatprevar;
    float tretNatprevar;
public:
    BasketballPlayer(char _imeNaKosharkar[20], char _prezimeNaKosharkar[20], float _dresBroj, float _poemiNatprevar,
        float _vtorNatprevar, float _tretNatprevar) {
        strcpy(imeNaKosharkar, _imeNaKosharkar);
        strcpy(prezimeNaKosharka, _prezimeNaKosharkar);
        dresBroj = _dresBroj;
        poeniNatprevar = _poemiNatprevar;
        vtorNatprevar = _vtorNatprevar;
        tretNatprevar = _tretNatprevar;
    }
        void printBasketballPlayer() {
        cout<<"Player: " << imeNaKosharkar <<" with number: "<< dresBroj << " has "<< abs((poeniNatprevar + vtorNatprevar + tretNatprevar) / 3) << " points on average"<<endl;
        }
};

int main(){
    char imeNaKosharkar[20];
    char prezimeNaKosharka[20];
    float dresBroj, poeniNatprevar, vtorNatprevar, tretNatprevar;
    cin>>imeNaKosharkar>>prezimeNaKosharka>>dresBroj>>poeniNatprevar>>vtorNatprevar>>tretNatprevar;
    BasketballPlayer obj1(imeNaKosharkar,prezimeNaKosharka,dresBroj,poeniNatprevar,vtorNatprevar,tretNatprevar);
    obj1.printBasketballPlayer();
    return 0;
}