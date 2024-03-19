#include <iostream>
using namespace std;
struct Transaction{
    int id;
    int sumaPlatena;
    int provizija;
    bool vidKarticka;
};

int main(){
    int n;
    int brojac=0;
    cin>>n;
    Transaction transakcii[100];
    for(int i=0;i<n;i++){
        cin>>transakcii[i].id;
        cin>>transakcii[i].sumaPlatena;
        cin>>transakcii[i].provizija;
        cin>>transakcii[i].vidKarticka;
    }
    for(int i=0;i<n;i++){
        if(transakcii[i].vidKarticka == 1){
            cout<<transakcii[i].id;
            cout<<" "<<transakcii[i].sumaPlatena + transakcii[i].provizija<<endl;
        }
        else{
            brojac++;
        }
        if(brojac == n){
            cout<<"No credit card transaction"<<endl;
        }
    }

    return 0;
}