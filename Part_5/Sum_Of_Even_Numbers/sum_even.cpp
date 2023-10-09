#include <iostream>
#include <string>

using namespace std;

int main () {
    int total = 0;

    for (int i = 1; i <= 100; i++) {
        if ((i%2) == 0) {
            total += i;
        }
    }

    cout << "Total: " + to_string(total);
    cout << endl << endl;
    system("pause");
}