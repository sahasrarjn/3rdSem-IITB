#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct boolPost{
	bool b;
	ll post;
};

// Function to implement KMP algorithm
int KMP(string X, string Y)
{
	int m = X.length();
	int n = Y.length();

	// if Y is an empty string
	if (n == 0)
	{
		return 0;
	}

	// if X's length is less than that of Y's
	if (m < n)
	{
		return -1;
	}

	// next[i] stores the index of next best partial match
	int next[n + 1];

	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++)
	{
		int j = next[i + 1];

		while (j > 0 && Y[j] != Y[i])
			j = next[j];

		if (j > 0 || Y[j] == Y[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		if (X[i] == Y[j])
		{
			if (++j == n)
				return i - j + 1;
		}
		else if (j > 0) {
			j = next[j];
			i--;	// since i will be incremented in next iteration
		}
	}
    return -1;
}


boolPost isSubSequence(string &str1, string &str2, ll m, ll n) 
{ 
    if (m == 0){
		boolPost temp;
		temp.b = true;
		temp.post = 0;
		return temp;
	}
    if (n == 0){
		boolPost temp;
		temp.b = false;
		temp.post = 0;
		return temp;
	} 
  
    if (str1[m-1] == str2[n-1]){
		boolPost temp;
		temp = isSubSequence(str1, str2, m-1, n-1);
		temp.post++;
		return temp;
	}

	boolPost temp;
	temp = isSubSequence(str1, str2, m, n-1); 
    temp.post++;
	return temp;
	// return isSubSequence(str1, str2, m, n-1);
} 

int SubSequence(string a, string b){
	int j = 0;
	int alen = a.length();
	int blen = b.length();
	
	for(int i=0; i<a.length(); i++){
		if(a[i] == b[j]){
			j++;
		}
		// cout << a[i] << " " << i << " " << j << endl;

		if(j == blen) return i;
	}
	return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "abaababaabaababaababaabaa";
    string b = "aaabab";
	cout << SubSequence(a, b) << endl;
}