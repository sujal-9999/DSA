#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#define int long long
#include <iomanip>
#include<cmath>



int prefix[200010];
char direction[200010];

int maxScore(int n){
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l < r ){
        while(l < n && direction[l] == 'R')l++;
        while(r >=0 && direction[r] == 'L')r--;
        if(l < n && r >= 0 && l < r){
            ans+= prefix[r] - ((l > 0)?prefix[l-1]:0);
            l++;
            r--;
        }
    }
    return ans;
}

int32_t main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        for(int i = 0 ;i < n; i++){
            int val;
            cin>>val;
            prefix[i] = val + ((i > 0)?prefix[i-1]:0);
        }
        for(int i = 0 ;i < n; i++){
            cin>>direction[i];
        }
        cout<<maxScore(n)<<endl;
    }
}