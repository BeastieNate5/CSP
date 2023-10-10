#include <iostream>
#include <string>
using namespace std;

class Calculator {
    public:
        float doOperation(float num1, float num2);
        void getOperator(); 
    
    private:
        float num1;
        float num2;
        int op;

};

void Calculator::getOperator() {
    // This method asks the user what operation they would like to use
    // 1 = +
    // 2 = -
    // 3 = *
    // 4 = /
    cout << "Choose a operator (+, -, *, /): ";
    string symbols[4] = {"+", "-", "*", "/"};

    string userInput;
    getline(cin, userInput);

    bool checked = false;
    for (int i = 0; i < 4; i++) {
        if (userInput == symbols[i]) {
            checked = true;
        }
    }

    if (userInput == "+") {
        this->op = 1;
    } else if (userInput == "-") {
        this->op = 2;
    } else if (userInput == "*") {
        this->op = 3;
    } else {
        this->op = 4;
    }


}

float Calculator::doOperation(float num1, float num2) {
    int answer;

    if (op == 1) {
        answer = num1 + num2;
    } else if (op == 2) {
        answer = num1 - num2;
    } else if (op == 3) {
        answer = num1 * num2;  
    } else {
        if (num2 == 0) {
            return -1;
        }
        answer = num1 / num2;
    }

    return answer;
}

float getValidNumber(string prompt) {
    cout << prompt;
    string userInput;
    getline(cin, userInput);

    try {
        stof(userInput);
    } catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return getValidNumber(prompt);
    }

    return stof(userInput);
}

// This will ask the user if they want to keep going
bool goAgain(string prompt) {
    cout << prompt;
    string userInput;
    getline(cin, userInput);

    if (userInput.length() == 1) {
        int asciiCode = (int)((char)(userInput[0]));
        
        if (asciiCode == 89 || asciiCode == 121) {
            return true;
        } else if (asciiCode == 78 || asciiCode == 110) {
            return false;
        } else {
            cout << "Invalid option, try again" << endl << endl;
            return goAgain(prompt);
        }

    } else {
        cout << "Invalid answer, try again" << endl << endl;
        return goAgain(prompt);
    }
}

int main() {
    bool runtime = true;
    Calculator cal;
    int i = 0;
    float answer;
    float userNum;

    while (runtime == true) {
        if (i == 0) {
            answer = getValidNumber("What's the first number?: ");
        }

        cal.getOperator();

        userNum = getValidNumber("What's the next number?: ");
        answer = cal.doOperation(answer, userNum);

        string prompt = "Type 'y' to continue calculating with " + to_string(answer) + ", or type 'n' to start a new calculation: ";
        runtime = goAgain(prompt);
        i += 1;
    }
}