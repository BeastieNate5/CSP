#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Generator {
    public:
        Generator();
        void setPara();
        string genPass();
    private:
        int letterAmount;
        int symbolAmount;
        int numberAmount;

        char lowerLetters[26];
        char upperLetters[26];
        char symbols[9] = {'!', '#', '$', '%', '&', '*', '(', ')', '+'};
        char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

Generator::Generator() {
    int index = 0;
    for (int i = 65; i < 91; i++) {
        this->lowerLetters[index] = char(i);
        this->upperLetters[index] = char(i+32);
        index += 1;
    }

}

int getNumber(string prompt) {
    string userInput;
    cout << prompt;
    getline(cin, userInput);

    try {
        stoi(userInput);
    } catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return getNumber(prompt);
    }

    return stoi(userInput);

}

void Generator::setPara() {
    for (int i = 0; i < 3; i++) {
        if (i==0) {
            int amount = getNumber("How many letters would you like in your password? ");
            this->letterAmount = amount;
        } else if (i==1) {
            int amount  = getNumber("How many symbols would you like? ");
            this->symbolAmount = amount;
        } else {
            int amount = getNumber("How many numbers would you like? ");
            this->numberAmount = amount;
        }
    }
}

string Generator::genPass() {    
    int size = (this->letterAmount+this->symbolAmount+this->numberAmount);
    char* passowrd = new char[size+1];

    int index = 0;
    for (int i = 0; i < this->letterAmount; i++) {
        *(passowrd+index) = this->lowerLetters[((rand() % 26))];
        index += 1;
    }

    for (int i = 0; i < this->symbolAmount; i++) {
        *(passowrd+index) = this->symbols[((rand() %  9))];
        index += 1;
    }

    for (int i = 0; i < this->numberAmount; i++) {
        *(passowrd+index) = this->numbers[((rand() % 10))];
        index += 1;
    }

    *(passowrd+size) = '\0';

    string strPassword = string(passowrd);
    delete[] passowrd;

    return strPassword;

}

bool in(int target,  int* ptrNums, int size) {
    bool checked = false;

    if (size == 0) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (*(ptrNums+i) == target) {
            checked = true;
        }
    }

    return checked;
}

string shuffle(string input) {
    int* usedNums;
    usedNums = new int[input.length()];

    char* shuffedPass;
    shuffedPass = new char[input.length()];

    int usedNumsSize = 0;
    for (int i = 0; i < input.length(); i++) {
        int randomIndex = (rand() % input.length());

        while (in(randomIndex, usedNums, usedNumsSize) == true) {
            randomIndex = (rand() % input.length());
        }
        *(shuffedPass+i) = input[randomIndex];
        *(usedNums+i) = randomIndex;
        usedNumsSize += 1;
    }

    *(shuffedPass+input.length()) = '\0';
    string strShuffedPass = string(shuffedPass);
    delete[] shuffedPass;
    delete[] usedNums;

    return strShuffedPass;

}

int main() {
    srand(time(0));

    Generator gen;
    gen.setPara();
    
    string pass = gen.genPass();
    string shuffedPass = shuffle(pass);

    cout << endl;
    cout << "Password: " + pass << endl;
    cout << "Shuffed: " + shuffedPass << endl;
    cout << endl;

    system("pause");
}