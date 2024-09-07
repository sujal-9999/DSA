#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>



int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i = 0 ;i < n ;i++){
            int a, b;
            cin>>a>>b;
            pq.push({min(a,b) , max(a,b)});
        }
        int ans = 0;
        while(!pq.empty() && k > 0){
            pair<int,int> curr = pq.top();
            pq.pop();
            int x = curr.first;
            int y = curr.second;
            ans += x;
            if(y -1 <=  0){
                k -= 2;
                continue;
            }
            y--;
            pq.push({min(x,y) , max(x,y)});
            k--;
        }
        if(pq.empty() && k > 0)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}