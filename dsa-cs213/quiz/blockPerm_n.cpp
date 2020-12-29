#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

struct seq{
    int a, b, M, m;
};

seq merge(seq &one, seq &two){
    seq temp;
    temp.a = one.a;
    temp.b = two.b;
    temp.m = min(one.m, two.m);
    temp.M = max(one.M, two.M);
    return temp;
}

int num_block(int p[], int n){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << num_block(a, n) << '\n';
}
