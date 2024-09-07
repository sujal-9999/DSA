#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

int main(){
    int n;
    cin>>n;
    int a(0),b(0),c(0);
    while(n--){
        int x,y,z;
        cin>>x>>y>>z;
        a+=x;
        b+=y;
        c+=z;
    }
    if(a==0 && b==0 && c==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}