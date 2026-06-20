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
const int mod = 998244353;
const int gr = 3;
ll ppp(ll a, ll b) {
    ll c = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) c = (c * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return c;
}

namespace NTT {
    vll sum_e, sum_ie;
    void init() {
        if (!sum_e.empty()) return;
        sum_e.resize(30);
        sum_ie.resize(30);
        int cnt = __builtin_ctz(mod - 1);
        ll e = ppp(gr, (mod - 1) >> cnt);
        ll ie = ppp(e, mod - 2);
        vll es(30), ies(30);
        for (int i = cnt; i >= 2; i--) {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e = (e * e) % mod;
            ie = (ie * ie) % mod;
        }
        ll now = 1, now_i = 1;
        for (int i = 0; i <= cnt - 2; i++) {
            sum_e[i] = (es[i] * now) % mod;
            now = (now * ies[i]) % mod;
            sum_ie[i] = (ies[i] * now_i) % mod;
            now_i = (now_i * es[i]) % mod;
        }
    }
    
    void bbb(vll& a) {
        init();
        int n = a.size();
        int h = __builtin_ctz(n);
        for (int ph = 1; ph <= h; ph++) {
            int w = 1 << (ph - 1);
            int p = 1 << (h - ph);
            ll now = 1;
            for (int s = 0; s < w; s++) {
                int offset = s << (h - ph + 1);
                for (int i = 0; i < p; i++) {
                    ll l = a[i + offset];
                    ll r = (a[i + offset + p] * now) % mod;
                    a[i + offset] = (l + r < mod ? l + r : l + r - mod);
                    a[i + offset + p] = (l - r >= 0 ? l - r : l - r + mod);
                }
                now = (now * sum_e[__builtin_ctz(~s)]) % mod;
            }
        }
    }
    
    void bi(vll& a) {
        init();
        int n = a.size();
        int h = __builtin_ctz(n);
        for (int ph = h; ph >= 1; ph--) {
            int w = 1 << (ph - 1);
            int p = 1 << (h - ph);
            ll now = 1;
            for (int s = 0; s < w; s++) {
                int offset = s << (h - ph + 1);
                for (int i = 0; i < p; i++) {
                    ll l = a[i + offset];
                    ll r = a[i + offset + p];
                    a[i + offset] = (l + r < mod ? l + r : l + r - mod);
                    a[i + offset + p] = ((l - r >= 0 ? l - r : l - r + mod) * now) % mod;
                }
                now = (now * sum_ie[__builtin_ctz(~s)]) % mod;
            }
        }
        ll n_inv = ppp(n, mod - 2);
        for (int i = 0; i < n; i++) a[i] = (a[i] * n_inv) % mod;
    }
    
    vll multiply(vll a, vll b) {
        if (a.empty() || b.empty()) return {};
        int sz = a.size() + b.size() - 1;
        int n = 1;
        while (n < sz) n <<= 1;
        a.resize(n, 0);
        b.resize(n, 0);
        bbb(a);
        bbb(b);
        for (int i = 0; i < n; i++) a[i] = (a[i] * b[i]) % mod;
        bi(a);
        a.resize(sz);
        return a;
    }
}

vll ss(int a, int b, const vector<vll>& c) {
    if (a == b) return c[a];
    int d = (a + b) / 2;
    return NTT::multiply(ss(a, d, c), ss(d + 1, b, c));
}
vll pp(vll a, vll b) {
    bool c = true;
    for (ll x : a) if (x != 0) c = false;
    if (c) return vll(a.size(), 0);

    int d = -1, e = -1;
    for (int i = 0; i < 3; ++i) {
        if (b[i] != 0) {
            if (d == -1) d = i;
            e = i;
        }
    }
    if (d == -1) return vll(a.size(), 0);
    vll f(a.size() - d);
    for (int i = 0; i < f.size(); ++i) f[i] = a[i + d];
    vll g(3 - d);
    for (int i = 0; i < g.size(); ++i) g[i] = b[i + d];
    int h = e - d;
    vll p(f.size() - h, 0);
    ll q = ppp(g[0], mod - 2);
    for (int i = 0; i < p.size(); ++i) {
        ll s = f[i];
        if (i - 1 >= 0 && h >= 1) s = (s - p[i - 1] * g[1]) % mod;
        if (i - 2 >= 0 && h >= 2) s = (s - p[i - 2] * g[2]) % mod;
        if (s < 0) s += mod;
        p[i] = s * q % mod;
    }
    return p;
}

void s() {
    int n; cin >> n; 
    vi a(2 * n);
    int b = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        b = max(b, a[i]);
    }
    
    vll c(2 * n + 5);
    c[1] = 1;
    for (int i = 2; i < c.size(); ++i) {
        c[i] = (mod - mod / i) * c[mod % i] % mod;
    }
    
    vll d(2 * n, 0);
    ll e = (mod + 1) / 2; 
    for (int k = b; k <= b + 1; ++k) {
        vector<vll> f(n, vll(3, 0));
        bool g = true;
        for (int i = 0; i < n; ++i) {
            int h = a[2 * i];
            int p = a[2 * i + 1];
            if (h + 1 <= k && p <= k) {
                int q = (h + 1 == k) + (p == k);
                f[i][q] = (f[i][q] + e) % mod;
            }
            if (h <= k && p + 1 <= k) {
                int q = (h == k) + (p + 1 == k);
                f[i][q] = (f[i][q] + e) % mod;
            }
            if (f[i][0] == 0 && f[i][1] == 0 && f[i][2] == 0) {
                g = false;
            }
        }
        if (!g) continue;
        vll r = ss(0, n - 1, f);
        map<vll, int> s_map;
        vector<vll> t;
        vector<pair<ll, ll>> u;
        for (int i = 0; i < n; ++i) {
            if (s_map.find(f[i]) == s_map.end()) {
                int v = t.size();
                s_map[f[i]] = v;
                vll p = pp(r, f[i]);
                t.pb(p);
                ll w = 0, z = 0;
                for (int j = 0; j < p.size(); ++j) {
                    if (p[j] == 0) continue;
                    w = (w + p[j] * c[1 + j]) % mod;
                    z = (z + p[j] * c[2 + j]) % mod;
                }
                u.pb({w, z});
            }
        }
        for (int i = 0; i < 2 * n; ++i) {
            int j = i / 2;
            int v = s_map[f[j]];
            int h = a[2 * j];
            int p = a[2 * j + 1];
            if (h + 1 <= k && p <= k) {
                int q = (h + 1 == k) + (p == k);
                ll w = (q == 1 ? u[v].first : u[v].second);
                if (i == 2 * j && h + 1 == k) {
                    d[i] = (d[i] + e * w) % mod;
                }
                if (i == 2 * j + 1 && p == k) {
                    d[i] = (d[i] + e * w) % mod;
                }
            }
            if (h <= k && p + 1 <= k) {
                int q = (h == k) + (p + 1 == k);
                ll w = (q == 1 ? u[v].first : u[v].second);
                if (i == 2 * j && h == k) {
                    d[i] = (d[i] + e * w) % mod;
                }
                if (i == 2 * j + 1 && p + 1 == k) {
                    d[i] = (d[i] + e * w) % mod;
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        cout << d[i] << (i == 2 * n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    s();
    return 0;
}