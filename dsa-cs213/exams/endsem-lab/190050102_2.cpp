#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node{
    ll n, e;

    node(ll _n, ll _e){
        n = _n;
        e = _e;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<node> s;
    string str;
    cin >> str;

    for(ll i=0; i<str.length(); i++){
        if(str[i] == 'e'){
            s.push(node(1,0));
        }else{
            ll a, b;
            node n1 = s.top(); s.pop();
            node n2 = s.top(); s.pop();
            a = n1.n + n2.n;
            b = n1.e + n2.e;
            
            if(str[i] == '0'){
                s.push(node(a,b));
            }else if(str[i] == '1'){
                b += n1.n*n2.n;
                s.push(node(a,b));
            }else{
                cout << "error" << endl;
            }
        }
    }

    node last = s.top(); s.pop();
    cout << last.e << endl;
}