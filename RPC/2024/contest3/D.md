```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long long
int n, sum = 0;
unordered_map<int, int> facts;



bool isPrime(){

    if(n == 1) return 0;
    if(n == 2) return 1;
    if(!(n&1)) return 0;
    for(int i = 3; i*i <= n; i += 2)
        if(!(n%i)) return 0;
    return 1;

}


bool canWin(){

    if(isPrime()) return 1;
    for(int i = 2; i*i <= n; ++i)
        for(; !(n%i); n /= i) ++facts[i];
    if(n > 1) ++facts[n];
    if(facts.size() > 2) return 0;
    for(auto &p : facts) sum += p.second;
    return (facts.size() == 2)? sum == 2 : sum&1;

}


signed main(){

    scanf("%lld", &n);
    printf((canWin())? "Y\n" : "N\n");
    return 0;

}
