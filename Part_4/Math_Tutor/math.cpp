#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Tutor {
    public:
        void generateMath();
        void checkAnswer(int answer);
        int getAnswer();
        bool askAgain();
    private:
        int answer;
};

void Tutor::generateMath() {
    time_t currentTime = time(NULL);
    srand(currentTime);

    int op = (rand() % 4) + 1;
    int num1 = (rand()  %  10) + 1;
    int num2 = (rand() % 10) + 1;

    if (op == 1) {
        cout << to_string(num1) + " " + "+" + " " + to_string(num2) << endl;
        this->answer = num1+num2;
    } else if (op == 2) {
        cout << to_string(num1) + " " + "-" + " " + to_string(num2) << endl;
        this->answer = num1-num2;
    } else if (op == 3) {
        cout << to_string(num1) + " " + "x" + " " + to_string(num2) << endl;
        this->answer = num1*num2;
    } else if (op == 4) {
        cout << to_string(num1) + " " + "/" + " " + to_string(num2) << endl;
        this->answer = num1/num2;
    }

}

void Tutor::checkAnswer(int answer) {
    if (answer == this->answer) {
        cout << "Correct answer" << endl;
    } else {
        cout << "Incorrect answer" << endl;
    }
}

int Tutor::getAnswer() {
    string userInput;
    cout << "Answer: ";
    getline(cin, userInput);

    try {
        stoi(userInput);
    }  
    
    catch (...) {
        cout << "Invalid number try again" << endl;
        return this->getAnswer();
    }

    return stoi(userInput);
}

bool Tutor::askAgain() {
    char userInput[2];

    cout << "Would you like another problem: ";
    cin.getline(userInput, 2);

    int asciiCode = (int)userInput[0];

    char returnValue;

    if ((asciiCode >= 65 && asciiCode <= 90) || (asciiCode >= 97 && asciiCode <= 122)) {

        if (asciiCode >= 65 && asciiCode <= 90) {
            asciiCode + 32;
        }

    } else {
        cout << "Invalid option, try again" << endl;
        return this->askAgain();
    }

    if (asciiCode == 121) {
        cout << endl;
        return true;
    } else {
        return false;
    }
    
}

int main() {
    Tutor tutor;

    bool playing = true;

    while (playing == true) {
        tutor.generateMath();
        int userAnswer = tutor.getAnswer();

        tutor.checkAnswer(userAnswer);

        cout << endl;
        playing = tutor.askAgain();
    }

    cout << endl << endl;

    system("pause");
}