```cpp
#include <bits/stdc++.h>
using namespace std;

string n;

bool isMagical() {
    
    for (char c : n) if (c != '4' && c != '1') return false;

    if(n[0] == '4') return false;

    if(n.find("444") != string::npos) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    cout << ((isMagical()) ? "YES\n" : "NO\n");
    return 0;
}
