#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Triangle {
    public:
        void setSides();
        float getHypo();
    
    private:
        float sideA;
        float sideB;
};

// Normal defs
float getValidNumber(string prompt) {
    string userInput;
    
    cout << prompt;
    getline(cin, userInput);

    try {
        stof(userInput);
    }
    
    catch (...) {
        cout << "Invaild number, try again" << endl;
        return getValidNumber(prompt);
    }

    return stof(userInput);
}


// Class defs
void Triangle::setSides() {
    float sides[2];

    for (int i = 0; i < 2; i++) {
        string txt = "Enter side " + to_string((i+1)) + ": ";
        sides[i] = getValidNumber(txt);
    }

    this->sideA = sides[0];
    this->sideB = sides[1];
}

float Triangle::getHypo() {
    float hypo = sqrt(pow(this->sideA, 2) + pow(this->sideB, 2));

    return hypo;
}


int main() {
    Triangle tri;
    tri.setSides();
    float hypo = tri.getHypo();

    string txt = "Hypoteneuse: " + to_string(hypo);
    cout << txt << endl << endl;
    system("pause");
}