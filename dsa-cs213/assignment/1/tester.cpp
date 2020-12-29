#include<bits/stdc++.h>
#include<chrono>
#include<algorithm>
#include "assignment.h"
using namespace std;
typedef long long ll;
#define pb push_back
const ll INF = 1e18;

int gcd(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    if (a == b) 
        return a; 
   
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}

int pro(int n, int aray[])
{
	vector<int> v;
	int visit[n], c = 0;
	memset(visit, 0, n);

	for(int i=0;i<n;i++)
	{
		if(visit[i])
			continue;
		c = 1;
		int curr = aray[i];
		while(curr != i)
		{
			c++;
			curr = aray[curr];
		}
		v.pb(c);
	}
	int ans = 1;
	// for(auto x: v)
	// fori(t, v.size())
	for(int t=0; t<v.size(); t++)
		ans = ans/gcd(ans, v[t])*v[t];
	return ans;
}
int main()
{
	srand(time(0));
	int n=10;
	// cin>>n;
	int aray[n];
	for(ll i=0;i<n;i++)
		aray[i] = i;
	int t=5;
	// cin>>t;
	int c = 0, high = 0, same = 0;
	int total = 0;
	cout << "Started\n";
	while(t--)
	{
		cout << "iterating...\n";
		ll raise = rand()%(INF);
		// random_shuffle(aray, aray+n);
		permutation p = permutation(n, aray);
		int lcm = pro(n, aray);
		permutation q = p^raise;
		int val = p.log(p);
		// if(val == raise)
		// 	same++;
		// if(val >= lcm)
		// {
		// 	c++;
		// 	continue;
		// }
	// 	high = max(high, val);
	// 	if(val == -1)
	// 	{
	// 		c++;
	// 		continue;
	// 	}
		// permutation ans = p^val;
		// int *arr = q.to_array(), *a = ans.to_array();
		// for(int i=0;i<n;i++)
		// {
		// 	if(a[i] != arr[i])
		// 	{
		// 		c++;
		// 		break;
		// 	}
		// }
	}
	cout<<"Highest value of log: "<<high<<"\n";
	cout<<"Number of times the raised power equals log: "<<same<<"\n";
	cout<<"Number of wrong answers: "<<c<<"\n";
	cout<<"Execution time (in microseconds): "<<total<<"\n";
	return 0;
}
