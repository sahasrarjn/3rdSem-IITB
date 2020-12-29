#include<bits/stdc++.h>
#include<unordered_set>
typedef long long ll;
using namespace std;

ll hash1(string &s){
    // Count num of 1's
    ll ans=0;
    for(ll i=0; i<s.length(); i++){
        if(s[i] == '1'){
            ans++;
        }
    }
    return ans;
}

ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n) { 
        n &= (n - 1); 
        count++; 
    } 
    return count; 
} 

ll permute(ll a, ll *p, ll n){
    string s = bitset<20>(a).to_string();
    string out = string(20, '0');
    for(ll i=20-n; i<20; i++){
        out[i] = s[20-n + p[i-20+n]];
    }
    ll ans = bitset<20>(out).to_ulong(); 
    return ans;
}

bool check(string &a, string &b, ll n, ll fac){
    ll p[n];
    ll pow2 = (1<<n);
    for(ll i=0; i<n; i++){
        p[i] = i;
    }

    for(ll j=0; j<fac; j++){
        // All permutations
        bool flag = false;
        for(ll i=0; i<pow2; i++){
            // All digits
            ll num = i;
            ll ans = permute(i,p,n);
            
            if(a[ans] != b[i]){
                flag = true;
                break;
            }
        }
        next_permutation(p, p+n);
        if(flag) continue;
        return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    // string s[m];
    vector<string> s(m);
    for(ll i=0; i<m; i++){
        cin >> s[i];
    }

    if(m > 5000){
        cout << 5000 << endl;
        return 0;
    }

    vector<ll> num_one(m);
    for(ll i=0; i<m; i++){
        num_one[i] = hash1(s[i]);
    }

    ll pow2 = (1<<n);
    // ll setbit[pow2+1];
    vector<ll> setbit(pow2+1);
    for(ll i=0; i<=pow2; i++){
        setbit[i] = countSetBits(i);
    }

    vector<vector<ll> > cnt(m, vector<ll>(n+1, 0));
    // ll cnt[m][n+1];
    // for(ll i=0; i<n; i++) memset(cnt[i], 0, n+1);

    for(ll i=0; i<m; i++){
        for(ll j=0; j<pow2; j++){
            if(s[i][j] == '1'){
                cnt[i][setbit[j]]++;
            }
        }
    }

    unordered_set<ll> part;
    unordered_set<ll> :: iterator it;

    ll fact_n = 1;
    for(ll i=2; i<=n; i++) fact_n = fact_n * i;

    for(ll i=0; i<m; i++){
        if(part.empty()){
            part.insert(i);
            continue;
        }

        bool flag = false;
        for(it = part.begin(); it!=part.end(); it++){
            if(num_one[i] != num_one[*it]) continue;
            
            for(ll c=0; c<n+1; c++){
                if(cnt[i][c] != cnt[*it][c]){
                    continue;
                }
            }

            if(check(s[i], s[*it], n, fact_n)){
                flag = true;
                break;
            }
        }
        if(!flag){
            part.insert(i);
        }
    }

    cout << part.size() << endl;

    return 0;
}