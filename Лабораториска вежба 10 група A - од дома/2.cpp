#include<iostream>
#include<cstring>
#include<vector>
#include "algorithm"

using namespace std;

class Sentence {
private:
    vector<string> zborovi;
    vector<string> stopZborovi;
public:
    Sentence(vector<string> stopwords = vector<string>()) {
        this->stopZborovi = stopwords;
    }
    Sentence &operator+=(const string &p){
        if(find(stopZborovi.begin(),stopZborovi.end(), p) == stopZborovi.end()){
            zborovi.push_back(p);
        }
        return *this;
    }
    Sentence &operator-=(const string &p){
        auto alo = find(zborovi.begin(), zborovi.end(), p);
        if(alo != zborovi.end()){
            zborovi.erase(alo);
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Sentence& sentence) {
        for (size_t i = 0; i < sentence.zborovi.size(); ++i) {
            os << sentence.zborovi[i];
            if (i < sentence.zborovi.size() - 1) {
                os << " ";
            }
        }
        return os;
    }
};

int main() {
    // Read stopwords from standard input
    vector<string> stopwords;
    string stopword;
    while (cin >> stopword) {
        if (stopword == "done") {
            break;
        }
        stopwords.push_back(stopword);
    }

    // Create a Sentence object with the stopwords
    Sentence sentence(stopwords);

    // Read words to add to the sentence from standard input
    string word;
    while (cin >> word) {
        if (word == "exit") {
            break;
        }
        sentence += word;
    }

    // Display the sentence
    cout << sentence << endl;

    // Demonstrate removing a word
    cin >> word;
    sentence -= word;

    // Display the updated sentence
    cout << sentence << endl;

    return 0;
}
