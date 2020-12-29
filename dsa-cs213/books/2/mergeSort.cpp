// Merge sort
#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

void merge(int *a, int s, int mid, int e){
    int l[mid-s+1], r[e-mid];

    fori(i, mid-s+1){
        l[i] = a[s+i];
    }
    fori(i, e-mid){
        r[i] = a[mid+1+i];
    }

    int lc=0, rc=0;
    fori(i, e-s+1){
        if(rc>=e-mid){
            a[s+i] = l[lc];
            lc++;
            continue;
        }
        if(lc>=mid-s+1){
            a[s+i] = r[rc];
            rc++;
            continue;
        }
        
        if(l[lc]<r[rc]){
            a[s+i] = l[lc];
            lc++;
        }else{
            a[s+i] = r[rc];
            rc++;
        }
    }
}

void mergeSort(int *a, int s, int e){
    if(s >= e) return;
    int mid = (e+s)/2;

    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);
    merge(a, s, mid, e);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    fori(i, n){
        cin >> a[i];
    }

    mergeSort(a, 0, n-1);

    fori(i, n){
        cout << a[i] << ' ';
    }
    cout << endl;
}