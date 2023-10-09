#include <iostream>
#include <string>

using namespace std;

class Digits {
    public:
        Digits(string number);
        int getDigitAmount();
    
    private:
        string number;
};

Digits::Digits(string number) {
    this->number = number;
}

int Digits::getDigitAmount() {
    return this->number.length();
}

string getNumber() {
    string userInput;
    cout << "Enter a number less than 100: ";
    getline(cin, userInput);

    try {
        stoi(userInput);

        if (stoi(userInput) >= 100) {
            cout << "Number must be less than 100" << endl << endl;
            return getNumber();
        }
    }

    catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return getNumber();
    } 

    return userInput;
}

int main() {
    string number = getNumber();
    Digits dig(number);

    string txt = "Your number has \"" + to_string(dig.getDigitAmount()) + "\" digit(s)";
    cout << txt << endl << endl;

    system("pause");
}