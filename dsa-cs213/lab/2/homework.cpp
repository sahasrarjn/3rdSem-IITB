#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(long long i=0; i<n; i++)
#define prlong long(x) cout << x << endl;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    int a[k];
    fori(i, k){
        cin >> a[i];
        // scanf("%d", &a[i]);
    }

    string toPr;
    for(int i=1; i<k; i++){
        toPr += to_string(i) + " ";
    }


    for(int i=0; i<n; i++){
        // cout << toPr;
        printf("%s", toPr.c_str());
    }
    // toPr = toPr + toPr + toPr;
    // cout << "0\n";

    // while(a[0] != n){
    //     long long max_index = max_element(a.begin()+1, a.end()) - a.begin();
    //     long long elem = a[max_index];

    //     cout << max_index << " ";
    //     a[max_index] = 0;

    //     long long b, c;
    //     b = (max_index+1)%k;
    //     c = (max_index + elem%k)%k;

    //     long long extra = elem%k;
    //     if(c>=b){
    //         extra--;
    //     }

    //     for(long long i=0; i<k; i++){
    //         a[i] += extra;
    //         if(i<=c) a[i]++;
    //         else if(i>=b) a[i]++;
    //     }
    // }
    cout << "0\n";
}