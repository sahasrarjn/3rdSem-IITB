#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(long long i=0; i<n; i++)
#define prlong long(x) cout << x << endl;

long long par(vector<vector<long long>> &a, long long l, long long m){
    if(a[l][m] != -1){
        return a[l][m];
    }

    if(l==0){
        a[0][m] = 1;
        return 1;
    }

    long long temp = (m+1)*par(a, l-1, m);

    temp += par(a, l-1, m+1);

    a[l][m] = temp;
    return temp;
}

long long rnk(vector<vector<long long>> &memo, long long *x, long long n){
    long long mx=0, ans=0;
    bool start=false;
    fori(j, n){
        // cin >> x;                
        if(x[j]==0) continue;

        ans += x[j]*memo[n-j-1][mx];

        mx = max(mx, x[j]);
    }

    return ans;
}

void seq(vector<vector<long long>> &memo, long long rank, long long n){
    long long mx=0;
    vector<long long> ans(n, 0);

    for(long long i=n-1; i>=0; i--){
        if(memo[i][mx] <= rank){
            for(long long t=mx+1; t>=1; t--){
                if(t*memo[i][mx] <= rank){
                    ans[n-1-i] = t;
                    rank -= memo[i][mx]*t;
                    break;
                }
            }

            mx = max(ans[n-1-i], mx);
        }
        printf("%lld ", ans[n-1-i]);
    }printf("\n");

    ans.clear();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t;
    cin >> n >> t;

    vector<vector<long long>> memo(n+1, vector<long long> (n+1, -1));

    par(memo, n-1, 0);

    char c;
    fori(i, t){
        cin >> c;

        if(c == 'R'){
            long long x[n];

            fori(t, n){
                cin >> x[t];
            }

            printf("%lld\n", rnk(memo, x, n));
        }
        
        else{
            long long rnk;
            cin >> rnk;

            seq(memo, rnk, n);
        }
    }

}