#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class graph{
    struct edge{
        int a;
        list<edge> :: iterator e;
        edge(int _a){
            a = _a;
        }
    };

    int n;
    bool *exists;
    list<edge> *adj;
    queue<int> q;
public:
    graph(int _n){
        n = _n;
        adj = new list<edge>[2*n];
        exists = new bool[n];
        for(int i=0; i<n; i++) exists[i] = true;
    }

    ~graph(){
        delete [] adj;
        delete [] exists;
    }

    void addEdge(int u, int v){
        // Check for TC
        int a, b;
        if(adj[u].size() > adj[v].size()){
            a = v; b = u;
        }else{
            a = u; b = v;
        }

        for(auto it=adj[a].begin(); it!=adj[a].end(); it++){
            if(it->a == b){
                // cout << "extra edge: " << a << " " << b << endl;
                return;
            } 
        }

        adj[u].push_back(edge(v));
        adj[v].push_back(edge(u));

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

    bool check(){

        while(!q.empty() && n > 1){
            int node = q.front();
            q.pop();
            int degree = adj[node].size();
            if(degree == 1){
                // cout << "deleting 1: " << node << endl;
                // Node of degree 1
                int neigh = adj[node].back().a;
                
                // cout << adj[neigh].size() << endl;      // test
                
                list<edge> :: iterator iter = adj[node].back().e;
                adj[neigh].erase(iter);

                // cout << adj[neigh].size() << endl;      // test
                
                exists[node] = false;
                adj[node].clear();

                // queuing it if it becomes 2
                if(adj[neigh].size() == 2){
                    q.push(neigh);
                }
            }
            else if(degree == 2){
                // Node of degree 2
                // If the node to be deleted has degree 2, again delete it and the two edges incident with it, 
                //  and add the edge between its neighbours.
                // cout << "deleting 2: " << node << endl;
                
                int n1 = adj[node].front().a;
                int n2 = adj[node].back().a;

                list<edge> ::iterator it1 = adj[node].front().e, it2 = adj[node].back().e;
                adj[n1].erase(it1);
                adj[n2].erase(it2);

                addEdge(n1,n2);


                if(adj[n1].size() <= 2) q.push(n1);
                if(adj[n2].size() <= 2) q.push(n2);

                exists[node] = false;
                adj[node].clear();
            }
            else if(degree == 0){
                // cout << "error degree 0, node: " << node << endl;
                return true;
            }
            else{
                // cout << "Error: degree 3: " << node << "\tsize: " << adj[node].size() << endl;
            }
        }
        
        
        int left=0;
        for(int i=0; i<n; i++){
            if(exists[i]) left++;
        }
        cout << "left: " << left << endl;
        if(left == 1) return true;
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
    
    g.pushToQueue();
    if(g.check()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}