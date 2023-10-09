#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int paint(int height, int width) {
    // must convert height and width to floats to divide correctly
    float heightF = static_cast<float>(height);
    float widthF = static_cast<float>(width);

    float cans = (heightF*widthF) / 5;
    return ceil(cans);
}

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

    if (stoi(userInput) < 1) {
        cout << "Number must be greater than 0" << endl << endl;
        return getValidNumber(prompt); 
    }

    return stoi(userInput);

}

int main() {
    int height = getValidNumber("Enter height of wall: ");
    int width = getValidNumber("Enter width of wall: ");
    int cans = paint(height, width);

    cout << endl;
    cout << "Cans needed: " + to_string(cans) << endl << endl;

    system("pause");
}