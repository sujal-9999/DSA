#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

int grid[3][3];

int main(){
    memset(grid , 1 , sizeof(grid));
    for(int i = 0 ;i < 3 ; i++){
        for(int j = 0 ;j < 3 ; j++){
            int a;
            cin>>a;
            grid[i][j] =(grid[i][j] +  a)%2;
            if(i+1 < 3)grid[i+1][j] =(grid[i+1][j] +  a)%2;
            if(i-1 >=0)grid[i-1][j] =(grid[i-1][j] +  a)%2;
            if(j+1 < 3)grid[i][j+1] =(grid[i][j+1] +  a)%2;
            if(j-1 >= 0)grid[i][j-1] =(grid[i][j-1] +  a)%2;
        }
    }
    for(int i = 0 ;i < 3 ; i++){
        for(int j = 0 ;j < 3 ; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
}