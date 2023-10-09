#pragma once
#include <string>
#include <iostream>

using namespace std;

class Password {
    public:
        static string getPassword();
        static void checkPassword(string Password, int* codes);
        static string codeResults(int* codes);
    private:
        char lowerLetters[27];
        char highLetters[27];
};