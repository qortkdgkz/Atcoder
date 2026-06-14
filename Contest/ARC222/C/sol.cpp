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
const ll LINF = 4e18;

void s() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> b(n, vector<ll>(n, LINF));
    for (int c = 0; c < 2; c++) {
        int d = 0;
        vector<vector<int>> e(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == c) {
                    e[i][j] = d++;
                }
            }
        }
        vector<ll> f(d);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (e[i][j] != -1) {
                    f[e[i][j]] = a[i][j];
                }
            }
        }
        vector<vector<int>> g(d);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (e[i][j] == -1) continue;
                int h = e[i][j];
                if (j > 0) {
                    if (i > 0 && e[i - 1][j - 1] != -1)
                        g[h].pb(e[i - 1][j - 1]);
                    if (i < n - 1 && e[i + 1][j - 1] != -1)
                        g[h].pb(e[i + 1][j - 1]);
                    if (j > 1 && e[i][j - 2] != -1)
                        g[h].pb(e[i][j - 2]);
                }
                if (j < n - 1) {
                    if (i > 0 && e[i - 1][j + 1] != -1)
                        g[h].pb(e[i - 1][j + 1]);
                    if (i < n - 1 && e[i + 1][j + 1] != -1)
                        g[h].pb(e[i + 1][j + 1]);
                    if (j < n - 2 && e[i][j + 2] != -1)
                        g[h].pb(e[i][j + 2]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (e[i][j] == -1) continue;
                int o = e[i][j];
                priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> p;
                vector<ll> q(d, LINF);
                q[o] = f[o];
                p.push({q[o], o});
                while (!p.empty()) {
                    auto [r, s] = p.top();
                    p.pop();
                    if (r > q[s]) continue;
                    for (int t : g[s]) {
                        if (q[t] > q[s] + f[t]) {
                            q[t] = q[s] + f[t];
                            p.push({q[t], t});
                        }
                    }
                }
                ll u = 0;
                for (int k = 0; k < d; k++) {
                    if (q[k] < LINF) {
                        u += f[k];
                    }
                }
                b[i][j] = u;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << (j + 1 < n ? " " : "");
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while (t--) {
        s(); 
    }
    return 0; 
}