#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

bool canItBeLostNumber(string& a){
    if(a.size() < 3)return false;
    if(a[0]!= '1' || a[1]!= '0')return false;
    int exp = stoi(a.substr(2 , a.size()-2));
    if(exp < 2)return false;
    if(to_string(exp)!= a.substr(2 , a.size()-1))return false;
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        if(canItBeLostNumber(a))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}