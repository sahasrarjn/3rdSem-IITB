// Pg 22, ex 2.1-4, Binary Addition
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

    int a[n], b[n];
    
    fori(i, n){
        cin >> a[i];
    }
    fori(i, n){
        cin >> b[i];
    }

    int c[n+1];
    memset(c, 0, n+1);

    int carry=0;
    for(int i=n-1; i>=0; i--){
        c[i+1] = a[i]+b[i]+carry;
        if(c[i+1] > 1){
            c[i+1]-=2;
            carry = 1;
        }else{
            carry = 0;
        }
    }

    c[0] = carry;

    fori(i, n+1){
        cout << c[i];
    }
    
    cout << endl;
}