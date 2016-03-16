#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();

    while(n > 0) {
        string line;
        getline(cin, line);
        stringstream linestream;
        linestream << line;
        vector<string> words;

        string word;
        while(linestream >> word)
        words.push_back(word);

        for(int i = 0; i < words.size(); i++) {
            if(words.at(i).size() == 4)
                cout << "****";
            else
                cout << words.at(i);
            cout << " ";
        }
        cout << endl;

        n--;
    }

    return 0;
}
