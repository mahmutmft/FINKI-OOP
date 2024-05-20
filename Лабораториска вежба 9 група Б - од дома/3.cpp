#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void writeToFile() {
    std::ofstream outFile("text.txt");
    char c;
    while((c = std::cin.get()) != '#') {
        outFile.put(c);
    }
    outFile.close();
}

int main() {
    writeToFile();

    //Your code

    return 0;
}