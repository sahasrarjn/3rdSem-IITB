#include<bits/stdc++.h>
#include<unordered_map>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n];
    unordered_map <ll, ll> cnt;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll maxCnt=0, max=-1;
    for(auto  it=cnt.begin(); it!=cnt.end(); it++){
        if(maxCnt < it->second){
            max = it->first;
            maxCnt = it->second;
        }
    }

    if(2*maxCnt-1 <= n) cout << 2*maxCnt-1 << endl;
    else cout << n << endl;
    
}
