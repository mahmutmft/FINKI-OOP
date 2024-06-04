#include <iostream>
#include <cstring>

using namespace std;

class MountainTrail {
private:
    char path[100];
    int pathLength;
    double slope;
public:
    MountainTrail(){

    }

    MountainTrail(const char *path, int pathLength, double slope){
        this->slope = slope;
        this->pathLength = pathLength;
        strcpy(this->path, path);
    }

    double difficulty() const {
        return pathLength * slope / 100.0;
    }

    void display() const {
        cout << path << " " << pathLength << " " << slope << endl;
    }
};

class Mountain {
private:
    char name[100];
    MountainTrail trails[5];
    int peak_elevation;
    static int num_mountains;
public:
    Mountain(){
    }
    Mountain(const char *name, MountainTrail trails[], int peak_elevation) {
        strcpy(this->name, name);
        for (int i = 0; i < 5; ++i) {
            this->trails[i] = trails[i];
        }
        this->peak_elevation = peak_elevation;
    }
    void display() const {
        cout << name << ": " << peak_elevation << "m" << endl;
    }
    static int getNumMountains() {
        return num_mountains;
    }

    int getPeak(){
        return peak_elevation;
    }

};

int Mountain::num_mountains = 0;

void sortMountainsByPeakElevation(Mountain mountains[], int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            if(mountains[i].getPeak() < mountains[j+1].getPeak()){
                swap(mountains[i],mountains[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        mountains[i].display();
    }
}

int main() {

    int test_case_n;

    char trail_name[100];
    int trail_length;
    double trail_slope;

    char mountain_name[100];
    int mountain_peak_elevation;

    cin>>test_case_n;
    if (test_case_n == 0) {
        cout << "Testing MountainTrail c-tors, display function:"<<endl;
        cin >> trail_name >> trail_length >> trail_slope;
        MountainTrail mt = MountainTrail(trail_name, trail_length, trail_slope);
        MountainTrail mt2 = MountainTrail(mt);
        mt.display();
        mt2.display();
    } else if (test_case_n == 1) {
        cout << "Testing MountainTrail difficulty function:"<<endl;
        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            MountainTrail mt = MountainTrail(trail_name, trail_length, trail_slope);
            cout<<mt.difficulty()<<endl;
        }
    } else if (test_case_n == 2) {
        cout << "Testing Mountain c-tor, display function:"<<endl;
        MountainTrail trails[5];

        cin>>mountain_name>>mountain_peak_elevation;

        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            trails[i] = MountainTrail(trail_name, trail_length, trail_slope);
        }

        Mountain mountain = Mountain(mountain_name, trails, mountain_peak_elevation);
        mountain.display();
    } else if (test_case_n == 3) {
        cout << "Testing static field in Mountain:" <<endl;
        MountainTrail trails[5];

        cin>>mountain_name>>mountain_peak_elevation;

        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            trails[i] = MountainTrail(trail_name, trail_length, trail_slope);
        }

        for (int i = 0; i < 10; ++i) {
            Mountain mountain = Mountain(mountain_name, trails, mountain_peak_elevation);
        }

        Mountain m1 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m2 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m3 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m4 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m5 = Mountain(mountain_name, trails, mountain_peak_elevation);

        if(Mountain::getNumMountains() == 5) {
            cout<<"OK";
        } else {
            cout<<"Missing mountain count increment/decrement";
        }
    } else if (test_case_n == 4) {
        int M;
        cin>>M;
        cout<<"Testing order function:"<<endl;

        Mountain mountains[M];

        for (int i = 0; i < M; ++i) {
            cin>>mountain_name>>mountain_peak_elevation;
            MountainTrail trails[5];

            for (int j = 0; j < 5; ++j) {
                cin >> trail_name >> trail_length >> trail_slope;
                trails[j] = MountainTrail(trail_name, trail_length, trail_slope);
            }

            mountains[i] = Mountain(mountain_name, trails, mountain_peak_elevation);
        }

        sortMountainsByPeakElevation(mountains, M);
    }
}