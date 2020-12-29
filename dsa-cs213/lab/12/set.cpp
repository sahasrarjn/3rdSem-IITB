#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

static int cnt = 0;

class graph{
    struct edge{
        int a;
        list<edge> :: iterator e;
        int x1,x2,x3,x4;
        edge(int _a, int _x1=0, int _x2=0, int _x3=0, int _x4=0){
            a = _a;
            x1=_x1, x2=_x2, x3=_x3, x4=_x4;
        }
    };

    struct node{
        int a, b;

        node(int _a=0, int _b=0){
            a = _a;
            b = _b;
        }
    };

    int n;
    int left;
    bool *exists;
    list<edge> *adj;
    queue<int> q;
    vector<node> vert;
public:
    graph(int _n){
        n = _n;
        left = n;
        adj = new list<edge>[2*n];
        
        for(int i=0; i<n; i++){
            vert.push_back(node());
        }

        exists = new bool[n];
        for(int i=0; i<n; i++) exists[i] = true;
    }

    ~graph(){
        delete [] adj;
        delete [] exists;
    }

    void addEdge(int u, int v, bool series=false, int x1=0, int x2=0, int x3=0, int x4=0){
        // Check for TC
        int a, b;
        if(adj[u].size() > adj[v].size()){
            a = v; b = u;
        }else{
            a = u; b = v;
        }

        for(auto it=adj[a].begin(); it!=adj[a].end(); it++){
            // Parallel merge
            if(it->a == b){
                it->x1 += x1;
                it->x2 += x2;
                it->x3 += x3;
                it->x4 += x4;
                it->e->x1 += x1;
                it->e->x2 += x3;
                it->e->x3 += x2;
                it->e->x4 += x4;
                return;
            } 
        }

        if(series){
            adj[u].push_back(edge(v, x1, x2, x3, x4));
            adj[v].push_back(edge(u, x1, x3, x2, x4));
        }else{
            adj[u].push_back(edge(v));
            adj[v].push_back(edge(u));
        }

        adj[u].back().e = --adj[v].end();
        adj[v].back().e = --adj[u].end();
    }

    void pushToQueue(){
        for(int i=0; i<n; i++){
            if(adj[i].size() <= 2){
                q.push(i);
            }
        }
    }

    bool check(int &ans){
        while(!q.empty() && left > 1){
            int node = q.front();
            q.pop();
            int degree = adj[node].size();
            if(degree == 1){
                // Node of degree 1
                int neigh = adj[node].back().a;
                
                list<edge> :: iterator iter = adj[node].back().e;
                adj[neigh].erase(iter);
                
                int a1 = max(iter->x1 + vert[node].a + 1, iter->x2 + vert[node].b);
                int a2 = max(iter->x3 + vert[node].a + 1, iter->x4 + vert[node].b);

                exists[node] = false;
                left--;
                adj[node].clear();

                vert[neigh].a = a1;
                vert[neigh].b = a2;

                // queuing it if it becomes 2
                if(adj[neigh].size() == 2){
                    q.push(neigh);
                }
            }
            else if(degree == 2){
                // Node of degree 2
                // Series merge
                int n1 = adj[node].front().a;
                int n2 = adj[node].back().a;

                list<edge> ::iterator it1 = adj[node].front().e, it2 = adj[node].back().e;
                adj[n1].erase(it1);
                adj[n2].erase(it2);

                int x1 = max(it1->x1 + it2->x1 + vert[node].a, it1->x3 + it2->x3 + vert[node].b);
                int x2 = max(it1->x1 + it2->x2 + vert[node].a, it1->x3 + it2->x4 + vert[node].b);
                int x3 = max(it1->x2 + it2->x1 + vert[node].a, it1->x4 + it2->x3 + vert[node].b);
                int x4 = max(it1->x2 + it2->x2 + vert[node].a + 1, it1->x4 + it2->x4 + vert[node].b);
                addEdge(n1,n2, true, x1, x2, x3, x4);

                if(adj[n1].size() <= 2) q.push(n1);
                if(adj[n2].size() <= 2) q.push(n2);

                exists[node] = false;
                // left--;
                adj[node].clear();
            }
            else if(degree == 0){
                ans = max(vert[node].a, vert[node].b);
                return true;
            }
        }
        
        int left=0;
        int idx=0;
        for(int i=0; i<n; i++){
            if(exists[i]){
                idx = i;
                left++;
            } 
        }
        // cout << "left: " << left << endl;
        if(left == 1){
            ans = max(vert[idx].a, vert[idx].b);
            return true;
        } 
        return false;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    graph g(n);

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g.addEdge(a,b);
    }
    
    int ans;
    g.pushToQueue();
    if(g.check(ans)){
        cout << "yes" << endl;
        cout << ans << endl;
    }else{
        cout << "no" << endl;
    }
}