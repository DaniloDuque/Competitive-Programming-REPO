```cpp
#include <bits/stdc++.h>
using namespace std;

int Ar, Ac, Tr, Tc, maxH, maxW;
vector<vector<int>> image;



//produces an accumulated Matrix
void accumulateImage(){

    for(int i = Tr; i<maxH; ++i)
        for(int j = Tc; j<maxW; ++j) 
            image[i][j] += image[i-1][j] + image[i][j-1] - image[i-1][j-1];

}




//in this function, return 0 means, no point inside the rectangle, so no tile needed, else tile needed
int needsTile(int x, int y, int n, int m){

    if(n > maxH - 2 || m > maxW - 2) return 0;                            //out of bounds, no need for a tile
    if(!x && !y) return image[n][m];                                        //if x = 0 and y = 0, then return the bottom right
    if(!x) return image[n][m] - image[n][y-1];                              //if x = 0, return the difference, between bottom right and bottom left
    if(!y) return image[n][m] - image[x-1][m];                              //if y = 0, return the difference, between bottom right, and top right
    return image[n][m] + image[x-1][y-1] -  image[n][y-1] - image[x-1][m];  //else, normal, accumulated Matrix operation

}




void minTiles(){

    int rslt = 1<<20;

    for(int i = 0; i<Tr; i++){
        for(int j = 0; j<Tc; j++){

            int currMin = 0;
            for(int x=i; x<maxH; x+=Tr)
                for(int y=j; y<maxW; y+=Tc) currMin += min(needsTile(x, y, x + Tr - 1, y + Tc - 1), 1); //chooses the minimum, between using a tile, or not
            rslt = min(rslt, currMin);

        }

    }cout<<rslt<<'\n';


}





int main(){

    ios::sync_with_stdio(false);
    while(cin>>Ar>>Ac>>Tr>>Tc){

        maxH = Ar + (Tr<<1);   //image height + 2 times the height of the tile
        maxW = Ac + (Tc<<1);   //image width + 2 times the width of the tile
        //this ensures the answer is minimum because, we can choose a tile outside of the image
        image.assign(maxH, vector<int>(maxW, 0));
        
        for(int i = Tr; i<maxH-Tr; i++)

            for(int j = Tc; j<maxW-Tc; j++){

                char curr;
                cin>>curr;
                image[i][j] += (curr == 'X');

            }
            
        accumulateImage();
        minTiles();

    }return 0;


}
