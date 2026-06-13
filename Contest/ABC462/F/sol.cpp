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
    string a; int b; cin >> a >> b; 
    int n = a.length(), c[150][3]; 
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 1e9; 
        }
    }
    c[75][0] = 0; 
    for (int i = 0; i < n; i++) {
        int d[150][3]; 
        for (int j = 0; j < 150; j++) {
            for (int k = 0; k < 3; k++) {
                d[j][k] = 1e9; 
            }
        }
        bool e = (a[i] == 'A'), f = (a[i] == 'B'), g= (a[i] == 'C'), h = (!e && !f && !g);
        int m = 0; 
        if (i >= 2  && a[i - 2] == 'A' && a[i - 1] == 'B' && a[i] == 'C') {
            m = 1; 
        } 
        for (int j = 0; j < 150; j++) {
            for (int k = 0; k < 3; k++) {
                if (c[j][k] == 1e9) continue;
                int u = 1, v = e ? 0 : 1, w = j - m; 
                if (w >= 0 && w < 150) {
                    d[w][u] = min(d[w][u], c[j][k] + v); 
                }
                u = (k == 1) ? 2 : 0; 
                v = f ? 0 : 1; 
                w = j - m; 
                if (w >= 0 && w < 150) {
                    d[w][u] = min(d[w][u], c[j][k] + v); 
                }
                u = 0; 
                v = g ? 0 : 1; 
                w = j - m + (k == 2 ? 1 : 0); 
                if (w >= 0 && w < 150) {
                    d[w][u] = min(d[w][u], c[j][k] + v); 
                }
                u = 0; 
                v = h ? 0 : 1; 
                w = j - m ; 
                if (w >= 0 && w < 150) {
                    d[w][u] = min(d[w][u], c[j][k] + v); 
                }
            }
        }
        for (int j = 0; j < 150; j++) {
        for (int k = 0; k < 3; k++) {
            c[j][k] = d[j][k]; 
        }
    }
    }
    int z =min({c[75 + b][0], c[75 + b][1], c[75 + b][2]}); 
    if (z == 1e9) {
        cout << -1 << '\n'; 
    } else {
        cout << z << '\n';
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