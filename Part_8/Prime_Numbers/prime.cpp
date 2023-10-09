#include <iostream>
#include <string>
using namespace std;

bool checkPrime(int num) {
    static int i = 2;

    // 0 and 1 can not be prime numbers
    if (num == 0 || num == 1) {
        return false;
    }

    // In this case it has to be a prime number because it was divided by all numbers
    // before it and it had a remainder
    if (num == i) {
        return true;
    }


    // In this case it is not a prime number
    if (num % i == 0) {
        return false;
    }

    i++;
    return checkPrime(num);

}

int getValidNumber(string prompt) {
    cout << prompt;

    string userInput;
    getline(cin, userInput);

    try {
        stoi(userInput);
    } catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return getValidNumber(prompt);
    }

    if (stoi(userInput) < 0) {
        cout << "Number must be greater than 0" << endl << endl;
        return getValidNumber(prompt);
    }

    return stoi(userInput);
}

int main() {
    int userNum = getValidNumber("Enter number: ");

    bool prime = checkPrime(userNum);

    prime ? cout << "This number is prime" : cout << "This number is not prime";

    cout << endl << endl;

    system("pause");

}