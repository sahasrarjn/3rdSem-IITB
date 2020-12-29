#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 6;
	int parent[] = {-1,0,1,0,3,3};

	std::vector<bool> visited(n,false);
	list<int> L;
	L.push_back(0);
	visited[0] = true;
	for(int i=n-1; i>0; i--){
		list<int>::iterator p = L.begin();
		int j = i;
		while(!visited[j]){
			visited[j] = true;
			L.insert(p,j);
			j = parent[j];
		}
	}

	list<int>::iterator p;
	for(p = L.begin(); p!=L.end(); p++){
		cout << *p << " ";
	}
	cout << endl;
}