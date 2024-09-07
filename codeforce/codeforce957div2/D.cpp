#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#include <iomanip>

void can_cross(vector<char>& river , int m , int k ){
    int n = river.size();
    vector<int> dp(n+1 , 200001);
    dp[n] = 0;
    for(int i = n-1 ; i >= 0 ; i--){
        if(river[i] == 'W'){
            dp[i] = dp[i+1]+1;
        }
        else if(river[i] == 'L'){
            for(int j = min(i+m , n) ; j > i ; j--){
                dp[i] = min(dp[j] , dp[i]);
            }
        }
    }
    for(int i = 0 ;i < m ; i++){
        if(dp[i] <= k){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n , m , k;
        cin>>n>>m>>k;
        vector<char> river(n);
        int i = 0;
        while(n--){
            cin>>river[i++];
        }
        can_cross(river , m , k);
    }
}

