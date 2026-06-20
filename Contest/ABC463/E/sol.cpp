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
    int n, m; ll a; cin >> n >> m >> a;
    vector<vector<pair<int, ll>>> b(n + 2); 
    for (int i = 0; i < m; ++i) {
        int c, d; ll e; cin >> c >> d >> e; 
        b[c].pb({d, e}); b[d].pb({c, e}); 
    }  
    vll f(n + 1); 
    for (int i = 1; i <= n; ++i) {
        cin >> f[i]; 
        b[i].pb({n + 1, f[i] + a}); 
        b[n + 1].pb({i, f[i]}); 
    }
    vll g(n + 2, 4e18); 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>h; 
    g[1] = 0; 
    h.push({0, 1}); 
    while (!h.empty()) {
        auto x = h.top(); 
        h.pop(); 
        ll z = x.first; 
        int u = x.second; 
        if (z > g[u]) continue;
        for (auto& y : b[u]) {
            int v = y.first; 
            ll w = y.second; 
            if (g[u] + w < g[v]) {
                g[v] = g[u] + w; 
                h.push({g[v], v}); 
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << g[i] << (i == n ? "" : " "); 
    }
    cout << '\n'; 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    s(); 
    return 0; 
}