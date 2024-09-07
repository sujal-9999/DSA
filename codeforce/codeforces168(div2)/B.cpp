#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ld long double
#include <iomanip>

void dfs(vector<vector<char>>& graph, int i , int j){
    int n = graph[0].size();
    if(i < 0 || i>= 2 || j< 0 || j >= n || graph[i][j] == 'x')return;
    graph[i][j] = 'x';
    dfs(graph , i+1 , j);
    dfs(graph , i-1 , j);
    dfs(graph, i , j+1);
    dfs(graph , i , j-1);
}

int number_of_region(string& a , string& b){
    int n = a.size();
    vector<vector<char>> graph(2 , vector<char>(n,'.'));
    for(int i = 0 ; i< n ; i++){
        graph[0][i] = a[i];
        graph[1][i] = b[i];
    }
    int ans = 0;
    for(int i = 0 ;i < 2 ; i++){
        for(int j = 0 ; j < n ; j++){
            if(graph[i][j] == '.'){
                dfs(graph , i ,j);
                ans++;
            }
        }
    }
    return ans;
}

int split_3(string& a , string& b){
    if(number_of_region(a,b) == 0)return 0;
    int n = a.size();
    vector<vector<bool>> graph(2 , vector<bool>(n,false));
    for(int i = 0 ; i< n ; i++){
        graph[0][i] = (a[i] =='x');
        graph[1][i] = (b[i] =='x');
    }
    int ans = 0;
    for(int i = 1 ; i < n-1 ; i++){
        if(graph[0][i-1] == false && graph[1][i-1] == true && graph[0][i+1] == false && graph[1][i+1] == true){
            if(graph[0][i] == false && graph[1][i] == false)
                ans++;
        }
        if(graph[0][i-1] == true && graph[1][i-1] == false && graph[0][i+1] == true && graph[1][i+1] == false){
            if(graph[0][i] == false && graph[1][i] == false)
                ans++;
        }
    }
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string a, b;
        cin>>a;
        cin>>b;
        cout<<split_3(a,b)<<endl;
    }
}