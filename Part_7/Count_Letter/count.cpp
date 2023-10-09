#include <iostream>
#include <string>

using namespace std;

string getPhrase() {
    string phrase;
    cout << "Enter phrase: ";
    getline(cin, phrase);

    return phrase;
}

char getLetter() {
    cout << "Letter to search: ";
    string userInput;
    getline(cin, userInput);

    if (userInput.length() != 1) {
        cout << "Enter one letter, try again" << endl << endl;
        return getLetter();
    }

    char letter = userInput[0];
    return letter;
}

int search(string phrase, char letter) {
    int amount = 0;

    for (int i = 0; i < phrase.length(); i++) {
        if (phrase[i] == letter) {
            amount += 1;
        }
    }

    return amount;
}

int main() {
    string phrase = getPhrase();
    char letter = getLetter();
    int amount = search(phrase, letter);

    cout << "Counted: " + to_string(amount) << endl;
    cout << endl;
    system("pause");
}