#include "Password.h"
using namespace std;

string Password::getPassword() {
    cout << "New password: ";
    string userInput;
    getline(cin, userInput);

    return userInput;
}

void Password::checkPassword(string password, int* codes) {
    // codes = {0, 0, 0, 0, 0, 0}
    // index 0 = At least 1 letter between a-z 
    // index 1 = At least 1 letter between A-Z
    // index 2 = At least 1 number between 0-9
    // index 3 = At least 1 character from $#@!
    // index 4 = Minimum length 8 characters
    // index 5 = Maximum length 24 characters
    // index 6 = if its 0 that means password is not valid, if its 1 that means password is valid
    // A one means that it passed a test, a zero means it failed. By default all are zero

    // This code segment is for making abc and ABC because im lazy
    char lowerLetters[27];
    char highLetters[27];
    
    int index = 0;
    for (int i = 65; i < 91; i++) {
        highLetters[index] = (char)i;
        lowerLetters[index] = (char)(i+32);
        index += 1;
    }

    highLetters[26] = '\0';
    lowerLetters[26] = '\0';

    char symbols[5] = {'$', '#', '@', '!', '\0'};

    // Code segement runs all the checks
    int passwordLen = password.length();
    int passedAmount = 0;

    for (int i = 0; i < passwordLen; i++) {
        char currentCharacter = password[i];

        // If it has not passed upper letter test then check if current character is in the higher ABC
        if (*(codes) == 0) {
            for (int x = 0; x < 26; x++) {
                if (currentCharacter == highLetters[x]) {
                    *(codes) = 1;
                    passedAmount += 1;
                }
            }
        }

        // If it has not passed lower letter test then check if current character is in the lower ABC
        if (*(codes+1) == 0) {
            for (int x = 0; x < 26; x++) {
                if (currentCharacter == lowerLetters[x]) {
                    *(codes+1) = 1;
                    passedAmount += 1;
                }
            }
        }

        // If it has not passed the number test then check if current character is between 0-9
        if (*(codes+2) == 0) {
            for (int x = 48; x < 58; x++) {
                if (currentCharacter == (char)x) {
                    *(codes+2) = 1;
                    passedAmount += 1;
                }
            }
        }

        // If it has not passed the symbol test then check if current character is in symbols
        if (*(codes+3) == 0) {
            for (int x = 0; x < 5; x++) {
                if (currentCharacter == symbols[x]) {
                    *(codes+3) = 1;
                    passedAmount += 1;
                }
            }
        }

    }

    // Finally check if password is greater than 8 characters and less than 24 characters
    if (password.length() < 8) {
        // dont actually need this but idc
        *(codes+4) = 0;
    } else {
        *(codes+4) = 1;
        passedAmount += 1;
    }

    if (password.length() > 24) {
        *(codes+5) = 0;
    } else {
        *(codes+5) = 1;
        passedAmount += 1;
    }

    if (passedAmount == 6) {
        *(codes+6) = 1;
    }

    
}

string Password::codeResults(int* codes) {
    // codes = {0, 0, 0, 0, 0, 0}
    // index 0 = At least 1 letter between a-z 
    // index 1 = At least 1 letter between A-Z
    // index 2 = At least 1 number between 0-9
    // index 3 = At least 1 character from $#@!
    // index 4 = Minimum length 8 characters
    // index 5 = Maximum length 24 characters
    // index 6 = if its 0 that means password is not valid, if its 1 that means password is valid


    string results = "";

    if (*(codes) == 0) {
        results += "Password must contain at least one capital letter \n";
    }

    if (*(codes+1) == 0) {
        results += "Password must contain at least one lowercase letter\n";
    }

    if (*(codes+2) == 0) {
        results += "Password must contain at least one number\n";
    }

    if (*(codes+3) == 0) {
        results += "Password must contain at least one of the following symbols $,#,@,!\n";
    }

    if (*(codes+4) == 0) {
        results += "Password must have a minium length of 8\n";
    }

    if (*(codes+5) == 0) {
        results += "Password must have a maximum length of 24\n";
    }

    if (*(codes+6) == 1) {
        results += "Password accepted";
    }

    return results;
}