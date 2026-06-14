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
void s() {
    int n, m; cin >> n >> m; 
    vi a(n + 1, 0); 
    for (int i= 0; i < m; i++) {
        int u, v; cin >> u >> v; 
        a[u] = max(a[u], v); 
    }
    vi b(n + 1, 0); 
    int c = 0; 
    for (int i=1; i <= n; i++) {
        c = max(c, a[i]); 
        b[i] =max(i, c); 
    }
    vvi d(n + 2); 
    priority_queue<int, vi, greater<int>> e; 
    for (int i = 1; i <= n; i++) {
        e.push(i); 
    }
    vi f(n + 1); 
    for (int i=1; i <= n; i++) {
        for (int j : d[i]) e.push(j); 
        f[i] = e.top(); e.pop(); 
        if (b[i] + 1 <= n + 1) d[b[i] + 1].pb(f[i]); 
    }
    for (int i =1; i <= n; i++) {
        cout << f[i] << (i == n ? "": " "); 
    }
    cout << '\n'; 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while (t--) {
        s(); 
    }
    return 0; 
}