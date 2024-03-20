#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class SpaceObject {
private:
    char name[100];
    char type[100];
    float distanceFromEarth;
public:
    char *getName(){
        return this->name;
    }

    char *getType(){
        return this->type;
    }

    int getDistanceFromEarth(){
        return this->distanceFromEarth;
    }

    void setName(char *name){
        strcpy(this->name, name);
    }

    void setType(char *type){
        strcpy(this->type, type);
    }

    void setDistanceFromEarth(float distanceFromEarth){
        this->distanceFromEarth=distanceFromEarth;
    }
    SpaceObject(){}
    SpaceObject(char *_name, char *_type, float _distanceFromEarth) {
        strcpy(name, _name);
        strcpy(type,_type);
        distanceFromEarth = _distanceFromEarth;
    }
    void print() {
        cout<<name<<" ("<<type<<") " << "- distance: "<< fixed << setprecision(0) << distanceFromEarth <<" light years away from Earth"<<endl;
    }
};
class Alien {
private:
    char name[100];
    int age;
    char homePlanet[100];
    int numObj;
    SpaceObject _spaceObject[100];
public:
    Alien(){}
    Alien(char *_name, int _age, char *_homePlanet, int _numObj, SpaceObject *spaceobjects) {
        strcpy(name, _name);
        strcpy(homePlanet, _homePlanet);
        age = _age;
        numObj = _numObj;
        for(int i=0;i<numObj;i++) {
            _spaceObject[i] = spaceobjects[i];
        }
    }
    SpaceObject getObjectClosestToEarth() {
        float minDistance = _spaceObject[0].getDistanceFromEarth();
        int index=0;
        for(int i=0;i<numObj;i++)
        {
            if(_spaceObject[i].getDistanceFromEarth()<minDistance) {
                minDistance = _spaceObject[i].getDistanceFromEarth();
                index = i;
            }
        }
        return _spaceObject[index];
    }
    Alien(const Alien &other) {
        strcpy(name, other.name);
        age = other.age;
        strcpy(homePlanet, other.homePlanet);
        numObj = other.numObj;
        for(int i = 0; i < numObj; i++) {
            _spaceObject[i] = other._spaceObject[i];
        }
    }
    void print() {
        cout<<"Alien name: "<< name <<endl;
        cout<<"Alien age: "<<age<<endl;
        cout<<"Alien homePlanet: "<<homePlanet<<endl;
        cout<<"Favourite space object closest to earth: " ;
        getObjectClosestToEarth().print();
    }
};

int main()
{
    char name[100], homePlanet[100];
    int age, numObj;
    cin>>name>>age>>homePlanet>>numObj;
    SpaceObject spaceObjects[numObj];
    for(int i=0; i<numObj; i++)
    {
        char spaceObjectName[100], spaceObjectType[100];
        float distanceFromEarth;
        cin>>spaceObjectName>>spaceObjectType>>distanceFromEarth;
        spaceObjects[i]=SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }
    Alien alien;
    alien=Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}