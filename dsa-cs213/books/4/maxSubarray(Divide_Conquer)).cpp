#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;


int maxCrossSum(int *a, int s, int e, int m){
    int sum = 0;
    int leftSum = INT_MIN;

    for(int i=m; i>=s; i--){
        sum += a[i];
        if(sum > leftSum){
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;

    for(int i=m+1; i<=e; i++){
        sum += a[i];
        if(sum > rightSum){
            rightSum = sum;
        }
    }

    return max( max(leftSum, rightSum), rightSum+leftSum);
}

int maxsum(int *a, int s, int e){
    if(s==e)
        return a[s];

    int m = (s+e)/2;

    return max(
        max(
            maxsum(a, s, m),
            maxsum(a, m+1, e)
        ),
        maxCrossSum(a, s, e, m)
    );
}

int solve(){
    int n;
    cin >> n;

    int a[n];
    fori(i, n) cin >> a[i];

    return maxsum(a, 0, n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
        cout << solve() << endl;
}