#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#define ll long long
#include <iomanip>

int max_score(string& ans , int n){
    int a(0),b(0),c(0),d(0);
    for(int i = 0 ; i < 4* n ; i++){
        char x = ans[i];
        if(x == 'A')a++;
        else if(x == 'B')b++;
        else if(x == 'C')c++;
        else if(x == 'D')d++;
    }
    return min(n , a) + min(n , b) + min(n , c) + min(n , d);
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string ans;
        cin>>ans;
        cout<<max_score(ans , n)<<endl;
    }
}

