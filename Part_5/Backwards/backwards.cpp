#include <iostream>
#include <string>
using namespace std;

class Backwards {
    public:
        static string transform(string words);
};

string Backwards::transform(string words) {
    string backwards = "";
    int len = words.length();

    for (int i = len; i>-1; i--) {
        backwards += words[i];
    }

    return backwards;
}

string getWords() {
    string userInput;
    cout << "Enter the words you want backwords: ";
    getline(cin, userInput);
    return userInput;
}

int main() {
    string userWords = getWords();
    string backWords = Backwards::transform(userWords);
    cout << "Backwards: " + backWords;
    cout << endl << endl;
    system("pause");
}