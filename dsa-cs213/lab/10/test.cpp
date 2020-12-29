#include<bits/stdc++.h>
#include<bitset>
typedef long long ll;
using namespace std;


int fact(int n){
    if(n == 1) return 1;
    return fact(n-1)*n;
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

bool check(string a, string b, int n){
    int p[n];
    int pow2 = (1<<n);
    for(int i=0; i<n; i++){
        p[i] = i;
    }

    int fac = fact(n);

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

    cout << check("00001010", "00011000", 3) << endl;
    cout << check("00001010", "00001100", 3) << endl;
    // cout << check("0101", "0011", 2) << endl;
    
}