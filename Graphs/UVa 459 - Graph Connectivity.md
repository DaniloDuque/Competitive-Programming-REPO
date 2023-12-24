```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> unionFind;
int n, dsCount;
bool blank = false;
char s[3];






int find(int a){

    while(unionFind[a] != a) a = unionFind[a];
    return a;

}


void Union(int a, int b){

    if(a != b){

        unionFind[a] = b;
        dsCount--;

    }

}



int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    cin.ignore(); 
    
    while (n--) {

        char k;
        cin >> k;
        cin.ignore();

        dsCount = k - 'A' + 1;
        unionFind.assign(dsCount, 0);
        iota(unionFind.begin(), unionFind.end(), 0);

        while (cin.getline(s, sizeof(s)) && strlen(s) > 1) Union(find(s[0] - 'A'), find(s[1] - 'A'));

        if(blank) cout<<'\n';
        blank = true;
        cout << dsCount << '\n';


    }return 0;
    

}
