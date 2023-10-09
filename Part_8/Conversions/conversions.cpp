#include <iostream>
#include <string>
using namespace std;

class Conversions {
    public:
        static float inchToCen(float num);
        static float feetToCen(float num);
        static float yardsToMeters(float num);
        static float milesToKilo(float num);
        static void showOptions();
        static int getValidOption();
};

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

    return stoi(userInput);
}

float getValidFloat(string prompt) {
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

float Conversions::inchToCen(float num) {
    return (num * 2.54);
}

float Conversions::feetToCen(float num) {
    return (num * 30.48);
}

float Conversions::yardsToMeters(float num) {
    return (num * 0.91);
}

float Conversions::milesToKilo(float num) {
    return (num * 1.6);
}

void Conversions::showOptions() {
    cout << "Which conversion would you like? Just type the number" << endl << endl;
    cout << "   Input          Output" << endl;;
    cout << "1. Inches ----> Centimeters" << endl;
    cout << "2. Feet   ----> Centimeters" << endl;
    cout << "3. Yards  ----> Meters" << endl;
    cout << "4. Miles  ----> Kilometers" << endl << endl;
}

int Conversions::getValidOption() {
    int userNum = getValidNumber("Select option: ");

    if (userNum >= 1 && userNum <= 4) {
        return userNum;
    } else {
        cout << "Invalid option, try again" << endl << endl;
        return Conversions::getValidOption();
    }
}

int main() {
    Conversions::showOptions();
    int userOption = Conversions::getValidOption();

    string inputUnit;
    string outUnit;
    float output;
    float input;

    switch (userOption) {
        case 1:
            input = getValidFloat("Enter inch(es): ");
            output = Conversions::inchToCen(input);
            inputUnit = "in";
            outUnit = "cm";
            break;
        
        case 2:
            input = getValidFloat("Enter feet(s): ");
            output = Conversions::feetToCen(input);
            inputUnit = "ft";
            outUnit = "cm";
            break;
        
        case 3:
            input = getValidFloat("Enter yard(s): ");
            output = Conversions::yardsToMeters(input);
            inputUnit = "yd";
            outUnit = "m";
            break;
        
        case 4:
            input = getValidFloat("Enter mile(s): ");
            output = Conversions::milesToKilo(input);
            inputUnit = "mi";
            outUnit = "km";
            break;

        }

    cout << endl;
    printf("%.2f", input);
    cout << inputUnit;

    cout << " ----> ";

    printf("%.2f", output);
    cout << outUnit;

    cout <<endl << endl;

    system("pause");
}