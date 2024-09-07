#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

bool comp(pair<int,int>& a , pair<int,int>& b){
    return a.first < b.first;
}

long long max_bouque(vector<int>& petal , int n , long long m){

    unordered_map<int,int> hashmap;

    for(auto a : petal){
        hashmap[a]++;
    }

    vector<pair<int,int>> flowers;
    for(auto pair : hashmap){
        flowers.push_back(pair);
    }
    sort(flowers.begin() , flowers.end() , comp);

    int pair_size = flowers.size();
    long long ans = 0;
    for(int i = 0 ;i < pair_size ; i++){
        long long temp1 = static_cast<long long>(flowers[i].second) * flowers[i].first;
        long long temp2 = 0;
        if(i+1  < pair_size && flowers[i].first + 1 == flowers[i+1].first){
            temp2 = static_cast<long long>(flowers[i + 1].second)* flowers[i+1].first;
        }
        long long final_temp = temp1 + temp2;
        ans = max(ans , final_temp);
    }
    return min(ans , m); 
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n ;
        long long m;
        cin>>n>>m;
        vector<int> petal(n ,0);
        int i = 0;
        while(i < n ){
            cin>>petal[i++];
        }
        cout<<max_bouque(petal , n , m)<<endl;
    }
}
