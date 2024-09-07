#include "icpc.h"

#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readAndPrintLongDouble(const string& filename) {
    // Open an input file stream
    ifstream inFile(filename);

    // Check if the file was opened successfully
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading" << endl;
        return;
    }

    // Define a variable to store the long double number
    long double number;

    // Read the long double number from the file
    inFile >> number;

    // Check if the reading was successful
    if (inFile.fail()) {
        cerr << "Error reading number from file" << endl;
        inFile.close();
        return;
    }

    // Close the file
    inFile.close();

    // Print the number with high precision
    cout<<"Correct answer : ";
    cout << fixed << setprecision(13) << number << endl;
}



int main(){

    string filename  = "C:/Users/SUJAL DAS/Desktop/DSA/Carl_solution/icpc2023data/icpc2023data/D-carlsvacation/secret-02.in";
    string ans = "C:/Users/SUJAL DAS/Desktop/DSA/Carl_solution/icpc2023data/icpc2023data/D-carlsvacation/secret-02.ans";
    int n = filename.size();
    for(int i = 1 ; i <= 44 ;i++){
        string num;
        if(i < 10){
            num += '0';
            num += '0'+i;
        }
        else{
            num = to_string(i);
        }
        filename[94] = num[0];
        filename[95] = num[1];
        ans[94] = num[0];
        ans[95] = num[1];
        cout<<"Solution "<<num<<" :    ";
        Solution::execute(filename);
        readAndPrintLongDouble(ans);
        cout<<endl;
    }
}

