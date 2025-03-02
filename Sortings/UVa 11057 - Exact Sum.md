```cpp
#include <bits/stdc++.h>
using namespace std;

int s, n;
vector<int> books;


pair<int, int> twoSum(){

    int i = 0, j = s-1;
    pair<int, int> result;
    while(i <= j){

        if(books[i] + books[j] == n) result = {books[i], books[j]};
        (books[i] + books[j] > n)? j--: i++;

    }return result;

}


int main(){

    while(cin>>s){

        books.assign(s, 0);
        for(int i = 0; i<s; i++) cin>>books[i];
        cin>>n;
        sort(books.begin(), books.end());
        pair<int, int> result = twoSum();
        cout<<"Peter should buy books whose prices are "<<result.first<<" and "<<result.second<<".\n\n";

    }return 0;

}
