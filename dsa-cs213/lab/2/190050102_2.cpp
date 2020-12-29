#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(long long i=0; i<n; i++)
#define prlong long(x) cout << x << endl;

bool gtr(long long &a, long long &b){
    return a > b;
}

bool sortbyfir(const pair<long long,long long> &a, 
              const pair<long long,long long> &b) 
{ 
    return (a.first > b.first); 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;


    if(k == 0){
        return 0;
    }

    vector<long long> a(k,0);
    for(long long i=0; i<k; i++){
        cin >> a[i];
    }

    pair <long long, long long> tempvec[k-1];

    for(int i=1; i<k; i++){
        tempvec[i-1].first = a[i];
        tempvec[i-1].second = i;
    }

    sort(tempvec, tempvec+k-1, sortbyfir);

    string toPr;
    for(long long i=0; i<k-1; i++){
        toPr += to_string(tempvec[i].second) + " ";
    }

    for(long long i=0; i<n; i++){
        cout << toPr;
        if(a[0]==n){
            break;
        }
    }
    cout << "0\n";
}