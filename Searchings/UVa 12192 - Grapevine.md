```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, q, low, high;
int Map[501][501];




bool valid(int len){

    for(int i = 0; i<n - len; i++){     //for all rows, try a square, with side length = len

        int j = lower_bound(Map[i], Map[i] + m, low) - Map[i];     //binary search the starting point of the square
        if(j < m-len && Map[i][j] >= low && Map[i+len][j+len] <= high) return true;
    
    }return false;

}


int maxSquare(){

    int i = 0, j = min(n-1, m-1), rslt = -1;

    while(i <= j){

        int mid = (i+j)>>1;

        if(valid(mid)){      //if a square with side length = mid, exists, then try bigger squares

            rslt = mid;
            i = mid+1;

        }else j = mid - 1;  //else, try smaller squares

    }return rslt+1;

}



int main(){

    ios::sync_with_stdio(false);
    while(cin>>n>>m && n && m){

        for(int i = 0; i<n; i++) 
            for(int j = 0; j<m; j++) 
                cin>>Map[i][j];

        cin>>q;
        while(q--){

            cin>>low>>high;
            cout<<maxSquare()<<'\n';

        }cout<<"-\n";


    }return 0;

}
