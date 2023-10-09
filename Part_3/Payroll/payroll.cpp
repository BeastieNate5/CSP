#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Payroll {
    public:
        void setHours();
        void setPay();
        void setTax();
        void getPayCheck();
    private:
        float pay;
        int hours;
        bool overtime;
        int hoursOver;
        bool tax;
};

void Payroll::setHours() {
    string userInput;
    cout << "How many hours did you work this week? ";
    getline(cin, userInput);

    try {
        stoi(userInput);
    }

    catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return this->setHours();
    }

    int hours = stoi(userInput);

    if (hours > 40) {
        this->overtime = true;
        this->hoursOver = (hours - 40) * 1.5;
        this->hours = 40;
    }

    else {
        this->hours = hours;
        this->overtime = false;
        this->hoursOver = 0;
    }

}

void Payroll::setPay() {
    string userInput;
    cout << "What is your hourly pay rate? ";
    getline(cin, userInput);

    try {
        stof(userInput);
    }
    
    catch (...) {
        cout << "Invalid number, try again" << endl << endl;
    }

    char* num = new char[userInput.length() + 1];

    strcpy(num, userInput.c_str());
    bool dot = false;
    int afterDot=0;

    for (int i = 0; i<userInput.length(); i++) {
        char character = *(num+i);
        
        if (dot == true) {
            afterDot += 1;
        }

        if (character == '.') {
            dot = true;
        }
    }

    if (afterDot > 2) {
        cout << "Invalid pay, try again" << endl << endl;
        return this->setPay();
    }

    this->pay=stof(userInput);

}

void Payroll::setTax() {
    char userInput[2];
    cout << "Are you tax deducted? (y/n): ";
    cin.getline(userInput, 2);

    int asciiCode = (int)userInput[0];

    if ((asciiCode >= 65 && asciiCode <= 90) || (asciiCode >= 97 && asciiCode <= 122)) {
        
        if (asciiCode <= 90) {
            asciiCode += 32;
        }

        if (asciiCode == 121) {
            this->tax = true;
        } else if (asciiCode == 110) {
            this->tax = false;
        } else {
            cout << "Invalid option, try again" << endl << endl;
            this->setTax();
        }

    } else {
        cout << "Invalid character, try again" << endl << endl;
        this->setTax();
    }
    
}

void Payroll::getPayCheck() {
    this->setHours();
    this->setPay();
    this->setTax();

    cout << endl;

    string txt = "";
    string taxTxt;
    float totalPay;    

    float pay = this->pay * (this->hours + this->hoursOver);

    if (this->tax == true) {
        taxTxt = "Yes";
        totalPay = pay - (pay * 0.18);
        
    } else {
        taxTxt = "No";
        totalPay = pay;
    }

    cout << "========== Pay Check ==========" << endl;
    cout << "Hours: " + to_string(this->hours) + "hr(s)" + "\n";
    cout << "Overtime: " + to_string(this->hoursOver) + "hr(s)" + "\n";

    cout << "Gross Pay: $";
    printf("%.2f", pay); 
    cout << endl;

    cout << "Tax Exempt: " + taxTxt + "\n";

    cout << "Net Pay: $";
    printf("%.2f", totalPay);
    cout << endl;

    cout << "===============================" << endl;

}

int main() {
    Payroll pay;
    pay.getPayCheck();
    
    cout << endl << endl;
    system("pause");
}