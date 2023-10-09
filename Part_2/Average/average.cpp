#include <iostream>
#include <string>
using namespace std;


class Average {
    public:
        Average(float* nums, int size);
        float getAvg();
    
    private:
        float* ptrNums;
        int size;

};

Average::Average(float* nums, int size) {
    this->ptrNums = nums;
    this->size = size;
}

float Average::getAvg() {
    float total;

    for (int i = 0; i < this->size; i++) {
        total += *(this->ptrNums+i);
    }

    float avg = total / this->size;
    return avg;
}


int getAmountJumps() {
    string amount;
    cout << "How many jumps do you want to input? ";
    getline(cin, amount);

    try {
        stoi(amount);
    }
    catch (...) {
        cout << "Invalid number, try again" << endl;
        return getAmountJumps();
    }

    return stoi(amount);

}

float getValidNumber(string promt) {
    string input;
    cout << promt;

    getline(cin, input);

    try {
        stof(input);
    }

    catch (...) {
        cout << "Invalid number, try again" << endl;
        return getValidNumber(promt);
    }

    return stof(input);
    
}

float* getJumps(int amount) {
    float * jumps;
    jumps = new float[amount];

    for (int i = 0; i < amount; i++) {
        string txt = "Enter jump " + to_string(i+1) + ": ";
        float jump = getValidNumber(txt);
        jumps[i] = jump;
        
    }

    return jumps;
}


int main() {
    int amount = getAmountJumps();
    float* ptrJumps = getJumps(amount);

    Average avg(ptrJumps, amount);
    float average = avg.getAvg();

    string txt = "Average: " + to_string(average);

    cout << txt << endl;

    system("pause");
}

