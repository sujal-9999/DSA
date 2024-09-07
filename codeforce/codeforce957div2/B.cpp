#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#include <iomanip>

int restore_pie(vector<int>& piece){
    int ans = 0;
    int mx = *max_element(piece.begin() , piece.end());
    for(auto a : piece){
        ans += 2*a-1;
    }
    ans -= 2*mx-1;
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n , k;
        cin>>n>>k;
        vector<int> piece(k);
        int i = 0;
        while(k--){
            cin>>piece[i++];
        }
        cout<<restore_pie(piece)<<endl;
    }
}