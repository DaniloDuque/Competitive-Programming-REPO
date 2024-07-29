```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int p = 998244353;

int t, n, pairs, zeros;
string s;

int prod(int i, int j) {
    int f = 1;
    for(; i <= j; ++i) f = (f * i) % p;
    return f;
}

int mod_pow(int b, int e) {
    if (e == 0) return 1;
    if (e % 2 == 1) return (b * mod_pow((b * b) % p, e / 2)) % p;
    return mod_pow((b * b) % p, e / 2) % p;
}

int mod_inverse(int i) {
    return mod_pow(i, p - 2);
}

int comb(int n, int k) {
    if (k > n) return 0;
    int numerator = prod(n - k + 1, n);
    int denominator = prod(1, k);
    return (numerator * mod_inverse(denominator)) % p;
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        zeros = 0;
        pairs = 0;
        int sum = 0;

        for (char i : s) zeros += (i == '0');
        for (char i : s) 
            if (i == '1') sum++;
            else {
                pairs += sum / 2;
                sum = 0;
            }
        printf("%lld\n", comb(pairs + zeros + (sum>>1), pairs + (sum>>1)));
    }
    return 0;
}
