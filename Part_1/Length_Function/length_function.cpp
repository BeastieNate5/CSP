#include <iostream>
#include <string>
using namespace std;

class Address {
    public:
        void setStreet();
        void setCity();
        void setState();
        void setZip();

        string getStreet();
        string getCity();
        string getState();
        string getZip();

    private:
        string street;
        string city;
        string state;
        string zip;
};

void Address::setStreet() {
    cout << "What is your street address? ";
    getline(cin, this->street);

    cout << endl;
}

void Address::setCity() {
    cout << "What is your city? ";
    getline(cin, this->city);

    cout << endl;
}

void Address::setState() {
    cout << "What is your state? ";
    getline(cin, this->state);

    cout << endl;
}

void Address::setZip() {
    cout << "What is your zip code? ";
    getline(cin, this->zip);
    cout << endl;

    try {
        stoi(this->zip);
    }
    catch (...) {
        cout << "Invalid number, try again" << endl;
        return this->setZip();
    }
}

string Address::getStreet() {
    return this->street;
}

string Address::getCity() {
    return this->city;
}

string Address::getState() {
    return this->state;
}

string Address::getZip() {
    return this->zip;
}

int main() {
    Address address;
    address.setStreet();
    address.setCity();
    address.setState();
    address.setZip();

    string street = address.getStreet();
    string city = address.getCity();
    string state = address.getState();
    string zip = address.getZip();

    string full_txt = street + " " + to_string(street.length()) + ", " + city + " " + to_string(city.length()) + ", " + state + " " + to_string(state.length()) + " " + zip + " " + to_string(zip.length());
    cout << full_txt << endl;

    system("pause");    
}