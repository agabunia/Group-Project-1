#include <iostream>
#include <string.h>
using namespace std;



// Global variable list with definitions
string userInput;           //The string variable where user enters the roman numbers
char oper;                  // The char variable where user enters the operation between numbers
string check;               // The string variable, which is used to break while-loop in the calculator
int calculatedNumber = 0;   //the variable where calculations are cumulated


// Code below converts roman numbers to ordinary integers
//The function that takes entered roman argument and returns equivalent integer value
int roman_to_int(string roman){
    int n = int(roman.length());

    int convertedRoman = 0;

    if (n == 0){
        return 0;
    }

    for (int i = 0; i < n; i++){
        switch (roman[i]){
        case 'I':
            convertedRoman += 1;
            break;
        case 'V':
            convertedRoman += 5;
            break;
        case 'X':
            convertedRoman += 10;
            break;
        case 'L':
            convertedRoman += 50;
            break;
        case 'C':
            convertedRoman += 100;
            break;
        }
    }

    for (int i = 1; i < n; i++){
        if ((roman[i] == 'V' || roman[i] == 'X') && roman[i -1] == 'I'){
            convertedRoman -= 1 + 1;
        }

        if ((roman[i] == 'L' || roman[i] == 'C') && roman[i -1] == 'X'){
            convertedRoman -= 10 + 10;
        }
    }

    return convertedRoman;
}


//This code is used to convert ordinary numbers to roman numbers
string int_to_rom(int n){
    string str_roman[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};

    int size = sizeof(str_roman) / sizeof(str_roman[0]);

    string result = "";

    for (int i = 0; i < size; i++){
        while (n - values[i] >= 0){
            result += str_roman[i];
            n -= values[i];
        }
    }

    return result;
}


int main(){

    cout << "Enter the roman number: ";
    cin >> userInput;

    calculatedNumber = roman_to_int(userInput);

    // the calculator code
    while (true){
        cout << "Enter the operator: ";
        cin >> oper;

        cout << "Enter the roman number: ";
        cin >> userInput;


        int numberForCalculation =  roman_to_int(userInput);
        
        check = oper;
        if (check[0] == 'e'){
            break;
        }

        switch(oper) {
            case '+':
                calculatedNumber = calculatedNumber + numberForCalculation;
                break;
            case '-':
                calculatedNumber = calculatedNumber - numberForCalculation;
                break;
            case 'X':
                calculatedNumber = calculatedNumber * numberForCalculation;
                break;
            case '/':
                calculatedNumber = calculatedNumber / numberForCalculation;
                break;
        }
    }
    
    cout << "The calculated roman number is: " << int_to_rom(calculatedNumber) << endl;
    
    return 0;
}