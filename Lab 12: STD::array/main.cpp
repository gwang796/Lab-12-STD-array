//
//  main.cpp
//  COMSC-210 | Lab 12: Lab 12: STD::array | Guo An Wang
//  IDE used: Xcode
//  Created by Guo An Wang on 9/19/25.
//  Program use:
//  This program takes in the txt file weather which is the daily temperature
//  high for Lafayette,CA for the next 30 days. It also uses various array member
//  functions to demonstrate knowledge

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;
const int SIZE = 30; //size of data file

int main(int argc, const char * argv[]) {
    system("ls");//checks what files i am accessing. debugging to try and access txt file
    
    array <int,SIZE> weather;
    ifstream inputFile("weather.txt");
    if (!inputFile) {
        cout << "Error: Could not access input file" << endl;
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        inputFile >> weather[i];
    }
    inputFile.close();
    
    cout << "1. Size: " << weather.size() << endl;
    cout << "2. Front: " << weather.front() << endl;
    cout << "3. Back: " << weather.back() << endl;
    cout << "4. Empty?: " << weather.empty() << endl;
    
    return 0;
}
