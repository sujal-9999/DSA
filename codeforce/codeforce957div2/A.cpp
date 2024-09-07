#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#include <iomanip>

int kmes(int a , int b , int c){
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    for(int i= 0 ; i< 5 ; i++){
        int temp = pq.top();
        pq.pop();
        pq.push(temp+1);
    }
    int ans =1;
    while(!pq.empty()){
        ans *= pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<kmes(a,b,c)<<endl;
    }
}