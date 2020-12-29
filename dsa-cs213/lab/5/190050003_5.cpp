#include <iostream>
using namespace std;
typedef long long ll;

void recur(ll* F, ll* doof, bool* isF, int s, int e){
    
    if(s==e){
        F[s] = doof[s];
        return;
    }
    recur(F, doof, isF, s, (s+e-1)/2);
    
    ll shift = (e-s+1)/2;
    for(int i = (s+e+1)/2; i <=e; i++)
        if(isF[i])
            doof[i] -= F[i-shift];
    
    recur(F, doof, isF, (s+e+1)/2, e);

    for(int i = s; i < s+shift; i++)
        F[i+shift] += F[i];

   return;
}

void reverse(ll* F, int s, int e){
    if(s==e)
        return;
    
    int shift = (e-s+1)/2;
    for(int i = s; i < s+shift; i++){
        F[i+shift] -= F[i];
    }
    reverse(F, s, (s+e-1)/2);
    reverse(F, (s+e+1)/2, e);

    return;
}


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n;
    cin >> n;

    ll tpn = (1 << n);
    ll doof[tpn];
    bool isF[tpn] = {0};

    for(ll i = 0; i < tpn; i++)
        cin >> doof[i];
    
    ll F[tpn];

    recur(F, doof, isF, 0, tpn-1);

    for(ll i = 0; i < tpn; i++)
        cin >> isF[i];

    for(ll i = 0; i < tpn; i++)
        cout << F[i] << ' ';
    cout << endl;
    

    // coverts all to F form
    recur(F, doof, isF, 0, tpn-1);
    ll F2[tpn];
    // saving for future print purposes :P
    copy(F, F+tpn, F2);
    // now reversing to 0 
    reverse(F2, 0, tpn-1);

    for(ll i = 0; i < tpn; i++){
        if(isF[i])
            cout << F2[i] << ' ';
        else
            cout << F[i] << ' ';
    }
    cout << endl;

    return 0;
}
    
