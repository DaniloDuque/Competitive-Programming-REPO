```cpp
#include <bits/stdc++.h>
using namespace std;


#define duo pair<int, int>
#define int long
#define f first
#define s second


int n, k;
vector<duo> arr;
priority_queue<duo, vector<duo>, greater<duo>> pq;
priority_queue<int, vector<int>, greater<int>> H;



signed main() {

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k; arr.assign(n, {});
    for(int i = 0; i<n; i++){
        cin>>arr[i].s>>arr[i].f;
        pq.emplace(arr[i].s, arr[i].f);
    }

    sort(arr.begin(), arr.end());
    int rslt = 0;
    for(auto &curr: arr){

        while(!pq.empty() && pq.top().f <= curr.f + k){
            H.push(pq.top().s);
            pq.pop();

        }rslt = max(rslt, (int)H.size());
        while(H.size() && H.top() == curr.f) H.pop();

    }cout<<rslt<<'\n';
    return 0;

}
