#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Height {
    public:
        void getTime();
        float getHeight();
        float time = 0;
};

void Height::getTime() {
    string time;
    cout << "Enter a time less than 4.5: ";
    
    try {
        getline(cin, time);
        float time_f = stof(time);

        if (time_f < 4.5) {
            this->time = time_f;
        }
        else {
            cout << "Height must be less than 4.5" << endl;
            return this->getTime();
        }
    }

    catch (...) {
        cout << "Invalid number, try again" << endl;
        return this->getTime();
    }
}

float Height::getHeight() {
    float height = 100-4.9*(pow(this->time, 2));
    return height;
}

int main() {
    Height height_obj;
    height_obj.getTime();

    float height = height_obj.getHeight();

    string full_txt = "Time: " + to_string(height_obj.time) + "\nHeight: " + to_string(height);
    cout << "=============== Height Results ===============" << endl;
    cout << full_txt << endl;
    cout << "==============================================" << endl;

    system("pause");
}