```cpp
#define ll long long
#define pi pair<ll, ll>
#define fst first
#define snd second

int n;
map<pi, vector<pair<pi, ll>>> G;
set<pi> tkn;
priority_queue<pair<ll, pi>> pq;
vector<pi> pnts;

void process(pi &v){
    tkn.insert(v);
    for(auto e : G[v]) if(!tkn.count(e.fst)) pq.push({-e.snd, e.fst});
}

int prim(){
    tkn.clear(); process(pnts[0]);
    int mst = 0;
    while(!pq.empty()){
        int c = pq.top().fst;
        pi v = pq.top().snd; pq.pop();
        if(!tkn.count(v)) mst -= c, process(v);
    }return mst;
}

ll distSQR(pi &a, pi &b){
    return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        pnts.clear(); G.clear(); tkn.clear();
        for(auto &v : points) pnts.push_back({v[0], v[1]});
        n = points.size();
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<n; ++j)
                if(j!=i) G[pnts[i]].push_back({pnts[j], distSQR(pnts[i], pnts[j])});
        return prim();
    }
};
