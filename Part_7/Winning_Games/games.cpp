#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Games {
    public:
        static void genUniqueAry(int* arry);    
    private:
        static void genRanAry(int* arry);
        int uniqueAry[3];
};

bool check(int* ptrAry) {
    int nums[3];
    int size = 0;


    // Loop through the generated ary
    for (int i = 0; i < 3; i ++) {

        // Skip checking if the current index is already in the nums array
        if (i != 0) {
            // Loop through the nums ary to check if the current index is already in the ary
            for (int x = 0; x < size; x++) {
                
                // If the current index equals a number in the nums array return false (0)
                if (*(ptrAry+i) == nums[x]) {
                    return false;
                }
            }
        }

        nums[i] = *(ptrAry+i);
        size += 1;
    }

    return true;
}

void Games::genRanAry(int* arry) {

    for (int i = 0; i < 3; i++) {
        *(arry+i) = 1 + (rand() % 5);
    }

}

void Games::genUniqueAry(int* arry) {
    int tries = 1;

    while (check(arry) == false) {
        Games::genRanAry(arry);
        tries += 1;
    }
    
    *(arry+3) = tries;

}

int main() {
    srand(time(0));
    int ary[4] = {0, 0, 0, 0};

    // ary = {2,   1,   3,   4}
    //        ^    ^    ^    ^
    //       num  num  num tries

    Games::genUniqueAry(ary);

    cout << "Array: ";

    for (int i = 0; i < 3; i++) {
        cout << to_string(ary[i]) + " ";
    } 


    
    cout << endl;
    cout << "Tries: " + to_string(ary[3]) << endl;

    cout << endl;
    system("pause");
}