// Try same prob as 2-majority but with n/3 as the mark 


#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

bool majority(int a[], int n){
    int x=a[0];
    int cnt1=1, cnt2=1;
    for(int i=1; i<n; i++){
        cout << cnt << '\t' << a[i] << '\t' << x << '\n';
        if(a[i]==x) cnt++;
        else if(cnt == 0){
            x = a[i];
            cnt = 0;
        }
        else cnt--;
    }

    cnt=1;
    for(int i=0; i<n; i++)
        if(a[i]==x) cnt++;
    
    return (cnt>n/2);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];

    fori(i, n)  cin >> a[i];

    cout << bool(majority(a, n)) << '\n';
}