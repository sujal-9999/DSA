#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

//s = text , t = pattern
void pattern_match(string& s , string& t){
    int n = s.size();
    int m = t.size();
    int i(0) , j(0);
    while(i < n && j < m){
        if(s[i] == t[j]){
            j++;
        }
        else if(s[i]== '?'){
            s[i] = t[j];
            j++;
        }
        i++;
    }
    if(j != m)s = "";
    else{
        while(i< n){
            if(s[i] == '?')s[i] = 'x';
            i++;
        }
    }
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string s,t;
        cin>>s;
        cin>>t;
        pattern_match(s , t);
        if(s == "")cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
    }
}