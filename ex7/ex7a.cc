//-------------- include section --------------
#include <iostream>
#include <cctype>
#include <cstring>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::toupper;
using std::isalpha;
using std::strlen;

//-------------- const and enum section --------------
const int MAX_STR_LEN = 100;

//-------------- functions section -------------------
// function to read input from the user
void readInput(char userInput[], int MAX_STR_LEN);

// this function removes all non-letter characters, and converts all 
// lowercase letters to uppercase.
void upper(char userInput[], char result[], int& len);

// this function removes all matching char in the two arrays 
void rmMatching(char userInputOne[], char userInputTwo[], int& lenOne, int lenTwo);

//-------------- main --------------
int main() {
    // declare character arrays
    char userInputOne[MAX_STR_LEN];
    char userInputTwo[MAX_STR_LEN];
    char result[MAX_STR_LEN];

    // Call function to read user input 
    readInput(userInputOne, MAX_STR_LEN);
    readInput(userInputTwo, MAX_STR_LEN);

    // Get length of the first input string and the secend one
    int lenOne = strlen(userInputOne);
    int lenTwo = strlen(userInputTwo);

    // calling the function upper the converts all lowercase 
    // letters to uppercase and remove non letter characters
    upper(userInputOne, result, lenOne);

    // calling the function that removes all matching characters
    rmMatching(userInputOne, userInputTwo, lenOne, lenTwo);

    return EXIT_SUCCESS;
}

// read user input 
void readInput(char userInput[], int MAX_STR_LEN) {
    cin.getline(userInput, MAX_STR_LEN);
}

// this function removes all non letter characters and converts all 
// lowercase letters to uppercase.
void upper(char userInput[], char result[], int& len) {
    int newLen = 0; // counter that tracks how many valid characters
    // looping through all chars in the array 
    for (int i = 0; i < len; i++) {
        if (isalpha(userInput[i])) {
            // add all uppercase letters
            result[newLen] = toupper(userInput[i]);
            // move to the next line 
            newLen++;
        }
    }
    result[newLen] = '\0'; // adding null terminate

    // output 
    cout << result << "\n";
}

// this function removes all matching char in the two arrays 
void rmMatching(char userInputOne[], char userInputTwo[], int& lenOne, int lenTwo) {
    int newLen = 0; // counter that tracks how many valid characters
    // loop through each character in the first string
    for (int i = 0; i < lenOne; i++) {
        bool matchFound = false;
        // loop through each character in the second string
        for (int j = 0; j < lenTwo; j++) {
            // if there is a match break 
            if (userInputOne[i] == userInputTwo[j]) {
                matchFound = true;
                break;
            }
        }
        // if there is no match save the character
        if (!matchFound) {
            userInputOne[newLen] = userInputOne[i];
            newLen++;
        }
    }
    userInputOne[newLen] = '\0'; // adding null terminate
     
    // output 
    cout << userInputOne << "\n";
}
