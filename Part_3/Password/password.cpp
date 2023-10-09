#include <iostream>
#include <string>

using namespace std;

class Password {
    public:
        bool checkInput();
    private:
        int tries = 0;
        int maxTries = 5;
        string password = "secret";
};


string getInput() {
    string userInput;
    cout << "Enter password: ";
    getline(cin, userInput);
    return userInput;
}


bool Password::checkInput() {

    if (this->tries == this->maxTries) {
        cout << "Too many attemps, exiting program" << endl << endl;
        return false;
    }

    string guess = getInput();

    if (guess == this->password) {
        cout << "Password Accepted" << endl;
        return false;
    }

    else {
        this->tries += 1;
        string txt = "Password incorrect\nTries: " + to_string(this->tries) + "\nAttempts left: " + to_string(this->maxTries - this->tries);
        cout << txt << endl << endl;
        return true;
    }
}


int main() {
    Password pass;
    bool playing = true;

    while (playing == true) {
        playing = pass.checkInput();
    }

    system("pause");
}