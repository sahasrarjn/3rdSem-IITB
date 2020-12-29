/*
At the start of the ith iteration, 
the elements a[0] to a[i-1] are 
grouped in pairs of distinct numbers and 
the only number x remains cnt times.

For cnt=1:
cnt = 0 means

For cnt=0:
cnt = 0 means, 

induction hypothesis is that the number of left elements 
is either cnt or cnt+1 at any iteration and this remains constant

if x appeared 1 times, 
we pair the unequal element and 
left = 0 and so is cnt  
whereas if x appeared 0 time, 
left = 1 and cnt is 0 and 
the property is still satisfied.
*/

#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

bool majority(int a[], int n){
    int x = a[0];
    int cnt = 1;
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