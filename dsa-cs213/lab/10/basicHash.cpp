#include<bits/stdc++.h>
#include<unordered_set>
typedef long long ll;
using namespace std;

int hash1(string s){
    // Count num of 1's
    int ans=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1'){
            ans++;
        }
    }
    return ans;
}

int permute(int a, int *p, int n){
    string s = bitset<8>(a).to_string();
    string out = string(8, '0');
    for(int i=8-n; i<8; i++){
        out[i] = s[8-n + p[i-8+n]];
    }
    int ans = bitset<8>(out).to_ulong(); 
    return ans;
}

bool check(string &a, string &b, int n, int fac){
    int p[n];
    int pow2 = (1<<n);
    for(int i=0; i<n; i++){
        p[i] = i;
    }

    for(int j=0; j<fac; j++){
        // All permutations
        bool flag = false;
        for(int i=0; i<pow2; i++){
            // All digits
            int num = i;
            int ans = permute(i,p,n);
            
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

    int n, m;
    cin >> n >> m;

    string s[m];
    for(int i=0; i<m; i++){
        cin >> s[i];
    }

    // if(n > 10 || m > 2000){

    // }

    int num_one[m];
    for(int i=0; i<m; i++){
        num_one[i] = hash1(s[i]);
    }
    


    unordered_set<int> part;
    unordered_set<int> :: iterator it;

    int fact_n = 1;
    for(int i=2; i<=n; i++) fact_n = fact_n * i;

    for(int i=0; i<m; i++){
        if(part.empty()){
            part.insert(i);
            continue;
        }

        bool flag = false;
        for(it = part.begin(); it!=part.end(); it++){
            if(num_one[i] == num_one[*it]){
                if(check(s[i], s[*it], n, fact_n)){
                    // cout << s[i] << "\t" << s[*it] << endl;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            part.insert(i);
        }
    }

    cout << part.size() << endl;

    return 0;
}