#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>


int main(){
    string ans;
    string input;
    cin>>input;
    for(int i = 0 ;i < input.size() ; i++){
        if(input[i] == '.'){
            ans += '0';
        }
        if(input[i] == '-'){
            i++;
            if(input[i] =='.')
                ans+= '1';
            else ans += '2';
        }
    }
    cout<<ans<<endl;
}