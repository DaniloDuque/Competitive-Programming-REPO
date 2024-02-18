'''cpp
#include <bits/stdc++.h>
using namespace std;


#define int long
int t, p, letters[26];
string s;


signed main() {

    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){

        memset(letters, 0, sizeof(letters));
        cin>>s>>p;
        
        int sum = 0;
        for(char &c: s) letters[c-'a']++;
        for(int i = 0; i<26; i++) sum += (i+1)*letters[i];        

        for(int i = 25; i>=0 && sum > p; --i)

            while(letters[i] > 0 && sum > p) {
            	sum -= i+1;
            	--letters[i];
            }  

        for(char &c: s) if(letters[c-'a'] > 0) {
        	cout<<c;
        	--letters[c - 'a'];
        }
        cout<<'\n';

    }return 0;

}
