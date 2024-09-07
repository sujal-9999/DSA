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
        int n,s,m;
        cin>>n>>s>>m;
        int time = 0;
        bool flag = false;
        int l,r;
        while(n--){
            cin>>l>>r;
            if(l-time >= s)flag = true;
            time = r;
        }
        if(m - r >= s)flag = true;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}