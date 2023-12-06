#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char* error = "\033[31m[!]\033[0m";
const char* info = "\033[94m[*]\033[0m";
const char* success = "\033[92m[+]\033[0m";

class Birthdays {
    public:
        void showMenu();
        void searchPerson();
        void deletePerson();
    
    private:
        void setSearchType(int mode);
        void setSerarh();
        string fileName = "Text/birthdays.txt";
        int searchType;
        string search;
};

string lower(string text) {
    int length = text.length();

    for (int i = 0; i < length; i++) {
        int asciiCode = (int)text[i];

        if (asciiCode >= 65 && asciiCode <= 90) {
            text[i] = (char)(asciiCode+32);
        }

    }

    return text;
}

void Birthdays::setSearchType(int mode) {
    if (mode == 0) {
        cout << "Would you like to search by name or birthdate: ";
    } else {
        cout << "Would you like to delete by name or birthdate: ";
    }
    string userInput;
    getline(cin, userInput);

    userInput = lower(userInput);

    if (userInput == "name" || userInput == "birthdate") {
        if (userInput == "name") {
            this->searchType = 0;
            printf("\n%s Set search type to name\n\n", info);
        } else {
            this->searchType = 1;
            printf("\n%s Set search type to brithdate\n\n", info);
        }

    } else {
        printf("\n%s Invalid option, try again\n\n", error);

        return Birthdays::setSearchType(mode);
    }

}

void Birthdays::setSerarh() {
    string userInput;
    if (this->searchType == 0) {
        cout << "Enter name: ";
    } else {
        cout << "Enter birthdate: ";
    }

    getline(cin, userInput);

    this->search = lower(userInput);
    printf("\n%s Set search term to %s\n", info, this->search.c_str());
}

void Birthdays::searchPerson() {
    this->setSearchType(0);
    this->setSerarh();

    ifstream file(this->fileName);

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(this->search) != -1) {
            found = true;
            printf("\n%s %s\n", success, line.c_str());
        }
    }

    if (found == false) {
        printf("\n%s None found\n", error);
    }
}

void Birthdays::deletePerson() {
    this->setSearchType(1);
    this->setSerarh();

    int deletedAmount = 0;
    string newFileText;
    string line;
    ifstream file(this->fileName);

    while (getline(file, line)) {
        if (line.find(this->search) == -1) {
            newFileText += line;
        } else {
            deletedAmount += 1;
        }
    }

    ofstream newFile(this->fileName);
    newFile << newFileText;

    if (deletedAmount > 0) {
        printf("%s Deleted %d lines", error, deletedAmount);
    }

}

void Birthdays::showMenu() {
    string menuText = "1. Search\n2. Delete\n3. Quit";
    cout << menuText << endl;
}

int getChoice() {
    string userInput;
    int validChoices[3] = {1,2,3};

    cout << "" << endl;
    getline(cin, userInput);

    return 1;

}

int main() {
    Birthdays birth;
    birth.showMenu();

    cout << endl;
    system("pause");
}