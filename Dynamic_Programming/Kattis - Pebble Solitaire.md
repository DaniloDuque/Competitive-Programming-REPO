```cpp
#include <bits/stdc++.h>
using namespace std;

int n, msk, auxMSK;
char x;
int dp[1<<12];

int SET(int msk, int i){return msk|(1<<i);}
int CLEAR(int msk, int i){return msk^(1<<i);}
bool TEST(int msk, int i){return msk&(1<<i);}




int countBits(int msk){

    int c = 0;
    while(msk){

        c+= msk&1;
        msk >>= 1;

    }return c;

}



int minPebbles(int msk){

    if(!msk | dp[msk]) return dp[msk];

    if(msk == (msk&-msk)) return 1;

    int min = 13;

    for(int i = 0; i<10; i++){

        if(TEST(msk, i) && TEST(msk, i+1) && !TEST(msk, i+2)){
            
            auxMSK = msk;
            auxMSK = CLEAR(auxMSK, i);
            auxMSK = CLEAR(auxMSK, i+1);
            auxMSK = SET(auxMSK, i+2);
            min = std::min(min, minPebbles(auxMSK));

        }

    }

    for(int i = 11; i>1; i--){

        if(TEST(msk, i) && TEST(msk, i-1) && !TEST(msk, i-2)){

            auxMSK = msk;
            auxMSK = CLEAR(auxMSK, i);
            auxMSK = CLEAR(auxMSK, i-1);
            auxMSK = SET(auxMSK, i-2);
            min = std::min(min, minPebbles(auxMSK));

        }

    }return dp[msk] = std::min(min, countBits(msk));


}



int main(){

    cin>>n;
    while(n--){

        msk = 0;
        for(int i = 0; i<12; i++){

            cin>>x;
            if(x == 'o') msk = SET(msk, i);

        }
        cout<<minPebbles(msk)<<endl;


    }return 0;

}
