#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

#define MOD 1000000007
double dmod(double x, double y) {
    return x - (int)(x/y) * y;
}
int nCr(int n, int r) {
    // If r is greater than n, return 0
    if (r > n) return 0;
    // If r is 0 or equal to n, return 1
    if (r == 0 || n == r) return 1;
    // Initialize the logarithmic sum to 0
    double res = 0;
    // Calculate the logarithmic sum of the numerator and denominator using loop
    for (int i = 0; i < r; i++) {
        // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
        res += log(n-i) - log(i+1);
    }
    res = dmod(res , 1e9+7);
    // Convert logarithmic sum back to a normal number
    return (int)round(exp(res));
}

int solver(int n , int cnt , int k){
    int mid = (k+1)/2;
    long long ans = 0;
    for(int i = mid ; i <= min(cnt , k) ; i++){
        ans = (ans + nCr(n-cnt,k-i)*nCr(cnt,i))%MOD;
    }
    return static_cast<int>(ans);
}

int main(){
    
    int tt;
    cin>>tt;
    while(tt--){
        int n, k;
        cin>>n>>k;
        int ones(0);
        for(int i = 0 ;i < n ;i++){
            int a;
            cin>>a;
            if(a==1)ones++;
        }
        cout<<solver(n , ones , k)<<endl;

    }
}