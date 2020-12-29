#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vll vector<ll>

using namespace std;

vector<ll> get_small(vector<ll> &a){
	ll n = a.size();
	vll f(n);
	f[0]=-1;
	for(ll i = 1; i<n;i++){
		ll j = i-1;
		while(j>=0 && a[j]<a[i]) j = f[j];
		f[i] = j;
	}
	return f;
}


void print(vector<ll> &v){
	for(int i=0;i<v.size();i++)
		cout << v[i] << " ";
	cout << endl;
}

// gives the just big element than i
vector<ll> get_big(vector<ll> &a){
	ll n = a.size();
	vll f(n);
	f[0]=-1;
	for(ll i = 1; i<n;i++){
		ll j = i-1;
		while(j>=0 && a[j]<=a[i]) j = f[j];
		f[i] = j;
	}
	return f;
}




int main(){
	ll n; cin >> n;
	vector<ll> a;
	for(int i=0;i<n;i++){
		ll x; cin >> x;
		a.pb(x);
	}

	vll b = a;
	reverse(b.begin(), b.end());

	// v1 and v2 contain the indices of the value just greater than the one at index i
	vll v1 = get_small(a);
	vll v2 = get_small(b);

	vll ans1,ans2;
	for(int i=0;i<n;i++){
		ans1.pb(i-v1[i]-1);
		ans2.pb(i-v2[i]-1);
	}

	// cout << "ans1 = " << ans1[n-2] <<" "<< "ans2 = "<<  ans2[n-1] << endl;

	reverse(ans2.begin(), ans2.end());
	
	// for(int i=0;i<n;i++)
	// 	cout << "ans1 = " << ans1[i] <<" "<< "ans2 = "<<  ans2[i] << "p = " << (ans1[i]+1)*(ans2[i]+1)<< endl;
	// 	// cout << (ans1[i]+1)*(ans2[i]+1) << " ";
	// cout << endl;


	for(int i=0;i<n;i++)
		cout << (ans1[i]+1)*(ans2[i]+1) << " ";
	cout << endl;

	vll big = get_big(a);
	ll ans = 0;
	vll aux;
	for(ll i=0;i<n;i++){
		while(!aux.empty() && a[aux.back()]>a[i]){
			aux.pop_back();
		}
		aux.pb(i);
		// cout << "aux.size  = " << (ll)aux.size() << endl;
		// cout << (ll)aux.size()-(ll)(lower_bound(aux.begin(), aux.end(),big[i]+1)-aux.begin()) << endl;
		// print(aux);
		ans = ans + (ll)aux.size()-(ll)(lower_bound(aux.begin(), aux.end(),big[i]+1)-aux.begin());
	}

	cout << ans << endl;
}


