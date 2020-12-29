#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

void odd(int a[], int n){
    int xr = 0;
    for(int i=0; i<n; i++) xr = xr^a[i];
    
    // int x = (xr-1 & xr+1);
    // int x = xr & ~(xr-1);
    
    // int x = xr - (xr-1&xr);
    // int x = (xr&(-xr));
    // int x = -xr&xr;
    int x = xr - (xr & xr-1);
    
    int y = 0;
    for (int i=0; i<n; i++){
        // cout << (x) << endl;
        if((x & a[i])==0) y = y^a[i];
    }

    cout << y << " " << (xr^y) << endl; 
    return;
}

int main(){
    int a[12] = {2, 6, 2, 6, 6, 6, 3, 3, 3, 4, 5, 5};

    odd(a, 12);

    // int a;
    // cin >> a;

    // cout << (a&(-a)) << endl;

}
