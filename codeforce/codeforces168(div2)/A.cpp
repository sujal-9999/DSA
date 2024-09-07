#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>


string helper(string& password){
    int n = password.size();
    bool flag = true;
    for(int i = 0 ;i < n ; i++){
        if(i > 0 && password[i] == password[i-1]){
            flag = false;
            password.insert(i , 1 , (password[i] != 'z')?(password[i]+1):'a');
            break;
        }
    }
    if(flag)
        password.insert(n , 1 , (password[n-1] != 'z')?(password[n-1]+1):'a');
    return password;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string password;
        cin>>password;
        cout<<helper(password)<<endl;
    }
}