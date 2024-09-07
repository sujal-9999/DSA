#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

int arr[5][5];


int main(){
    int x , y;
    for(int i = 0 ;i < 5 ;i++){
        for(int j = 0 ; j < 5 ; j++){
            int a;
            cin>>a;
            if(a == 1){
                x = i;
                y = j;
            }
        }
    }
    cout<<(abs(x-2) + abs(y-2));
}