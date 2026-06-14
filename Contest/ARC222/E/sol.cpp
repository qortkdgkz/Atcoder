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
void w(vll& a) {
    int n = a.size(); 
    for (int l = 1; l < n; l <<= 1) {
        for (int i = 0; i < n; i += 2 * l) {
            for (int j = 0; j < l; j++) {
                ll u = a[i + j]; 
                ll v = a[i + l + j]; 
                a[i + j] = u + v; a[i + l + j] = u - v; 
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, m; cin >> n >> m; 
    int s = 1 << m; 
    vi c(s, 0); 
    for (int i = 0; i < n; i++) {
        int x; cin >>x; c[x]++; 
    }
    int t = 300; 
    vll f(s, 0); 
    for (int k = 1; k <= t; k++) {
        vll a(s, 0); 
        bool y =false; 
        for (int v = 0; v < s; v++) {
            if (c[v] >= k) {
                a[v] = 1; 
                y = true; 
            }
        }
        if (!y) break; 
        w(a) ; 
        for (int i = 0; i < s; i++) f[i] += a[i] * a[i]; 
    }
    w(f); 
    for (int i = 0; i < s; i++) f[i] /= s;
    vll b(s, 0); 
    for (int i = 1; i < s; i++) {
        b[i] = f[i] / 2; 
    } 
    vi h, d;
    for (int i = 0; i < s; i++) {
        if (c[i] > t) {
            h.pb(i); 
            d.pb(c[i]); 
        }
    }
    int  l = h.size(); 
    for (int i = 0; i < l; i++) {
        int u = h[i], q = d[i]; 
        for (int j = i + 1; j < l; j++) {
            b[u ^ h[j]] += min(q, d[j]) - t;
        }
    }
    b[0] = 0; 
    for (int i = 0; i < s; i++) b[0] += c[i] / 2; 
    ll r = 0, p = 1; 
    for (int i = 0; i < s; i++) {
        r = (r + (b[i] % 998244353) * p) % 998244353;
        p = (p * 10) % 998244353;
    }
    cout << r << '\n'; 
    return 0; 
}