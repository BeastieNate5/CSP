#include <iostream>
#include <string>
using namespace std;

class Change {
    public:
        float money;
        void setMoney();
        void setChange();
        int* getChange();
    
    private:
        int change[4];

};

void Change::setMoney() {
    string userInput;
    cout << "Enter amount of money less than $1.00 dont put \".\": ";
    getline(cin, userInput);

    try {
        stoi(userInput);

        if (userInput.find(".") != string::npos) {
            cout << "Remove \".\" from input" << endl << endl;
            return Change::setMoney();
        }

        if (stoi(userInput) >= 100) {
            cout << "Number must be 99 or less" << endl << endl;
            return Change::setMoney();
        }
    }

    catch (...) {
        cout << "Invalid number try again" << endl << endl;
        return Change::setMoney();
    }

    this->money = stof(userInput);
}

void Change::setChange() {
    // 0 = quaters
    // 1 = dime
    // 2 = nickel
    // 3 = pennies

    int total = this->money;

    // quaters
    this->change[0] = (total / 25);
    total -= (this->change[0] * 25);

    // dimes
    this->change[1] = (total / 10);
    total -= (this->change[1] * 10);

    // nickles
    this->change[2] = (total / 5);
    total -= (this->change[2] * 5);

    this->change[3] = total;

}

int* Change::getChange() {
    return this->change;
}


int main() {
    Change changer;
    changer.setMoney();
    changer.setChange();

    int* ptrChange = changer.getChange();

    string txt = "Quarters: " + to_string(*(ptrChange)) + "\n" + "Dimes: " + to_string(*(ptrChange+1)) + "\n" + "Nickles: " + to_string(*(ptrChange+2)) + "\n" + "Pennies: " + to_string(*(ptrChange+3));

    cout << txt << endl << endl;

    system("pause");
}