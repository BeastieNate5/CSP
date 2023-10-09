#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Tip {
    public:
        void setBill();
        void setTip();
        void setSplit();
        float getTotalBill();
    
    private:
        float bill;
        float tipPer;
        int split;
};


void Tip::setBill() {
    string locBill;
    cout << "What was the total bill $";
    getline(cin, locBill);

    try {
        stof(locBill);
    }

    catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return Tip::setBill();
    }

    this->bill = stof(locBill);
    
}

void Tip::setTip() {
    int validTips[3] = {10,12,15};
    string locTip;
    cout << "How much would you like to tip? 10, 12, or 15? ";
    getline(cin, locTip);

    try {
        stoi(locTip);

    }

    catch (...) {
        cout << "Invalid number try again" << endl << endl;
        return setTip();
    }

    bool equal = false;
    for (int i = 0; i < 3; i++) {
        if (validTips[i] == stoi(locTip)) {
            equal = true;
        }
    }

    if (equal == false) {
        cout << "Tip amount must be 10, 12, or 15. Try again" << endl << endl;
        return Tip::setTip();
    }

    this->tipPer = stof(locTip) / 100;

}

void Tip::setSplit() {
    string locSplit;
    cout << "How many people to split the bill: ";
    getline(cin, locSplit);

    try {
        stoi(locSplit);
    }

    catch (...) {
        cout << "Invalid number try again" << endl << endl; 
        return Tip::setSplit();
    }

    this->split = stoi(locSplit);
}

float Tip::getTotalBill() {
    float billTip = this->bill + (this->bill * this->tipPer);
    float personPay = billTip / this->split;

    return personPay;
}

int main() {
    Tip tipCal;
    tipCal.setBill();
    tipCal.setTip();
    tipCal.setSplit();

    float pay = tipCal.getTotalBill();

    cout << "Each person should pay: $";
    printf("%.2f", pay);
    cout << endl << endl;

    system("pause");
}