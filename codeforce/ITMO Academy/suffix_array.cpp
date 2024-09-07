#include <bits/stdc++.h>
using namespace std;

void radix_sort( vector<pair<pair<int, int>, int>>& a){
    int n = a.size();
    
    {
        vector<int>cnt(n);
        for(auto x : a){
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i = 1 ; i < n; i++){
            pos[i] = pos[i-1] + cnt[i-1]; 
        }
        for(auto x : a){
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    
    {
        vector<int>cnt(n);
        for(auto x : a){
            cnt[x.first.first]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i = 1 ; i < n; i++){
            pos[i] = pos[i-1] + cnt[i-1]; 
        }
        for(auto x : a){
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    

}

vector<int> suffix_sort(string& s){
    s += "$";
    int n = s.size();
    vector<int> p(n), c(s.begin(),s.end());
    
    {
        //k =0
        vector<pair<char,int>> a(n);
        for(int i = 0 ;i < n; i++) a[i]= {s[i] , i};
        sort(a.begin() , a.end());  

        for(int i = 0 ;i < n ; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n){

        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);

        for (int i = 0; i < n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }

    return p;
}

void print_vector(vector<int>& ans){
    for(auto a : ans)
        cout<<a<<" ";
}

bool substring_search(vector<int>& ans , string& x ,string& s){
    int n = s.size();
    int max = n-1;
    int min = 0;
    int p = x.size();
    while( min <= max){
        int mid = min + (max-min)/2;
        int m = ans[mid];
        //cout<<m<<" "<<s.substr(m,p)<<endl;
        if(s.substr(m, p) == x) return true;
        else if( s.substr(m , p)  > x) max = mid-1;
        else min = mid+1;
    }
    return false;
}

int substring_count(const string &s, const vector<int> &suffix, const string &t) {
    int lo = 0, hi = suffix.size();
    while (lo < hi) {
        auto mid = lo + (hi - lo) / 2;
        // substr will take care of edge cases when the required sub string extends
        // past the end
        string sub = s.substr(suffix[mid], t.size());
        if (sub < t) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (lo >= suffix.size() || s.substr(suffix[lo], t.size()) != t) {
        return 0;
    }
    int lo2 = lo, hi2 = suffix.size();
    while (lo2 < hi2) {
        auto mid = lo2 + (hi2 - lo2) / 2;
        string sub = s.substr(suffix[mid], t.size());
        if (sub <= t) {
            lo2 = mid + 1;
        } else {
            hi2 = mid;
        }
    }
    return hi2 - lo;
}

int main()
{   
    string s;
    int tt;
    cin>>s;
    cin>>tt;
    vector<int> ans = suffix_sort(s);
    while(tt--){
        string x;
        cin>>x;
        cout<<substring_count(s , ans , x)<<endl;
    }
}