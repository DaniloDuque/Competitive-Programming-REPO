```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    int i = 1;
    for(;n > 1; i+=k, --n);
    printf("%d\n", i);

  }return 0;

}
