```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
typedef ll tf;
typedef ll tc;
const tf INFFLOW = 1e9;
const tc INFCOST = 1e9;
const int MAX = 2e5+20;
int t=1, n, m, s, sink, c, w, u, v;

struct MCF {
    int n;
    vec<tc> prio, pot;
    vec<tf> curflow;
    vec<int> prevedge, prevnode;
    priority_queue<pair<tc, int>, vec<pair<tc, int>>, greater<pair<tc, int>>> q;
    struct edge {
        int to, rev;
        tf f, cap;
        tc cost;
    };
    vec<vec<edge>> g;
    MCF(int n) : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
    void add_edge(int s, int t, tf cap, tc cost) {
        g[s].push_back({t, (int)g[t].size(), 0, cap, cost});
        g[t].push_back({s, (int)g[s].size() - 1, 0, 0, -cost});
    }
    pair<tf, tc> get_flow(int s, int t) {
        tf flow = 0;
        tc flowcost = 0;
        while (true) {
            q.push({0, s});
            fill(ALL(prio), INFCOST);
            prio[s] = 0;
            curflow[s] = INFFLOW;
            while (!q.empty()) {
                auto cur = q.top();
                tc d = cur.first;
                int u = cur.second;
                q.pop();
                if (d != prio[u]) continue;
                for (int i = 0; i < (int)g[u].size(); ++i) {
                    edge &e = g[u][i];
                    int v = e.to;
                    if (e.cap <= e.f) continue;
                    tc nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio) {
                        prio[v] = nprio;
                        q.push({nprio, v});
                        prevnode[v] = u;
                        prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == INFCOST) break;
            for (int i = 0; i < n; ++i) pot[i] += prio[i];
            tf df = min(curflow[t], INFFLOW - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v]) {
                edge &e = g[prevnode[v]][prevedge[v]];
                e.f += df;
                g[v][e.rev].f -= df;
                flowcost += df * e.cost;
            }
        }return {flow, flowcost};
    }
};

void solve(){        
    cin>>n>>m>>s>>sink;
    MCF mcf(n);
    while(m--){
        cin>>u>>v>>c>>w;
        mcf.add_edge(u, v, c, w);
    }
    auto rslt = mcf.get_flow(s, sink);
    cout<<rslt.fst<<' '<<rslt.snd<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
