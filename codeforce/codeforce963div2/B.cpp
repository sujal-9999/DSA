#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#define ll long long
#include <iomanip>


void parity_equalizer(priority_queue<ll , vector<ll>, greater<ll>>& even,priority_queue<ll>&odd ){
    int operation = 0;
    while(odd.size() && even.size()){
        ll val1 = odd.top();
        ll val2 = even.top();
        odd.pop();
        even.pop();
        if(val1 < val2){
            odd.push(val1+val2);
            even.push(val2);
        }
        else{
            odd.push(val1);
            odd.push(val1+val2);
        }
        operation++;
    }
    cout<<operation<<endl;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n ;
        cin>>n;
        priority_queue<ll , vector<ll> , greater<ll>>  even ;
        priority_queue<ll>odd;
        while(n--){
            ll val;
            cin>>val;
            if(val%2 == 1)odd.push(val);
            else even.push(val);
        }
        parity_equalizer(even , odd);
    }
}