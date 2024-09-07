#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

int winner(int& a1 , int& a2 , int& b1 , int& b2){
    if(a1 > b1 && a2 > b2)return 1;
    if(a1 > b1 && a2 == b2)return 1;
    if(a1 == b1 && a2 > b2)return 1;
    return 0;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        int ans(0);
        ans += winner(a1,a2,b1,b2);
        ans += winner(a1,a2,b2,b1);
        ans += winner(a2,a1,b1,b2);
        ans += winner(a2,a1,b2,b1);
        cout<<ans<<endl;
    }
}