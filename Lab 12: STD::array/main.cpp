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
    array <int,SIZE> weather; //declaring STD::array weather with fixed SIZE, and data type int
    ifstream inputFile("weather.txt"); //accessing external data file with 30 elements
    if (!inputFile) { //checks if weather.txt is accessible
        cout << "Error: Could not access input file" << endl;
        return 1;//exit program with error code
    }
    
    //copies values from weather.txt to STD::array weather
    //also checks to make sure there is enough elements to weather.txt
    //or else returns an error
    for (int i = 0; i < SIZE; i++) {
        if(!(inputFile >> weather[i])){
            cout << "Not enough numeric values in data file (needed " << SIZE << " values" << endl;
            return 1;
        }
    }
    inputFile.close(); //close input file
    
    cout << "1. Number of Days: " << weather.size() << endl; //print size of weather container
    cout << "\n2. First Day: " << weather.front() << endl; //print first value of container
    cout << "\n3. Last Day: " << weather.back() << endl; //prints last value of container
    cout << "\n4. Empty?: ";
    //checks if container is empty
    if (weather.empty()==0) {
        cout << "False" << endl;
    } else {
        cout << "True" << endl;
    }
    cout << "\n5. Highest Temperature: " << *max_element(weather.begin(),weather.end()) << endl; //finding max
    cout << "\n6. Lowest Temperature: " << *min_element(weather.begin(),weather.end()) << endl; //min
    cout << "\n7. Sum of temperatures: " << accumulate(weather.begin(),weather.end(),0) << endl; //sum
    array<int,7> week1; //declaring new STD::array week1, for first week temperature highs
    //copies values from STD::array weather into STD::array week1
    for (int i = 0; i < 7; i++) {
        week1[i] = weather[i];
    }
    //prints each day temperature high
    cout << "\n8. Week 1: " << endl;
    int day = 1; //integer value for day
    for (int value : week1) {
        cout << "Day " << (day) << ": " << value << endl;
        day++;
    }
    //sort weather from least to greatest
    sort(weather.begin(),weather.end());
    cout << "\n9. Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " ";
    }
    cout << endl;
    //sort weather from biggest to smallest
    sort(weather.rbegin(),weather.rend());
    cout << "\n10. Reverse Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
