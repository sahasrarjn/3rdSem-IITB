#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n=10;
	cin >> n;
	vector<int> v(n,0);
	for(int i=0; i<n; i++) v[i] = i;
	random_shuffle(v.begin(), v.end());
	int i=3, l=3;
	// cin >> l >> i;


	
	for(int i=0; i<v.size(); i++) cout << v[i] << " "; cout << endl;

	// v.erase(v.begin(),v.insert(v.end(),v.begin(),v.begin()+i)-v.size()+i);
	// auto a = v.insert(v.begin(),v.begin()+i,v.begin()+i+l); 
	// v.erase(v.insert(v.begin(),v.begin()+i,v.begin()+i+l)+l,v.end());
	v.assign(v.begin()+i,v.begin()+i+l);
	

	for(int i=0; i<v.size(); i++) cout << v[i] << " "; cout << endl;
}
