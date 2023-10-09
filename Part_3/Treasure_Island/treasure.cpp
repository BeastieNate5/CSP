#include <iostream>
#include <string>

using namespace std;

class Treasure {
    public:
        void playGame();
    private:
        int crossRoad();
        int lake();
        int island();
};

// Global methods
string lower(string input) {
    int length = input.length();

    for (int i = 0; i < length; i++) {
        char letter = input[i];
        input[i] = (char)tolower(letter);
    }

    return input;
}

string getInput(string promt, string* options, int size) {
    string userInput;
    cout << promt;
    getline(cin, userInput);

    bool checked = false;
    for (int i = 0; i < size; i++) {
        if (userInput == *(options+i)) {
            checked = true;
        }
    }

    if (checked == true) {
        return lower(userInput); 
    } else {
        cout << "Invalid option, try again" << endl << endl;
        return getInput(promt, options, size);
    }
}

// Class methods
int Treasure::crossRoad() {
    // 1 = Game over
    // 0 = go on
    string options[2] = {"left", "right"};
    string userInput = getInput("You're at a cross road. Where do you want to go? Type \"left\" or \"right\": ", options, 2);

    if (userInput == "left") {
        return 0;
    } else {
        return 1;
    }
}

int Treasure::lake() {
    // 1 = Game over
    // 0 = go on

    string options[2] = {"swim", "wait"};
    string userInput = getInput("You've come to a lake. There is an island in the middle of the lake. Type \"wait\" to wait for a boat. Type \"swim\" to swim across: ", options, 2);

    if (userInput == "wait") {
        return 0;
    } else {
        return 1;
    }

}   

int Treasure::island() {
    // 1 = Game over (fire)
    // 2 = Game over (eaten)
    // 0 = win

    string options[3] = {"red", "blue", "yellow"};
    string userInput = getInput("You arrive at the island unharmed. There is a house with 3 doors. One red, one yellow, and one blue. Which colour do you choose? ", options, 3);

    if (userInput == "yellow") {
        return 0;
    } else if (userInput == "red") {
        return 1;
    } else {
        return 2;
    }
}

void Treasure::playGame() {
    cout << "Welcome to Treausre Island." << endl << "Your mission is to find the treasure." << endl << endl;

    if (this->crossRoad() == 0) {

        cout << endl << endl;
        if (this->lake() == 0) {
            
            cout << endl << endl;
            int final = this->island();
            if (final == 0) {
                cout << "You Win!" << endl;
            } else if (final == 1) {
                cout << "Burned by fire." << endl << "Game Over." << endl;
            } else if (final == 2) {
                cout << "Eaten by beasts." << endl << "Game Over." << endl;
            }

        } else {
            cout << "Attacked by trout." << endl << "Game Over" << endl;
        }

    } else {
        cout << "Fall into a hole." << endl << "Game Over." << endl;
    }
}

int main() {
    Treasure game;
    game.playGame();

    cout << endl << endl;

    system("pause");
}