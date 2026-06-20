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
    int a; cin >> a; 
    vi b(a), c(a); 
    for (int i = 0; i < a; ++i) {
        cin >> b[i] >> c[i]; 
    }
    vi d(a); 
    int e = 0; 
    for (int i = a - 1; i >= 0; --i) {
        e = max(e, b[i]); 
        d[i] = e; 
    }
    int f; cin >> f; 
    while (f--) {
        int g; cin >> g; 
        int h = upper_bound(all(c), g) - c.begin(); 
        cout << d[h] << '\n'; 
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    s(); 
    return 0; 
}