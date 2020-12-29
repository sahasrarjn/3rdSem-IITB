/* 
Important points

J(2n+1, 2) = 2J(n+1, 2)-3 if J(n+1, 2) > 1 and 2n+1 otherwise

*/

#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(long long i=0; i<n; i++)
#define prlong long(x) cout << x << endl;

// All this is 0-indexed, later will add 1
long long J(long long n, long long k){
    if(n==1) return 0;
    // Standard case when only one of them is removed and shrinked
    if(n<k)  return (J(n-1, k)+k)%n;    
    
    // Remove all divisible by k and shrink. 'n%k' is to shift 1 back to the current head
    long long ans = J(n-n/k, k)-n%k;

    // If it goes back less than 0, we'll bring it back to +ve. 
    // This if-else statement is to add extra term (deshrink)
    // 0 1 2 3 4 5 6 7 8 9 10
    // 0 1   2 3   4 5   6  7
    // If ans<0, it's sure that it won't cross the gap
    // Otherwise we'll have to add ans/(k-1)
    // Say, for 5, ans = 5 + 5/2 = 7

    if(ans >= 0)     ans += ans/(k-1);
    else if(ans < 0) ans +=n;

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    cout << J(n, k)+1 << '\n';

}


