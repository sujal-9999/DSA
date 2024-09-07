#include<bits/stdc++.h>
#include<iostream>
#include <cmath>
#include<algorithm>
#include<string>
using namespace std;
#define ld double
#define ll long long
#include <iomanip>


void solve(int n , int q , string a , string b){
    
    unordered_map<char,ll> map;
    vector<ll> prefix(n+1 , 0);
    ll ans = 0;
    cout<<"prefix : "<<endl;
    for(int i = 0 ; i< n;i++){
        char x = a[i];
        char y = b[i];

        map[x]++;
        if(map[x] > 0)ans++;
        else ans--;

        map[y]--;
        if(map[y] >= 0)ans--;
        else ans++;

        cout<<i+1<<"("<<map[x]<<" "<<map[y]<<" "<<(ans/2)<<")"<<" "<<x<<" "<<y<<endl;
        prefix[i+1] = ans/2  ;
    }
    cout<<endl;

    while(q--){
        int l , r;
        cin>>l>>r;
        ll ans = abs(prefix[r] - prefix[l-1]);
        cout<<ans<<endl;
    }
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n , q;
        string a , b;
        cin>>n>>q;
        cin>>a;
        cin>>b;
        solve(n , q , a , b);
    }
}