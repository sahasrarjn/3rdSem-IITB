#include<bits/stdc++.h>
using namespace std;

int height(string s){
	stack <int> h;
	int curr=0, ht=0;
	for(int i=0; i<s.length(); i++)
	if(s[i] == 	'('	){
		if( ht<=curr ) ht++;
		h.push(	++curr );
	}
	else{
		curr=h.top();
		h.pop();
	}
	return ht;
}

int func(string s){
	int cnt=0, num=0;
	for(int i=0; i<s.length(); i++)
		if(s[i]=='(')cnt++;
		else{
			cnt--;
			if(cnt==0)num++;
		}
		return num;
}

int main(){
	// string s = "()()";
	// string s2 = "((())(())())(())()";
	// string s3 = "(()())()";
	// cout << height(s) << endl;
	// cout << height(s2) << endl;
	// cout << height(s3) << endl;
	// cout << height("((((()))))") << endl;
	// cout << height("()()()()()") << endl;
	int t=10;
	string s;
	while(t--){
		cin >> s;
		cout << height(s) << endl;
		// cout << "height: " << height(s) << endl;
		// cout << "func: " << func(s) << endl;
	}

	// cout << func("") << endl;
	// cout << func(s) << endl;	
	// cout << func(s2) << endl;	
	// cout << func(s3) << endl;	
}
