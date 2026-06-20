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
ll b = 998244353;
ll c[200005], d[200005];
ll e(ll x, ll y) {
    ll r = 1;
    x %= b;
    while (y) {
        if (y & 1) r = r * x % b;
        x = x * x % b;
        y >>= 1;
    }
    return r;
}
ll f(int x, int y) {
    if (y < 0 || y > x) return 0;
    return c[x] * d[y] % b * d[x - y] % b;
}
int p = 400;
struct Q {
    int n, k, i, t;
    bool operator<(const Q& z) const {
        int x = n / p, y = z.n / p;
        if (x != y) return x < y;
        return (x & 1) ? (k > z.k) : (k < z.k);
    }
};
ll l[200005], m[200005], o[200005], s[200005], y[200005];
vector<Q> g;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    c[0] = 1;
    for (int i = 1; i <= 200000; i++) c[i] = c[i - 1] * i % b;
    d[200000] = e(c[200000], b - 2);
    for (int i = 199999; i >= 0; i--) d[i] = d[i + 1] * (i + 1) % b;
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i];
        if (m[i] >= l[i]) o[i] = m[i] % b;
        else if (m[i] <= -l[i]) o[i] = (-m[i]) % b;
        else {
            int a = (l[i] + m[i]) / 2;
            g.pb({(int)l[i], a, i, 0});
            if (a - 1 >= 0) g.pb({(int)l[i] - 1, a - 1, i, 1});
            else y[i] = 0;
        }
    }
    sort(all(g));
    int u = 0, v = 0;
    ll w = 1;
    ll h = e(2, b - 2);
    for (auto& q : g) {
        while (u < q.n) { w = (2 * w - f(u, v) + b) % b; u++; }
        while (u > q.n) { u--; w = (w + f(u, v)) * h % b; }
        while (v < q.k) { v++; w = (w + f(u, v)) % b; }
        while (v > q.k) { w = (w - f(u, v) + b) % b; v--; }
        if (q.t == 0) s[q.i] = w;
        else y[q.i] = w;
    }
    for (int i = 0; i < n; i++) {
        if (m[i] >= l[i] || m[i] <= -l[i]) continue;
        ll z = l[i] + m[i];
        ll x = (m[i] % b + b) % b;
        ll j = 2 * z % b * s[i] % b;
        ll k = 4 * l[i] % b * y[i] % b;
        ll a = x * e(2, l[i]) % b;
        ll r = (j - k - a) % b;
        r = (r % b + b) % b;
        o[i] = r * e(e(2, l[i]), b - 2) % b;
    }
    for (int i = 0; i < n; i++) cout << o[i] << "\n";
    return 0;
}