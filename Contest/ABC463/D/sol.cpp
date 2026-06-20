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
    int n, k; cin >> n >> k; 
    pii a(n); 
    for (int i= 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first; 
    }
    sort(all(a)); 
    int b = 1, c = 1e9, d = -1; 
    while (b <= c) {
        int e = b + (c - b) / 2, f = 0, g = 0; 
        for (int i = 0; i < n; ++i) {
            if (f == 0 || a[i].second >= g + e) {
                f++; g = a[i].first; 
            }
        }
        if (f >= k) {
            d = e; b = e + 1; 
        } else {
            c = e - 1; 
        }
    }
    cout << d << '\n'; 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    s(); 
    return 0; 
}