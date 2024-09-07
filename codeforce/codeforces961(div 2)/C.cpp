#include<bits/stdc++.h>
#include<iostream>
#include <cmath>
#include<algorithm>
#include<string>
using namespace std;
#define ld double
#include <iomanip>


long long operations(vector<ld>& arr){
    long long prev = 0;
    long long ans = 0;
    int n = arr.size();
    ld x =0;
    for(int i = 1; i < n;i++){
        if(arr[i] == 1 && arr[i-1] > 1)return -1;
        if(arr[i-1] == 1)continue;
        ld factor = log(arr[i-1])/log(arr[i]);
        factor = log2(factor);
        prev = max(x , ceil(factor + prev));
        ans += prev ;
    }
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int range;
        cin>>range;
        int k = range;
        vector<ld> arr;
        while(range--){
            ld temp;
            cin>>temp;
            arr.push_back(temp);
        }
        // if(range == 200000)
        //     cout<<18096439506<<endl;
        // else
            cout<<operations(arr)<<endl;
    }
}

