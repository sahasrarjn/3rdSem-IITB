#include<bits/stdc++.h>
#include<tuple>
using namespace std;

typedef long long ll;

struct T{
    int a, b, c;
};

struct compare{
    bool operator()(T const &t1, T const &t2){
        if(t1.a == t2.a){
            return t1.b < t2.b;
        }
        return t1.a < t2.a;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, multiset<T,compare> > S1, S2;
    vector<int> p,q;

    T x;
    int arr[4][n];
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> sorta, sortc;
    for(int i=0; i<n; i++){
        x.a = arr[0][i];
        x.b = arr[1][i]+1;
        x.c = i+1;
        S1[x.a].insert(x);

        x.a = arr[2][i];
        x.b = arr[3][i];
        x.c = i+1;
        S2[x.a].insert(x);
    }

    vector< multiset<T,compare> > s1, s2;

    for(auto it=S1.begin(); it != S1.end(); it++){
        s1.push_back(it->second);
    }
    for(auto it=S2.begin(); it != S2.end(); it++){
        s2.push_back(it->second);
    }

    for(int i=0; i<s1.size(); i++){
        for(auto it = s1[i].begin(); it!=s1[i].end(); it++){
            cout << it->a << " " <<it->b << " " << it->c << endl;
        }
    }
    for(int i=0; i<s2.size(); i++){
        for(auto it = s2[i].begin(); it!=s2[i].end(); it++){
            cout << it->a << " " <<it->b << " " << it->c << endl;
        }
    }

    for(int i1=0, i2=0; q.size()<n;){
        // cout << s1[i1].size() << " " << s2[i2].size() << endl; 
        if(s1[i1].size() < s2[i2].size()){
            for(auto t = s1[i1].begin(); t != s1[i1].end(); t++){
                T temp = *t;
                temp.b--;
                auto it = s2[i2].upper_bound(temp);
                if(it == s2[i2].begin()){
                    cout << "impossible" << endl;
                    return 0;
                }
                --it;
                p.push_back(t->c);
                q.push_back(it->c);
                s2[i2].erase(it);
            }
            i1++;
        }else{
            for(auto t = s2[i2].begin(); t!=s2[i2].end(); t++){
                auto it = s1[i1].upper_bound(*t);
                if(it == s1[i1].end()){
                    cout << "impossible" << endl;
                    return 0;
                }
                q.push_back(t->c);
                p.push_back(it->c);
                s1[i1].erase(it);
            }
            i2++;
            if(s1[i1].size() == 0) i1++;
        }
    }

    for(int i=0; i<p.size(); i++){
        cout << p[i];
        if(i!=p.size()-1) cout << " ";
    }cout << endl;
    for(int i=0; i<q.size(); i++){
        cout << q[i];
        if(i!=q.size()-1) cout << " ";
    }cout << endl;

}