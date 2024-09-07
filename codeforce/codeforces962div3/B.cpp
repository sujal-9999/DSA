#include<bits/stdc++.h>
#include<iostream>
#include <cmath>
#include<algorithm>
#include<string>
using namespace std;
#define ld double
#include <iomanip>

void solve(int n , int k ){
    vector<vector<char>>ans(n/k , vector<char>(n/k) );
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char a;
            cin>>a;
            if(i%k == 0 && j%k == 0){
                ans[i/k][j/k] = a;
            }
        }
    }

    for(auto a : ans){
        for(auto b : a){
            cout<<b;
        }
        cout<<endl;
    }
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n, k;
        cin>>n>>k;
        solve(n , k);
    }
}