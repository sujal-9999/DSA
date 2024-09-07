#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

int maxRoot(vector<vector<int>>& graph , vector<int>& values,int node){
    int lowest = INT_MAX;
    for(auto adj : graph[node]){
        int val = maxRoot(graph , values ,  adj);
        lowest = min(lowest ,val );
    }
    if(lowest == INT_MAX ) return values[node];
    if(node == 0) return values[node]+lowest;
    if(lowest <= values[node])return lowest;
    return (values[node]+lowest)/2;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> values(n);
        for(auto i = 0; i < n ;i++){
            cin>>values[i];
        }
        vector<vector<int>> graph(n);
        for(int i = 1 ; i < n; i++){
            int temp;
            cin>>temp;
            graph[temp-1].push_back(i);
        }
        cout<<maxRoot(graph , values, 0)<<endl;

    }
}


