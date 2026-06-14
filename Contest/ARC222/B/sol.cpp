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
    ll a, b, c; cin >> a >> b >> c; 
    ll d = 0; 
    if (c == 0 && a <= b) d = max(d, a); 
    else if (b >= 1) d = max(d, min(b - 1, a)); 
    if (a == 0 && b <= c) d = max(d, b); 
    else if (c >= 1) d = max(d, min(c -1, b)); 
    if (b == 0 && c <= a) d = max(d, c); 
    else if (a >= 1) d = max(d, min(a - 1, c)); 
    if (c >= 2 && a >= 1 && b >= 3) {
        d = max(d, min(a + c -1, b - 1)); 
    }
    if (a >= 2 && b >= 1 && c >= 3) {
        d = max(d, min(b + a -1, c - 1)); 
    }
    if (b >= 2 && c >= 1 && a >= 3) {
        d = max(d, min(c + b -1, a - 1)); 
    }
    if (a >= 3 && b >= 3 && c >= 3) {
        ll e = min({a + b - 3, b + c - 3, c + a - 3, (a + b + c - 3) / 2}); 
        d = max(d, e); 
    }
    cout << d << '\n'; 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while (t--) {
        s(); 
    }
    return 0; 
}