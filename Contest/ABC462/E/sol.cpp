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
    ll a, b,c, d; cin >> a >> b >> c >> d; 
    c = abs(c); d = abs(d); 
    if ((c + d) % 2 == 0) {
        auto e = [&](ll f, ll g) {
            ll h = (f + g) / 2; 
            return (a + b) * h - abs(a - b) * min(f, g); 
        };
        ll i = max(c, d); 
        cout << min(e(c, d), e(i, i)) << '\n'; 
    } else {
        auto e =[&](ll f, ll g) {
             ll h = (f + g - 1) / 2; 
             ll i = 0; 
             if (a > b) i= max(-f, 1LL - g); 
             else i = min(f, g + 1LL); 
             return (a + b) * h + b + (a - b) * i; 
        }; 
        ll j = e(c, d); 
        if (c < d) {
            j = min({j, e(d - 1, d), e(d + 1, d)}); 
        } else if (d <c ){
            j = min({j, e(c, c - 1), e(c, c + 1)}); 
        }
        cout << j << '\n'; 
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
