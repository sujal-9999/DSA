#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

int helper(double l , double r){
    if(l == r){
        double log_result = log(l) / log(3);
        return static_cast<int>(floor(log_result)) + 1;
    }
    double log_result = log(l) / log(3);
    int ans =  (static_cast<int>(floor(log_result))+1)*2;
    for(int i = l+1 ; i<= r ; i++){
        double log_result = log(i) / log(3);
        ans += static_cast<int>(floor(log_result))+1;
    }
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int l,r;
        cin>>l>>r;
        cout<<helper(l , r)<<endl;
    }
}