#include <iostream>
#include <string>

using namespace std;

class Copies {
    public:
        void setAmount();
        void printReceipt();

    private:
        float getPrice();
        int amount;
        float price;
};

void Copies::setAmount() {
    string userInput;
    cout << "How many copies do you want? ";
    getline(cin, userInput);

    try {
        stoi(userInput);
        cout << endl;
    }

    catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return Copies::setAmount();
    }

    this->amount = stoi(userInput);

    if (this->amount < 500) {
        this->price = 0.30;
    }

    else if (this->amount < 750) {
        this->price = 0.28;
    }

    else if (this->amount < 1000) {
        this->price = 0.27;
    }  

    else {
        this->price = 0.25;
    }

}


float Copies::getPrice() {
    return this->amount * this->price; 
}  

void Copies::printReceipt() {
    float price = this->getPrice();

    cout << "=============== Receipt ===============" << endl;
    cout << "Amount: " << to_string(this->amount) << endl;
    cout << "Price per copy: $";
    printf("%.2f", this->price);
    cout << endl;
    cout << "Total price: $";
    printf("%.2f", price);
    cout << endl;
    cout << "=======================================";
}

int main() {
    Copies copies;
    copies.setAmount();

    copies.printReceipt();

    cout << endl << endl; 

    system("pause");
}