#include<bits/stdc++.h>
using namespace std;

int presuf(int *a, int n){
    int len[n];
    len[0] = 0;

    for(int i=1; i<n; i++){
        int j =  len[i-1] ;
        while((  j>0   )&&(  a[j]  !=a[i])) j =  len[j-1]  ;
        if(  a[i]==a[j]   ) len[i] =  j+1    ;
        else len[i]=0;
    }

    for(int i=0; i<n; i++) cout << len[i] << " "; cout << endl;

    return len[n-1];
}

int main(){
    int a[8] = {
        1, 2, 3, 4, 1, 2, 3, 4
    };

    cout << presuf(a, 8) << endl;

}