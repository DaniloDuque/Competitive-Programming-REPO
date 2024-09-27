```cpp
#define SET(msk, i) ((msk)|(1<<(i)))
#define TEST(msk, i) ((msk)&(1<<(i)))

class Solution {
public:
    int partitionString(string s) {
        int rslt = 1, msk = 0;
        for(char &c : s){
            if(TEST(msk, c-'a')) rslt++, msk^=msk;
            msk = SET(msk, c-'a');
        }return rslt;
    }
};
