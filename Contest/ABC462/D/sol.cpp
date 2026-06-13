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
int a[1000005]; 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, d; cin >> n >> d; 
    for (int i = 0; i < n; i++) {
        int b, c; cin >> b >> c; 
        if (b<= c - d) {
            a[b]++; a[c - d + 1]--; 
        }
    }
    ll f = 0; int e = 0; 
    for (int i =1; i <= 1000000; i++) {
        e += a[i]; 
        if (e >= 2) {
            f += (ll)e * (e - 1) / 2; 
        }
    }
    cout << f << '\n'; 
    return 0; 
}