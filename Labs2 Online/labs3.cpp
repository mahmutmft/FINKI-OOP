#include <iostream>
using namespace std;

class SpaceObject {
private:
    char name[100];
    char type[100];
    float distanceFromEarth;
public:
    void print() {

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
    SpaceObject getObjectClosestToEarth(){}
    void print(){}
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
        int distanceFromEarth;
        cin>>spaceObjectName>>spaceObjectType>>distanceFromEarth;
        spaceObjects[i]=SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }
    Alien alien;
    alien=Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}