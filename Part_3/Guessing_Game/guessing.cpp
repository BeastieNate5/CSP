#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Game {
    public:
        void play();
    
    private:
        int number;
        int getNum();
        void genNum();
};

int Game::getNum() {
    string number;
    cout << "Guess a number between 1 and 10: ";
    getline(cin, number);

    try {
        stoi(number);

        if (stoi(number) > 10 || stoi(number) < 0) {
            cout << "The number must be between 1 and 10, try again" << endl << endl;
            return this->getNum();
        }
    }

    catch (...) {
        cout << "Invalid number, try again" << endl << endl;
        return this->getNum();
    }

    return stoi(number);
}

void Game::genNum() {
    time_t currentTime = time(NULL);
    srand(currentTime);

    int num = 1 + (rand() % 10);
    this->number = num;
}

void Game::play() {
    this->genNum();

    bool playing = true;

    while (playing) {
        int userNum = this->getNum();

        if (userNum == this->number) {
            cout << "YOU GUESSED IT!";
            playing = false;
        }

        else if (userNum > this->number) {
            cout << "Guess to high" << endl << endl;
        }

        else if (userNum < this->number) {
            cout << "guess too low" << endl << endl;
        }

    }
    
}

int main() {
    Game game;
    game.play();

    cout << endl << endl;
    system("pause");

}