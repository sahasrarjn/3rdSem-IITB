// Pg 22, ex 2.1-3, Lienar search
#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    fori(i, n){
        cin >> a[i];
    }
    int v;
    cin >> v;

    fori(i, n){
        if(a[i] == v){
            cout << i+1 << '\n';
            return 0;
        } 
    }
    cout << "NIL\n";

}