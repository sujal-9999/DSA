#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

bool rulesFollowed(vector<int>& order){
    int n = order.size();
    vector<bool> isOccupied(n+1);
    isOccupied[order[0]] = true;
    for(int i = 1 ; i < n ;i++){
        int nextSeat = order[i];
        if(nextSeat == 0 || nextSeat == n){
            if(nextSeat -1 < 1 && isOccupied[nextSeat +1] == false)return false;
            if(nextSeat + 1 > n && isOccupied[nextSeat -1] == false)return  false;
        }
        else{
            if(!isOccupied[nextSeat-1] && !isOccupied[nextSeat+1])return false;
        }
        isOccupied[nextSeat] = true;
    }
    return true;
}


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> insertOrder(n);
        for(int i = 0 ;i < n ;i++){
            cin>>insertOrder[i];
        }
        if(rulesFollowed(insertOrder))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}