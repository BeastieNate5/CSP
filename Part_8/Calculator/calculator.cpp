#include <iostream>
#include <string>
using namespace std;

class Calculator {
    public:
        Calculator();
    
    private:
        float num1;
        float num2;
        bool first = true;

        int getOperator(); 

};

int Calculator::getOperator() {
    cout << "Choose a operator (+, -, *, /): ";
    string symbols[4] = {'+', '-', '*', "/"};

    string userInput;
    getline(cin, userInput);

    bool checked = false;
    for (int i = 0; i < 4; i++) {
        if (userInput == symbols[i]) {
            checked = true;
        }
    }


}

int main() {
    // Not done
}
