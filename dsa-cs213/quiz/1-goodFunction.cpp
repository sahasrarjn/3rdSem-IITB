#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

int f(int n){
    switch (n)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 4;
    default:
        return n;
    }
    return n;
}

int solve(){
    int n;
    cin >> n;

    int p = 0;
    for(int i=0; i<n; i++){
        p = f(p);
        cout << p << "\tp loop1\n";
    }

    int q = f(p), l=1;

    while(q != p){
        q = f(q);
        l++;
        cout << q << "\tq loop2\n";
    }

    p = q = 0;
    for(int i=0; i<l; i++) q = f(q);

    cout << q << "\tq\n";

    while(p!=q){
        p = f(p);
        q = f(q);
        cout << p << "  " << q << "\tloop3\n";
    }

    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << endl;
}

