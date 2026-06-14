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
int prev_d[10][256];
int curr_d[10][256];
int c_dp[10][256];
int e_dp[10][256];

int main() {
    ios_base::sync_with_stdio(false);  cin.tie(NULL); 
    
    int n; cin >> n; 
    vll a(n + 1), b(n + 1); 
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    for (int i = 1; i <= n; i++) cin >> b[i]; 
    
    vvi g(n + 1, vi(9, 0)), h(n + 1, vi(9, 0)); 
    for (int i = 1; i <= n; i++) {
        ll val = a[i]; 
        for (int p = 0; p < 9; p++) {
            g[i][p] = val % 10; 
            val /= 10; 
        }
        val = b[i]; 
        for (int p = 0; p < 9; p++) {
            h[i][p] = val % 10; 
            val /= 10; 
        }
    }
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 256; k++) {
            prev_d[j][k] = j; 
        }
    }
    
    vi f(n + 1);
    for (int i = 1; i <= n; i++) {
        int x = i - 8;
        int w = (x <= 0 ? 1 : 2);
        int base_z[256];
        for (int k = 0; k < 256; k++) {
            int z = 0;
            for (int p = 1; p <= 8; p++) {
                int y = x + p;
                if (y > 0 && y <= n) {
                    int choice = (k >> (p - 1)) & 1;
                    z += (choice == 0 ? g[y][p] : h[y][p]);
                }
            }
            base_z[k] = z;
        }
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 256; k++) {
                int bz = j + base_z[k];
                int min_val = 1e9;
                for (int l = 0; l < w; l++) {
                    int z = bz;
                    if (x > 0 && x <= n) {
                        z += (l == 0 ? g[x][0] : h[x][0]);
                    }
                    int q = z / 10;
                    int r = (l) | ((k & 127) << 1);
                    
                    if (prev_d[q][r] < 1e9 - 5) {
                        int rem = z % 10 + prev_d[q][r];
                        if (rem < min_val) min_val = rem;
                    }
                }
                curr_d[j][k] = min_val;
            }
        }
        int k_val = i;
        for (int j = 0; j < 10; j++) {
            for (int m = 0; m < 256; m++) {
                c_dp[j][m] = curr_d[j][m];
            }
        }
        for (int ex = k_val - 7; ex <= k_val; ex++) {
            int ew = (ex <= 0 ? 1 : 2);
            int e_base_z[256];
            for (int m = 0; m < 256; m++) {
                int z = 0;
                for (int p = 1; p <= 8; p++) {
                    int y = ex + p;
                    if (y > 0 && y <= k_val) {
                        int choice = (m >> (p - 1)) & 1;
                        z += (choice == 0 ? g[y][p] : h[y][p]);
                    }
                }
                e_base_z[m] = z;
            }
            for (int j = 0; j < 10; j++) {
                for (int m = 0; m < 256; m++) {
                    int bz = j + e_base_z[m];
                    int min_val = 1e9;
                    for (int l = 0; l < ew; l++) {
                        int z = bz;
                        if (ex > 0 && ex <= k_val) {
                            z += (l == 0 ? g[ex][0] : h[ex][0]);
                        }
                        int q = z / 10;
                        int r = (l) | ((m & 127) << 1);
                        if (c_dp[q][r] < 1e9 - 5) {
                            int rem = z % 10 + c_dp[q][r];
                            if (rem < min_val) min_val = rem;
                        }
                    }
                    e_dp[j][m] = min_val;
                }
            }
            for (int j = 0; j < 10; j++) {
                for (int m = 0; m < 256; m++) {
                    c_dp[j][m] = e_dp[j][m];
                }
            }
        }
        f[k_val] = c_dp[0][0];
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 256; k++) {
                prev_d[j][k] = curr_d[j][k];
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        cout << f[k] << (k == n ? "" : " ");
    }
    cout << '\n'; 
    
    return 0; 
}