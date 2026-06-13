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
const int M = 998244353; 
ll a[200005], b[200005]; 
ll p(ll c, ll d) {
    ll e =1; 
    while (d) {
        if (d & 1) e = e * c % M; 
        c = c *c % M; 
        d >>= 1; 
    }
    return e; 
}
void f (vll &c, bool d) {
    int e = c.size(); 
    for (int i = 1, j = 0; i < e; i++ ){
        int k = e >> 1; 
        for (;j & k; k >>= 1) j ^= k; 
        j ^= k; 
        if (i < j) swap(c[i], c[j]); 
    }
    for (int i =2; i <= e; i <<= 1) {
        ll g = p(3, (M - 1) / i); 
        if (d) {
            g =p(g, M - 2); 
        }
        for (int j = 0; j < e; j += i) {
            ll h = 1; 
            for (int k = 0; k < i / 2; k++) {
                ll u = c[j + k], v = h * c[j + k + i / 2] % M; 
                c[j + k] = (u + v < M ? u + v : u + v - M); 
                c[j + k + i / 2] = (u - v >= 0 ? u - v : u -v + M); 
                h = h * g % M; 
            }
        }
    }
    if (d) {
        ll g = p(e, M - 2); 
        for (int i = 0; i < e; i++) c[i] = c[i] * g % M; 
    }
}
vll m(vll c, vll d) {
    if (c.empty() || d.empty()) return {}; 
    int e=  1, g = c.size() + d.size() - 1; 
    while (e < g) e <<= 1; 
    c.resize(e); d.resize(e); 
    f(c, 0); f(d, 0); 
    for (int i = 0; i < e; i++) c[i] = c[i] * d[i] % M; 
    f(c, 1); 
    c.resize(g); 
    return c; 
}
void s() {
    a[0] =1; b[0] = 1; 
    for (int i= 1; i < 200005; i++) {
        a[i] = a[i - 1] * i % M; 
    }
    b[200004] = p(a[200004], M - 2); 
    for (int i = 200003; i >= 1; i--) b[i] = b[i + 1] * (i + 1) % M; 
    int n; cin >> n; 
    vi c(n + 1, 0), d(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        int e; cin >> e; 
        c[e]++; 
    }
    for (int i= 0; i < n; i++) {
        int e; cin >> e; 
        d[e]++; 
    }
    auto o = [](const vll& x, const vll& y) {
        return x.size() > y.size(); 
    }; 
    priority_queue<vll, vector<vll>, decltype(o) > q(o); 
    q.push({1}); 
    for (int i = 1; i <= n; i++) {
        if (!c[i] || !d[i]) continue;
        int e = min(c[i], d[i]); 
        vll g(e + 1); 
        for (int j = 0; j <= e; j++) {
            ll u = a[c[i]] * b[j] % M * b[c[i] - j] % M, v = a[d[i]] * b[j] % M * b[d[i] - j] % M;
            g[j] = u * v % M * a[j] % M;  
        }
        q.push(g); 
    }
    while (q.size() > 1) {
    vll x = q.top(); q.pop(); 
    vll y = q.top(); q.pop(); 
    q.push(m(x, y)); 
    }
    vll x = q.top(); 
    ll z = 0; 
    for (int i = 0; i < x.size(); i++) {
        ll w = x[i] * a[n - i] % M; 
        if (i % 2) z = (z - w + M) % M; 
        else z = (z + w) % M; 
    }
    z = z * p(a[n], M - 2) % M; 
    cout << z << '\n'; 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    s(); 
    return 0; 
}