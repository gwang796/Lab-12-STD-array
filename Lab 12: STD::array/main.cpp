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
    
    cout << "1. Number of Days: " << weather.size() << endl;
    cout << "2. First Day: " << weather.front() << endl;
    cout << "3. Last Day: " << weather.back() << endl;
    cout << "4. Empty?: " << weather.empty() << endl;
    cout << "5. Highest Temperature: " << *max_element(weather.begin(),weather.end());
    cout << "6. Lowest Temperature: " << *min_element(weather.begin(),weather.end());
    cout << "7. Sum of temperatures: " << accumulate(weather.begin(),weather.end(),0);
    sort(weather.begin(),weather.end());
    cout << "8. Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " " << endl;
    }
    cout << endl;
    sort(weather.rbegin(),weather.rend());
    cout << "9. Reverse Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " " << endl;
    }
    cout << endl;
    array<int,7> week1;
    fill(week1.begin(), week1.end(), 7);
    cout << "10. Week 1: ";
    for (int value : week1) {
        cout << value << endl;
    }
    cout << endl;
    return 0;
}
