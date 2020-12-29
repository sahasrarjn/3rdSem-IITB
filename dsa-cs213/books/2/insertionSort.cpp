// Pg 22, ex 2.1-2, insertion sort, descending
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

    for(int j=1; j<n; j++){
        int key = a[j];
        int i = j-1;

        while(i >= 0 && a[i] < key){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }

    fori(i, n){
        cout << a[i] << ' ';
    }
    cout << endl;
}