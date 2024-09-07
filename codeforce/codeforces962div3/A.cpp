#include<bits/stdc++.h>
#include<iostream>
#include <cmath>
#include<algorithm>
#include<string>
using namespace std;
#define ld double
#include <iomanip>


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a;
        cin>>a;
        int ans = 0;
        ans += a/4;
        a = a%4;
        ans += a/2;
        cout<<ans<<endl;
    }
}