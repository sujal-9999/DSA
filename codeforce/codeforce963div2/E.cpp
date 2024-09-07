#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#define ll long long
#include <iomanip>

void f(vector<vector<int>>& matrix , int row){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int j = 0 ; j < m ; j++){
        int val = 0;
        for(int i = 0 ;i < n ;i++){
            val ^= matrix[i][j];
        }
        matrix[row][j] = val;
    }
}
void g(vector<vector<int>>& matrix , int col){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0 ;i < n ;i++){
        int val = 0;
        for(int j = 0 ; j< m ; j++){
            val ^= matrix[i][j];
        }   
        matrix[i][col] = val;
    }
}

ll beauty_cal(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    ll diff = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 1; j < m ; j++){
            diff += abs(matrix[i][j] - matrix[i][j-1]);
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            diff += abs(matrix[i][j] - matrix[i-1][j]);
        }
    }
    return diff;
}

    
bool comp(vector<vector<int>>& a,  vector<vector<int>>& b) {
    return beauty_cal(a) > beauty_cal(b); // Max-heap for smallest beauty_cal first
}


void solver(set<vector<vector<int>>>& st, vector<vector<int>> matrix, ll& ans) {
    if (st.count(matrix)) return;
    st.insert(matrix);
    
    ans = min(ans, beauty_cal(matrix));

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<vector<int>>> pq;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> temp = matrix;
        f(temp, i);
        pq.push_back(temp);
    }
    for (int j = 0; j < m; j++) {
        vector<vector<int>> temp = matrix;
        g(temp, j);
        pq.push_back(temp);
    }
    sort(pq.begin() , pq.end() ,comp );
    while(!pq.empty()){
        solver(st , pq.back() , ans);
        pq.pop_back();
    }
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        set<vector<vector<int>>> st;
        ll ans = LLONG_MAX;
        solver(st, matrix, ans);
        cout << ans << endl;
    }
    return 0;
}
