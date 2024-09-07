#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

int diagonal_occupied(int n , int k){
    int diagonal = n;
    int it = 1;
    int ans = 0;
    while(k > 0){
        k = k - diagonal;
        it--;
        if(it == 0){
            diagonal--;
            it = 2;
        }
        ans++;
    }
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n , k;
        cin>>n>>k;
        cout<<diagonal_occupied(n , k)<<endl;
    }
}