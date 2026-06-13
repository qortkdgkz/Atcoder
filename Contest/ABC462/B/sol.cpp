#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std; 
#define pb push_back 
#define ppb pop_back 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vll vector<long long>
#define vi vector<int> 
#define vs vector<string> 
#define vb vector<bool> 
#define vvi vector<vector<int>>
#define pii vector<pair<int, int>>
#define pll vector<pair<long long, long long>> 
#define mii map<int, int> 
#define mll map<long long, long long>
#define msi map<string, int> 
typedef long long ll; 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n; cin >> n; 
    vi a[105]; 
    for (int i=1; i <= n; i++) {
        int b; cin >>b; 
        for (int j = 0; j < b; j++) {
            int c; cin >> c; a[c].pb(i); 
        }
    }
    for (int i= 1; i <= n; i++) {
        cout << a[i].size(); 
        for (int j = 0; j < a[i].size(); j++) {
            cout << " " << a[i][j]; 
        }
        cout << '\n';
    }
    return 0; 
}