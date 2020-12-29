#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


class graph{
    int n;
    list<int> *pos;
public:
    graph(int _n){
        n = _n;
        pos = new list<int>[2*n];
    }

    ~graph(){
        delete [] pos;
    }

    void edge(int u, int v){
        pos[2*u].push_back(2*v+1);
        pos[2*v+1].push_back(2*u);
        pos[2*v].push_back(2*u+1);
        pos[2*u+1].push_back(2*v);
    }

    int findMid(int u, int v, vector<int> &a){
        int visited[2*n];
        for(int i=0; i<2*n; i++) visited[i] = -1;

        list<int> queue; 
  
        visited[u] = 0;
        queue.push_back(u);
    
        list<int>::iterator i; 
    
        while(!queue.empty()) 
        { 
            u = queue.front();
            queue.pop_front(); 
    
            for (i = pos[u].begin(); i != pos[u].end(); ++i)
            {
                if (visited[*i] == -1)
                {
                    visited[*i] = visited[u]+1;
                    queue.push_back(*i);
                }
            }
        }

        for(int i=0; i<2*n; i++){
            if(visited[i] == visited[v]/2){
                a.push_back(i/2);
            }
        }
        
        return visited[v];
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m >> u >> v;

    graph g(n);

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g.edge(a, b);
    }

    vector<int> v1, v2;
    int len;
    len = g.findMid(2*u, 2*v, v1);
    len = g.findMid(2*v, 2*u, v2);
    
    if(len%2 == 0){
        cout << "possible" << endl;
        cout << len/2 << endl;
        vector<int> v(v1.size(), v2.size());
        vector<int>::iterator it, st; 
        it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin()); 
        for (st = v.begin(); st != it; ++st)
            cout << *st << " "; 
        cout << endl;
    }else{
        cout << "impossible" << endl;
    }
    return 0;
}