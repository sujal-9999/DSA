#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

char *arr;

bool isdistinct(int num){
    string N = to_string(num);
    return N[0] != N[1] && N[0]!= N[2] && N[0] != N[3] && N[1] != N[2] && N[1] != N[3] && N[2] != N[3];
}

int main(){
    cout<<sizeof(arr)/sizeof(char)<<endl;
    int num;
    cin>>num;
    num++;
    while(!isdistinct(num)){
        num++;
    }
    cout<<num<<endl;
}