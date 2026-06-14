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
const ll INF = 4e18;
ll eg(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll p, q;
    ll d = eg(b, a % b, p, q);
    x = q;
    y = p - q * (a / b);
    return d;
}

ll bsgs(ll x, ll y, ll z) {
    if (z == 1) return 0;
    ll c = 1;
    ll n = sqrt(z) + 1;
    for (int i = 0; i <= n; ++i) {
        if (c == y) return i;
        c = (c * x) % z;
    }
    vector<pair<ll, int>> t;
    t.reserve(n + 1);
    ll d = 1;
    for (int i = 0; i < n; ++i) {
        t.pb({(y * d) % z, i});
        d = (d * x) % z;
    }
    sort(all(t));
    vector<pair<ll, int>> u;
    u.reserve(n + 1);
    for (auto &p : t) {
        if (u.empty() || u.back().first != p.first) {
            u.pb(p);
        }
    }
    ll F = d;
    d = 1;
    for (int i = 1; i <= n + 1; ++i) {
        d = (d * F) % z;
        auto it = lower_bound(all(u), make_pair(d, -1));
        if (it != u.end() && it->first == d) {
            return (ll)i * n - it->second;
        }
    }
    return -1;
}

void s() {
    ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    if (a == d && b == e && c == f) {
        cout << 0 << "\n";
        return;
    }
    ll s = a + b + c;
    if (s != d + e + f || s == 0) {
        cout << -1 << "\n";
        return;
    }
    for (int l = 1; l <= 60; ++l) {
        ll u, v, w;
        if (b + c < a) {
            u = a - b - c;
            v = 2 * b;
            w = 2 * c;
        } else if (a + c < b) {
            u = 2 * a;
            v = b - a - c;
            w = 2 * c;
        } else if (a + b < c) {
            u = 2 * a;
            v = 2 * b;
            w = c - a - b;
        } else {
            u = b + c - a;
            v = a + c - b;
            w = a + b - c;
        }
        a = u; b = v;  c = w;
        if (a == d && b == e && c == f) {
            cout << l << "\n";
            return;
        }
    }
    int z = 0;
    if (a == 0) z++;
    if (b == 0) z++;
    if (c == 0) z++;
    if (z >= 2) {
        cout << -1 << "\n";
        return;
    }
    auto mm = [&](ll x, ll y, ll m) {
        x = (x % m + m) % m;
        y = (y % m + m) % m;
        return (ll)((__int128)x * y % m);
    };
    ll r = INF;
    for (int p = 0; p <= 1; ++p) {
        ll g, h, o;
        if (p == 0) {
            g = d;
            h = e;
            o = f;
        } else {
            g = (s - d % s) % s;
            h = (s - e % s) % s;
            o = (s - f % s) % s;
        }
        ll q = gcd(a, gcd(b, gcd(c, s)));
        if (g % q != 0 || h % q != 0 || o % q != 0) continue;
        ll aa = a / q, bb = b / q, cc = c / q, ss = s / q;
        ll dd = g / q, ee = h / q, ff = o / q;
        ll x, y, xx, yy, xxx, yyy;
        ll g1 = eg(aa, bb, x, y);
        ll g2 = eg(g1, cc, xx, yy);
        eg(g2, ss, xxx, yyy);
        ll X = mm(xxx, xx, ss);
        X = mm(X, x, ss);
        ll Y = mm(xxx, xx, ss);
        Y = mm(Y, y, ss);
        ll Z = mm(xxx, yy, ss);
        ll M = (mm(X, dd, ss) + mm(Y, ee, ss) + mm(Z, ff, ss)) % ss;
        if (mm(M, aa, ss) != dd) continue;
        if (mm(M, bb, ss) != ee) continue;
        if (mm(M, cc, ss) != ff) continue;
        ll K = bsgs(2 % ss, M, ss);
        if (K != -1) {
            r = min(r, K);
        }
    }
    if (r != INF) {
        cout << 60 + r << "\n";
    } else {
        cout << -1 << "\n";
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