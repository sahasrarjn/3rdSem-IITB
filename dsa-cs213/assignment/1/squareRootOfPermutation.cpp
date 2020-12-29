#include<bits/stdc++.h>
using namespace std;

bool sortBySize(vector<int> &a, vector<int> &b){
	return a.size() > b.size();
}

void cycle(int *a, vector<vector<int>> &v, int s, bool *visited){
	vector <int> temp;
	int i=a[s];
	temp.push_back(s);
	visited[s]=true;

	while(s != i){
		visited[i] = true;
		temp.push_back(i);
		i = a[i];
	}

	v.push_back(temp);

	return;
}

void srqt(int *a, int n){
	if(n==1){
		cout << a[0]+1 << "\n";
		return;
	}

	vector <vector<int>> v;
	bool visited[n];
	memset(visited, false, n);

	for(int i=0; i<n-1; i++){
		if(!visited[i]){
			cycle(a, v, i, visited);
		}
	}

	vector<int> ans;
	sort(v.begin(), v.end(), sortBySize);
	int finalAns[n];

	for(int i=0; i<v.size(); i++){
		
		if(v[i].size()==v[i+1].size() && i!=v.size()-1){
			for(int j=0; j<v[i].size(); j++){
				ans.push_back(v[i][j]);
				ans.push_back(v[i+1][j]);
			}
			i++;
		}
		else if(v[i].size()%2==0){
			cout << "-1\n";
			return;
		}else{
			vector<int> temp(v[i].size());

			int t=0;
			for(int j=0; j<v[i].size(); j++){
				temp[t] = v[i][j];
				t+=2;
				if(t>=v[i].size()) t=1;
			}
			for(int i=0; i<temp.size(); i++){
				ans.push_back(temp[i]);
			}
			temp.clear();
		}

		for(int t=0; t<ans.size()-1; t++){
			finalAns[ans[t]] = ans[t+1];
		}
		finalAns[ans[ans.size()-1]] = ans[0];
		
		ans.clear();
	}

	for(int i=0; i<n; i++){
		cout << finalAns[i]+1 << " "; 
	}cout << '\n';


	return;
}

int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i]--;
	}

	srqt(a, n);
}
