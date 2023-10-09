#include <iostream>
#include <string>
using namespace std;

string getCity() {
    string city;
    cout << "What's the name of the city you grew in? ";
    getline(cin,city);
    cout << endl;

    return city;
}

string getPet() {
    string pet;
    cout << "What's your pet's name? ";
    getline(cin,pet);
    cout << endl;

    return pet;
}

int main() {
    string idk;
    cout << "Welcome to the Band Name Generator" << endl;
    string user_city = getCity();
    string user_pet = getPet();

    string full_band_name = "Your band name could be " + user_city + " " + user_pet;
    cout << full_band_name << endl;

    cout << "Press enter to close";
    system("pause");
    
}