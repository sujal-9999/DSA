#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>
#include<cmath>

char student[50];

void reorganize(int n , int t){
    char student_temp[50];
    for(int i = 0 ; i < n ;i++)student_temp[i] = student[i];
    while(t--){
        for(int i = 1 ; i < n ;i++){
            if(student[i] == 'G' && student[i-1] == 'B')
                swap(student_temp[i] , student_temp[i-1]);
        }
        for(int i = 0 ; i < n ;i++)student[i] = student_temp[i];
    }
    for(int i = 0; i < n ; i++){
        cout<<student_temp[i];
    }
    cout<<endl;
}

int main(){
    int n,t;
    cin>>n>>t;
    for(int i = 0; i < n ;i++){
        cin>>student[i];
    }
    reorganize(n , t);
}
