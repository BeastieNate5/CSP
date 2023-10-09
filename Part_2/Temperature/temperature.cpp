#include <iostream>
#include <string>
using namespace std;

class Temperature {
    public:
        void setF();
        float getC();
        float getF();
    
    private:
        float F;
        float C;
};

void Temperature::setF() {
    string f;
    cout << "Temperature in Fahrenheit: ";
    getline(cin, f);

    try {
        this->F = stof(f);
    }
    catch (...) {
        cout << "Invalid number, try again" << endl;
        this->setF();
    }

}

float Temperature::getC() {
    return ((5.0/9.0) * (this->F - 32));
}

float Temperature::getF() {
    return this->F;
}

int main() {
    Temperature temp;
    temp.setF();

    string full_txt = to_string(temp.getF()) + "\n" + to_string(temp.getC());
    
    cout << "=============== Celsius Converter ===============" << endl;
    cout << full_txt << endl;
    cout << "=================================================" << endl;

    system("pause");
}