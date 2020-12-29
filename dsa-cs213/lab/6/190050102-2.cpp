#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;

    int *a;
    a = new int[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    } 


    int l[n], r[n]; 
    long long first[n];

    l[0] = -1;
    for(int i=1; i<n; i++){
        int j=i-1;
        while((j>=0) && (a[j] < a[i])) j = l[j];
        l[i] = j;
    }

    r[n-1] = n;
    for(int i=n-2; i>=0; i--){
        int j=i+1;
        while((j<n) && (a[j] < a[i])) j = r[j];
        r[i] = j;
    }

    for(int i=0; i<n; i++){
        l[i] = i-l[i];
        r[i] = r[i]-i;
        first[i] = l[i]*r[i];
    }

    for(int i=0; i<n; i++) cout << first[i] << " "; cout << endl;
    // for(int i=0; i<n; i++) cout << l[i] << " "; cout << endl;
    // for(int i=0; i<n; i++) cout << r[i] << " "; cout << endl;


    // int sn[n];
    // sn[0] = -1;
    // for(int i=1; i<n; i++){
    //     int j=i-1;
    //     while((j>=0) && (a[j] <= a[i])) j = sn[j];
    //     sn[i] = j;
    // }

    // for(int i=0; i<n; i++) cout << sn[i] << " "; cout << endl;

    // vector<int> v[1001];
    // long long ans=0;

    // for(int i=0; i<n; i++) v[a[i]].push_back(i);


    // for(int i=0; i<n; i++){
    //     int a = i;
    //     int b = sn[i];

    //     for(int j=0; j<=max(a, b); j++){
    //         int cnt = lower_bound(v[i].begin(), v[i].end(), a) - lower_bound(v[i].begin(), v[i].end(),b) ;
    //         cout << cnt << end;
    //     }

        
    // }




    

}