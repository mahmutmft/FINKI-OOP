#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>

using namespace std;

class InvalidOperation{
public:
    void print(){
        cout << "Conference duration exceeded" << endl;
    }
};

class Speaker{
private:
    string ime;
    string naslov;
    int vreme;
public:
    Speaker(string ime = "", string naslov = " ", int vreme = 1)
            : ime(ime), naslov(naslov), vreme(vreme) {}

    friend ostream &operator<<(ostream &out, const Speaker &p){
        out << p.ime << " - " << p.naslov << ", " << p.vreme;
        return out;
    }

    int getVreme() const {
        return vreme;
    }
};

class Conference{
private:
    string kod;
    string datum;
    vector<Speaker> niza;
    static int MaxDuration;
public:
    Conference(string kod = " ", string datum = " ", vector<Speaker> niza = {})
            : kod(kod), datum(datum), niza(niza) {}

    static void setMaxDuration(int p) {
        MaxDuration = p;
    }

    friend ostream &operator<<(ostream &out, const Conference &p){
        out << p.kod << " - " << p.datum << ", " << p.niza.size();
        return out;
    }

    bool operator>(const Conference &p) const {
        return niza.size() > p.niza.size();
    }

    bool operator==(const Conference &p) const {
        return datum == p.datum;
    }

    void operator+=(const Speaker& speaker) {
        int totalDuration = 0;
        for (const Speaker& s : niza) {
            totalDuration += s.getVreme();
        }
        if (totalDuration + speaker.getVreme() > MaxDuration) {
            throw InvalidOperation();
        }
        niza.push_back(speaker);
    }

    void longestPresentation() const {
        if (niza.empty()) {
            cout << "No speakers in the conference." << endl;
            return;
        }
        Speaker longest = niza[0];
        for (const Speaker& s : niza) {
            if (s.getVreme() > longest.getVreme()) {
                longest = s;
            }
        }
        cout <<"Longest Presentation: "<< longest << endl;
    }
};

int Conference::MaxDuration = 360;

//Your code here
int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0) {
        cout << "Speaker constructor" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "Speaker copy-constructor and operator=" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Speaker c1 = speaker2;
        Speaker c3;
        c3 = speaker2;
        cout << c3 << endl;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "Speaker operator print" << endl;
        Speaker speaker1("Aleksandar Stojmenski", "Introduction to C++", 60);
        Speaker speaker2("Stefan Andonov", "Object-Oriented Programming", 120);
        Speaker speaker3("Boban Joksimoski", "Computer Animation", 180);
        cout << speaker1 << endl;
        cout << speaker2 << endl;
        cout << speaker3 << endl;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 3) {
        cout << "Conference class" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference conference("CONF001", "2023-07-01");
        conference += speaker1;
        conference += speaker2;
        conference += speaker3;

        cout << conference << endl;
    } else if (testCase == 4) {
        cout << "Conference constructors" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference c("CONF001", "2023-07-01");
        c += speaker1;
        c += speaker2;
        Conference c1, c2 = c;
        c1 = c;
        c2 += speaker3;
        cout << c1 << endl;
        cout << c2 << endl;
    } else if (testCase == 5) {
        cout << "Conference operator> constructors" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference c("CONF001", "2023-07-01");
        c += speaker1;
        c += speaker2;
        Conference c1, c2 = c;
        c2 += speaker3;
        if (c2 > c) {
            cout << "PASSED" << endl;
        }
    } else if (testCase == 6) {
        cout << "longestPresentation and comparison" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        Conference conference("CONF001", "2023-07-01");

        conference += speaker1;
        conference += speaker2;
        conference += speaker3;

        cout << "Conference: " << conference << endl;

        conference.longestPresentation();

        // Test case for comparison operators
        Conference conference2("CONF002", "2023-07-01");
        conference2 += speaker1;
        conference2 += speaker2;

        if (conference > conference2) {
            cout << "CONF001 has more speakers than CONF002." << endl;
        } else {
            cout << "CONF001 has fewer speakers than CONF002." << endl;
        }

        // Test case for exceeding duration limit
        Speaker speaker4("Sarah Adams", "Advanced C++ Programming", 240);

    } else if (testCase == 7) {
        cout << "Exception handling" << endl;
        cout << "longestPresentation and comparison" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        Conference conference("CONF001", "2023-07-01");
        conference += speaker1;
        conference += speaker2;
        conference += speaker3;
        Conference conference2("CONF002", "2023-07-01");
        conference2 += speaker1;
        conference2 += speaker2;
        if (conference > conference2) {
            cout << "CONF001 has more speakers than CONF002." << endl;
        } else {
            cout << "CONF001 has fewer speakers than CONF002." << endl;
        }
        Speaker speaker4("Sarah Adams", "Advanced C++ Programming", 240);

        conference += speaker4;


    } else if (testCase == 8) {
        Conference conference4("CONF004", "2023-07-01");
        Conference conference5("CONF005", "2023-07-01");

        Speaker speaker9("Alex Turner", "Network Security", 120);
        Speaker speaker10("Olivia Parker", "Artificial Intelligence", 180);

        conference4 += speaker9;
        conference5 += speaker10;

        cout << "Conference 4: " << conference4 << endl;
        cout << "Conference 5: " << conference5 << endl;

        if (conference4 == conference5) {
            cout << "Conference 4 and Conference 5 have the same date." << endl;
        } else {
            cout << "Conference 4 and Conference 5 have different dates." << endl;
        }
    } else if (testCase == 9) {
        Conference conference3("CONF003", "2023-07-01");

        Conference::setMaxDuration(1000);
        Speaker speaker5("Michael Brown", "Web Development", 180);
        Speaker speaker6("Emily Davis", "Machine Learning", 240);
        Speaker speaker7("Robert Wilson", "Software Engineering", 120);

        conference3 += speaker5;
        conference3 += speaker6;
        conference3 += speaker7;

        cout << "Conference 3: " << conference3 << endl;

        Speaker speaker8("Jessica Lee", "Database Management", 180);


        conference3 += speaker8;
        cout << conference3;

    }
    return 0;
}


