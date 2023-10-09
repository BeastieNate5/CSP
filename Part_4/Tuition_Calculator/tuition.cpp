#include <iostream>
#include <string>

using namespace std;

class Tuition {
    public:
        void setCourse();
        void setHours();
        void getTotal();

    private:
        // 0 = undergraduate
        // 1 = graduate
        // 2 = doctorate
        int coursework;
        int hours;
};

string lower(string input) {
    int length = input.length();

    for (int i = 0; i < length; i++) {
       input[i] = (char) tolower(input[i]);
    }

    return input;

}

void Tuition::setCourse() {
    string userInput;
    string validOptions[3] = {"undergraduate", "graduate", "doctorate"};
    cout << "Which coursework undergraduate, graduate, doctorate? ";
    getline(cin, userInput);
    userInput = lower(userInput);

    bool checked = false;
    for (int i = 0; i < 3; i ++) {
        if (userInput == validOptions[i]) {
            checked = true;
        }
    }

    if (checked == false) {
        cout << "Invalid option try again" << endl << endl;
        this->setCourse();
    }

    if (userInput == "undergraduate") {
        this->coursework = 0;
    } else if (userInput == "graduate") {
        this->coursework = 1;
    } else {
        this->coursework = 2;
    }
}


void Tuition::setHours() {
    int valid[7] = {3,6,9,12,15,18,21};
    string userInput;
    cout << "How many credit hours 3, 6, 9, 12, 15, 18 or, 21? ";
    getline(cin, userInput);

    try {
        stoi(userInput);
    } catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return this->setHours();
    }

    bool checked = false;
    for (int i = 0; i < 7; i++) {
        if (stoi(userInput) == valid[i]) {
            checked = true;
        }
    }

    if (checked == false) {
        cout << "Invalid option, try again" << endl << endl;
        return this->setHours();
    }

    this->hours = stoi(userInput);
    
};

void Tuition::getTotal() {
    string course;
    int price;

    if (this->coursework == 0) {
        course = "Undergraduate";
        price = this->hours * 300;
    } else if (this->coursework == 1) {
        course = "Graduate";
        price = this->hours * 400;
    } else {
        course = "Doctorate";
        price = this->hours * 500;
    }
    
    cout << endl;
    cout << "========== Tuition ==========" << endl;
    cout << "Coursework: " + course << endl;
    cout << "Credit Hours: " + to_string(this->hours) << endl;
    cout << "Total: $" + to_string(price) << endl;
    cout << "=============================" << endl;
}

int main() {
    Tuition tuition;
    tuition.setCourse();
    tuition.setHours();
    tuition.getTotal();

    cout << endl;

    system("pause");
}