#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#define ll long long
#include <iomanip>


bool bad_case(int n , int a , int b){
    int output = n*a - b;
    string Output = to_string(output);
    int size1 = Output.size();
    string N = to_string(n);
    int size2 = N.size();
    int size3 = size2*a - b;
    if(size1 != size3 || size1 > 6 ){
        return false;
    }
    string ans ="";
    for(int i = 0 ; i < size3 ; i++){
        ans += N[i%size2];
    }
    if(stoi(ans) == output)return true;
    return false;
}

void novice_mistake(int n){
    vector<pair<int,int>> ans;
    string sn = to_string(n);
    int lenN = sn.length();
    for(int i = 1 ; i <= 10000 ; i++){
        int minB = max(1, lenN * i - 5);
        int maxB = lenN * i;
        for(int j = minB ; j <= maxB ; j++){
            if(bad_case(n , i , j)){
                ans.push_back({i,j});
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto pair : ans){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        novice_mistake(n);
    }
}