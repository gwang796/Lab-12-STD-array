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
    array <int,SIZE> weather; //declaring STD::array weather
    ifstream inputFile("weather.txt"); //accessing external data file with 30 elements
    if (!inputFile) { //
        cout << "Error: Could not access input file" << endl;
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        inputFile >> weather[i];
    }
    inputFile.close();
    
    cout << "1. Number of Days: " << weather.size() << endl;
    cout << "\n2. First Day: " << weather.front() << endl;
    cout << "\n3. Last Day: " << weather.back() << endl;
    cout << "\n4. Empty?: " << weather.empty() << endl;
    cout << "\n5. Highest Temperature: " << *max_element(weather.begin(),weather.end()) << endl;
    cout << "\n6. Lowest Temperature: " << *min_element(weather.begin(),weather.end()) << endl;
    cout << "\n7. Sum of temperatures: " << accumulate(weather.begin(),weather.end(),0) << endl;
    array<int,7> week1;
    for (int i = 0; i < 7; i++) {
        week1[i] = weather[i];
    }
    cout << "\n8. Week 1: " << endl;
    int day = 1;
    for (int value : week1) {
        cout << "Day " << (day) << ": " << value << endl;
        day++;
    }
    sort(weather.begin(),weather.end());
    cout << "\n9. Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " ";
    }
    cout << endl;
    sort(weather.rbegin(),weather.rend());
    cout << "\n10. Reverse Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
