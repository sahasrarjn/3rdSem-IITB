#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power2(ll n){
    return 1<<n;
}

ll msb(ll n){
    if(n==0)
        return 0;

    ll ans=0;
    n = n / 2; 
    while (n != 0) { 
        n = n / 2;
        ans++; 
    } 
  
    return (1 << ans);
}

void first(ll n, ll p, ll *F, ll*inp, ll post){
    if(n==0){
        F[post] = inp[post];
        return;
    }

    first(n-1, p/2, F, inp, post);
    first(n-1, p/2, F, inp, post+p/2);
    
    for(ll i=post+p/2; i<post+p; i++){
        ll temp = i-post;
        ll sub = msb(temp)^temp;

        F[i] += F[post+sub];
    }
    
    return;
}


void second(ll n, ll p, ll *f, ll *F, ll*inp, ll post, bool *forF){
    if(n==0){
        if(forF[post]==1){
            // F[post] = inp[post];
            f[post] = inp[post];
        }
        else{
            f[post] = inp[post];
            // F[post] = inp[post];
        }
        return;
    }

    second(n-1, p/2, f, F, inp, post, forF);
    second(n-1, p/2, f, F, inp, post+p/2, forF);
    
    for(ll i=post+p/2; i<post+p; i++){
        ll temp = i-post;
        ll sub = msb(temp)^temp;
        
        // for(ll t=0; t<p; t++) cout << f[t] << "   "; cout << endl;
        // for(ll t=0; t<p; t++) cout << F[t] << "   "; cout << endl;

        // cout << i << " test " << sub <<" " << post <<  " " << F[post+sub] << " " << forF[i] <<  endl;
        if(forF[i] == 0)
            f[i] -= f[post+sub];
            // F[i] += F[post+sub];
        // else{
            // F[i] += F[post+sub];
        // }
    }
    // cout << F[3] << '\n';
    
    return;
}



int main(){

    ll n;
    cin >> n;

    ll p =power2(n);

    bool forF[p];

    ll *inp = new ll [p];
    ll *f = new ll [p];
    ll *F = new ll [p];
    ll *F2 = new ll [p];
    ll *f2 = new ll [p];

    for(ll i=0; i<p; i++) cin >> inp[i];

    first(n, p, F, inp, 0);

    for(ll i=0; i<p; i++) cout << F[i] << " "; cout << endl;


    for(ll i=0; i<p; i++) cin >> forF[i];

    
    second(n, p, f2, F2, inp, 0, forF);
    // first(n, p,)

    // for(ll i=0; i<p; i++) cout << f2[i] << " "; cout << endl;
    // for(ll i=0; i<p; i++) cout << F2[i] << " "; cout << endl;


    for(ll i=0; i<p; i++){
        if(forF[i]==0)
            cout << F2[i] << " ";
        else
            cout << f2[i] << " ";
    }
    cout << endl;

}