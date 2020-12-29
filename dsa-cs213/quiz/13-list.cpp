#include<iostream>
// #include<algorithm>
#include<list>
using namespace std;

void fun(list <int> &l){
	auto p = l.begin();
	for(int i=0; i<l.size()/2; i++){ // 13
		l.insert(l.end(),*++p);  // 12
		p = l.erase(p);	// 10
	}
}

void invfun(list <int> &l){
	auto p = l.begin();
	auto q = p;

	for(int i=0; i< (l.size()+1)/2; i++) q++;
	for(int i=0; i<l.size()/2; i++){
		l.insert(++p,*q);
		q = l.erase(q);
	}
}

int main(){
	int n;
	cin >> n;

	list<int>l;
	for(int i=0; i<n; i++) l.push_back(i);

	invfun(l);
	fun(l);


	while(!l.empty()){
		cout << l.front() << " ";
		l.pop_front();
	}cout << endl;
}


/*
1 2 3 4 5 6
1 3 5 2 4 6
*/
