#include <iostream>
#include <string>
using namespace std;


class Sum {
    public:
        static int add(int num1, int num2);
};

int Sum::add(int num1, int num2) {
    int total = 0;

    for (int i = num1; i <= num2; i++) {
        total += i;
    }

    return total;
}

int getNumber(string promt) {
    string userInput;
    cout << promt;
    getline(cin, userInput);

    try {
        stoi(userInput);
    } catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return getNumber(promt);
    }

    if (stoi(userInput) < 1) {
        cout << "value must be greater than 1" << endl;
        return getNumber(promt);
    }

    return stoi(userInput);

}

int main() {
    int userNum1 = getNumber("Enter number 1: ");
    int userNum2 = getNumber("Enter number 2: ");
    int total = Sum::add(userNum1, userNum2);

    cout << endl;
    cout << "Total: " + to_string(total);
    cout << endl << endl;

    system("pause");

}