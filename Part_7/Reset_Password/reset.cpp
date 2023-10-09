#include <iostream>
#include "Headers/Password.h"

int main() {
    // codes = {0, 0, 0, 0, 0, 0}
    // index 0 = At least 1 letter between a-z 
    // index 1 = At least 1 letter between A-Z
    // index 2 = At least 1 number between 0-9
    // index 3 = At least 1 character from $#@!
    // index 4 = Minimum length 8 characters
    // index 5 = Maximum length 24 characters
    // index 6 = if its 0 that means password is not valid, if its 1 that means password is valid

    bool done = false;
    int codes[7] = {0,0,0,0,0,0,0};

    while (done == false) {
        string userPassowrd = Password::getPassword();
        cout << endl;
        Password::checkPassword(userPassowrd, codes);
        string results = Password::codeResults(codes);

        cout << results;

        if (codes[6] == 1) {
            done = true;
        } else {
            cout << "Try again";
        }
        
        for (int i = 0; i < 7; i++) {
            codes[i] = 0;
        }

        cout << endl << endl;

    }

    system("pause");

}