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


    int sn[n];
    sn[0] = -1;
    for(int i=1; i<n; i++){
        int j=i-1;
        while((j>=0) && (a[j] <= a[i])) j = sn[j];
        sn[i] = j;
    }

    // for(int i=0; i<n; i++){
    //     int j=i-1;
    //     while( (j>=0) && (a[j] != a[i])) {
    //         j = j-1;
    //     }

    //     if(j > 0) sn[i] = j;
    // }

    // for(int i=0; i<n; i++) cout << sn[i] << " "; cout << endl;

    // int second[n], max_till=a[0], max_pos=0;
    // second[0] = 1;
    // for(int i=1; i<n; i++){
    //     // if(max_till < a[i]){
    //     //     max_till = a[i];
    //     //     max_pos = i;
    //     // }

        
    //     if(a[i] < a[i-1]){
    //         second[i] = 1;
    //         continue;
    //     }

    //     if(sn[i] == -1){
    //         second[i] = 1;
    //         continue;
    //     }

    //     second[i] = second[sn[i]]+1;
    // }

    // for(int i=0; i<n; i++) cout << second[i] << " "; cout << endl;


    // int ans=0;
    // for(int i=0; i<n; i++) ans += second[i];
    // cout << ans << endl;


    vector <int> v;
    long long ans=0;
    v.push_back(0);
    int i = 1;

    while(true){
        if(v[ v.size()-1 ] <= a[i]){
            v.push_back(i);
            i++;
            if(i >= n) break;
        }else{
            v.pop_back();
            ans += v.size() - (lower_bound(v.begin(), v.end(), sn[i] + 1) - v.begin());
        }
    }

    while(v.size() != 0){
        v.pop_back();
        ans += v.size() - (lower_bound(v.begin(), v.end(), sn[v[n-1]] + 1) - v.begin());
    }

    cout << ans << endl;

    // for(int i=1; i<n; i++){
    //     // for(int j=0; j<v.size(); j++) cout << v[j] << " "; cout << endl;
    //     if(a[i] < v[v.size()-1]){
    //         // cout << (lower_bound(v.begin(), v.end(), sn[i]+1) - v.begin()) << endl;
    //         // ans += v.size() - (lower_bound(v.begin(), v.end(), sn[i]+1) - v.begin());
    //         ans += 1;
    //         v.pop_back();
    //         // cout << v.size() - (lower_bound(v.begin(), v.end(), sn[i]+1) - v.begin()) << endl;
    //     }else{
    //         v.push_back(a[i]);
    //     }
    // }


}