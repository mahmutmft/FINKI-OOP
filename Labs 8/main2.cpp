#include <iostream>
#include <cstring>

using namespace std;

class Athlete {
protected:
    string name;
    int age;
public:
    Athlete(string name = "", int age = 0) {
        this->name = name;
        this->age = age;
    }

    virtual void displayInfo() = 0;
};

class Runner : virtual public Athlete {
protected:
    double speed;
public:
    Runner(string name = "", int age = 0,double speed=0): Athlete(name,age){
        this->speed = speed;
    }
    double getSpeed(){
        return this->speed;
    }
    void displayInfo() {
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};
class Jumper : virtual public Athlete{
protected:
    double height;
public:
    Jumper(string name = "", int age = 0, double height = 0): Athlete(name,age){
        this->height = height;
    }
    double getHeight(){
        return this->height;
    }
    void displayInfo() {
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Height: "<<height<<endl;
    }
};

class AllRoundAthlete : public Jumper, Runner{
protected:
    int stanima;
public:
    AllRoundAthlete(string name = "", int age = 0, double speed = 0, double height = 0, int stanima = 0)
    : Athlete(name,age), Runner(name, age, speed), Jumper(name,age,height)
    {
        this->stanima = stanima;
    }
    void displayInfo(){
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Speed: "<<speed<<" mph"<<endl;
        cout<<"Height: "<<height<<"m"<<endl;
        cout<<"Stamina: "<<stanima<<endl;
    }
};
Athlete* findAthleteWithMaxValue(Athlete** athletes, int n){
    Athlete* najak = athletes[0];
    for(int i=1; i<n; i++){
        if(dynamic_cast<Runner*>(athletes[i])){
            if(dynamic_cast<Runner*>(athletes[i])->getSpeed() > dynamic_cast<Runner*>(najak)->getSpeed()){
                najak = athletes[i];
            }
        }
        else if(dynamic_cast<Jumper*>(athletes[i])){
            if(dynamic_cast<Jumper*>(athletes[i])->getHeight() > dynamic_cast<Jumper*>(najak)->getHeight()){
                najak = athletes[i];
            }
        }
    }
    return najak;
}

int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin >> choice;
    if (choice == 1) {
        cin >> name;
        cin >> age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    } else {

        cin >> n;

        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;

                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;

                athletes[i] = new Jumper(name, age, height);
            }

        }

        findAthleteWithMaxValue(athletes, n)->displayInfo();

    }

    return 0;
}