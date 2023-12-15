```cpp
#define vi vector<int>
#define vvi vector<vi>



vi TopSort(vvi &graph){

    vi in_deg(graph.size(), 0), topSort; queue<int> queue;
    for(int i = 0; i<graph.size(); i++)
        for(int nxt: graph[i])
            in_deg[nxt]++;
    
    for(int i = 0; i<graph.size(); ++i)

        if(!in_deg[i]) queue.push(i);  //pushes vertices with 0 incidence degree

    while(!queue.empty()){

        int curr = queue.front(); queue.pop();
        topSort.insert(topSort.begin(), curr);
        for(int nxt: graph[curr]){
            in_deg[nxt]--;
            if(!in_deg[nxt]) queue.push(nxt);

        }

    }if(topSort.size() == graph.size()) return topSort; //graph is a DAG
    return {};

}




class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vvi graph(numCourses);
        for(vi duo: prerequisites){

            graph[duo[0]].push_back(duo[1]);

        }

        return TopSort(graph);

    }
};
