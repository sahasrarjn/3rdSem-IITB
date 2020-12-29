#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

int num_block(int p[], int n){
    int m, M, num=0;
    
    for(int i=0; i<n; i++){
        m = n+1; M = 0;

        for(int j=i; j<n; j++){
            if(m > p[j]) m = p[j];
            if(M < p[j]) M = p[j];
            if(M == m+j-i) num++;
        }
    }

    return num;
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
