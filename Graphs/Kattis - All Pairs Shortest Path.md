```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo (1<<28|1<<27)
int n, m, q, v1, v2, w;
int graph[150][150];


void FloydWarshall(){

    for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
                		if((graph[i][j] > graph[i][k] + graph[k][j]) && (graph[i][k] < oo) && (graph[k][j] < oo))
				    graph[i][j] = graph[i][k] + graph[k][j];
    
    for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; (graph[i][j] != -oo) && (k < n); ++k)
				if ((graph[k][k] < 0) && (graph[i][k] != oo) && (graph[k][j] != oo))
					graph[i][j] = -oo;
				
}



int main(){

    ios::sync_with_stdio(0);
    while(cin>>n>>m>>q && n){

        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++) 
                graph[i][j] = (i==j)? 0: oo;
            
        while(m--){

            cin>>v1>>v2>>w;
            graph[v1][v2] = min(graph[v1][v2], w);

        }FloydWarshall();

        while(q--){

            cin>>v1>>v2;
            (graph[v1][v2] == oo)? cout<<"Impossible\n" : (graph[v1][v2] == -oo)? cout<<"-Infinity\n" : cout<<graph[v1][v2]<<'\n';

        }cout<<'\n';

    }return 0;

}
