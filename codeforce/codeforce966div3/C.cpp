#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

bool isisomorphic(string s, string t) {
    int n = s.size();
    unordered_map<char,char> hashmap1;
    unordered_map<char,char> hashmap2;

    for(int i = 0 ; i < n ; i++){
        char a = s[i];
        char b = t[i];
        if(hashmap1[a] == '\0' && hashmap2[b] =='\0'){
            hashmap1[a] = b;
            hashmap2[b] = a;
        }
        else if(!(hashmap1[a] == b && hashmap2[b] == a)){
            return false;
        }
    }
    return true;
}
bool isIsomorphic(vector<int> arr, string t) {
    if(arr.size() != t.size())return false;
    int n = arr.size();
    unordered_map<int,char> hashmap1;
    unordered_map<char,int> hashmap2;

    for(int i = 0 ; i < n ; i++){
        int a = arr[i];
        char b = t[i];
        if(hashmap1[a] == '\0' && hashmap2[b] =='\0'){
            hashmap1[a] = b;
            hashmap2[b] = a;
        }
        else if(!(hashmap1[a] == b && hashmap2[b] == a)){
            return false;
        }
    }
    return true;
}


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0 ; i< n ;i++ ){
            cin>>a[i];
        }
        int m;
        cin>>m;
        while(m--){
            string word;
            cin>>word;
            if(isIsomorphic(a , word))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}