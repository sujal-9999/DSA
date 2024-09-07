#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#include <iomanip>

void fgsub(int n ,int m , int k ){
    for(int i = n ; i > m ; i--){
        cout<<i<<" ";
    }
    for(int i = 1 ; i <= m ; i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n ,m , k;
        cin>>n>>m>>k;
        fgsub(n , m , k);
    }
}