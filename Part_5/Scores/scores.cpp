#include <iostream>
#include <string>
using namespace std;

class Scores {
    public:
        Scores(int amount);
        int max();
        int min();
        float avg();
        void getNumbers();
    private:
        int* scores;
        int amount;

};

int getNumber(string prompt) {
    string userInput;
    cout << prompt;
    getline(cin, userInput);

    try {
        stoi(userInput);
    } catch (...) {
        cout << "Invalid number, try again";
        return getNumber(prompt);
    }

    if (stoi(userInput) >= 1 && stoi(userInput) <= 100) {
        return stoi(userInput);
    } else {
        return getNumber(prompt);
    }

}

Scores::Scores(int amount) {
    scores = new int[amount];
    this->amount = amount;
}

void Scores::getNumbers() {
    for (int i = 0; i < this->amount; i++) {
        string prompt = "Enter number " + to_string(i+1) + ": ";
        int number = getNumber(prompt);
        *(this->scores+i) = number;
    }
}

int Scores::max() {
    int max = *(this->scores);

    for (int i = 1; i < this->amount; i++) {
        if (*(this->scores+i) > max) {
            max = *(this->scores+i);
        }
    }

    return max;
}

int Scores::min() {
    int min = *(this->scores);

    for (int i = 1; i < this->amount; i++) {
        if (*(this->scores+i) < min) {
            min = *(this->scores+i);
        }
    }

    return min;
}

float Scores::avg() {
    int total;

    for (int i = 0; i < this->amount; i++) {
        total = *(this->scores+i);
    }

    return (total/this->amount);

}


int main() {
    int amount = getNumber("How many elements do you want in the list? ");
    Scores scor(amount);
    scor.getNumbers();

    cout << endl;
    cout << "Max: " + to_string(scor.max()) << endl;
    cout << "Min: " + to_string(scor.min()) << endl;
    cout << "Avg: " + to_string(scor.avg()) << endl;
    cout << endl;

    system("pause");
}