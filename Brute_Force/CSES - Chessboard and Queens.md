```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout << #n << " = " << n << endl
#define MSET(arr, x, n) (memset(arr, x, (n) * sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
#define pb push_back
const int MAX = 2e5 + 20, MOD = 1e9 + 7;
int t = 1, r = 0;
vec<string> brd;
 
bool canPlace(vec<int>& qns, int row, int col) {
    for (int i = 0; i < col; ++i)
        if (qns[i] == row || abs(qns[i] - row) == abs(i - col))
            return false;  
    return true;
}
 
int rec(int col, vec<int>& qns, int msk = 0) {
    if (col == 8) return 1;  
    int r = 0;
    for (int i = 0; i < 8; ++i) {
        if (TEST(msk, i)) continue;  
        if (brd[i][col] == '*') continue;  
        if (canPlace(qns, i, col)) {
            qns[col] = i;  
            r += rec(col + 1, qns, SET(msk, i));  
        }
    }return r;
}
 
void solve() {
    brd.resize(8);
    for (auto& i : brd) cin >> i;
    vec<int> qns(8, -1);  
    cout << rec(0, qns) << endl;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (t--) {
        solve();
    }return 0;
}
