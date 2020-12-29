#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int f[n];
    f[0] = -1;
    int ans=0;

    for(int i=1; i<n; i++){
        int j = i-1;
        
        ans++;
        while((j>=0) && (a[j]>=a[i])){
        	ans ++;
        	j = j-1;	
        } 
        f[i] = j;
    }

    cout << ans << '\n';

    for(int i=0; i<n; i++) cout << f[i] << " "; cout << endl;
}
