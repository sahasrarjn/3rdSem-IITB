#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class graph{
    int n;
    list<int> *adj;
    list<int> *rev;
    int *sccNum;
    int sccCnt;
    list<int> *sccAdj;
    vector<int> sccRep;

    struct edge{
        int a, b; // a -> b
        bool keep;

        edge(int _a, int _b){
            a = _a;
            b = _b;
            keep = false;
        }
    };

    void dfs(int s, bool *visited, vector<edge> &edges){
        visited[s] = true;
        for(auto it = adj[s].begin(); it!=adj[s].end(); it++){
            if(visited[*it]) continue;
            edges.push_back(edge(s,*it));
            dfs(*it, visited, edges);
        }
        return;
    }

    void dfsRev(int s, bool *visited, vector<edge> &edges){
        visited[s] = true;
        for(auto it = rev[s].begin(); it!=rev[s].end(); it++){
            if(visited[*it]) continue;
            edges.push_back(edge(s,*it));
            dfs(*it, visited, edges);
        }
        return;
    }

public:
    graph(int _n){
        n = _n;
        adj = new list<int>[n];
        rev = new list<int>[n];
        sccNum = new int[n];
        sccAdj = NULL;
    }

    ~graph(){
        delete [] adj;
        delete [] rev;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        rev[v].push_back(u);
        return;
    }

    void SCC() 
    { 
        int *disc = new int[n]; 
        int *low = new int[n]; 
        bool *stackMember = new bool[n]; 
        stack<int> *st = new stack<int>(); 
    
        for (int i = 0; i < n; i++) 
        { 
            disc[i] = -1; 
            low[i] = -1; 
            stackMember[i] = false; 
        } 
    
        int cnt = 0;
        for (int i = 0; i < n; i++) 
            if (disc[i] == -1){
                SCCUtil(i, disc, low, st, stackMember, cnt); 
                cnt++;
            }

        sccCnt = cnt;
        sccAdj = new list<int>[n];          // Delete this
        for(int i=0; i<n; i++){
            for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
                if(sccNum[i] == sccNum[*it]) continue;
                sccAdj[sccNum[i]].push_back(sccNum[*it]);
            }
        }

        cout << "testing" << endl;
        cout << cnt << endl;
        for(int i=0; i<n; i++){
            cout << sccNum[i] << " ";
        }
        cout << endl;
        map();

        delete [] sccAdj;
        sccAdj = NULL;
    }

    void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[], int cnt){ 
        static int time = 0; 
    
        disc[u] = low[u] = ++time; 
        st->push(u); 
        stackMember[u] = true; 
    
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = *i;  // v is current adjacent of 'u' 
    
            if (disc[v] == -1) 
            { 
                SCCUtil(v, disc, low, st, stackMember, cnt); 
    
                low[u]  = min(low[u], low[v]); 
            } 
    
            else if (stackMember[v] == true) 
                low[u]  = min(low[u], disc[v]); 
        } 
    
        int w = 0;  // To store stack extracted vertices 
        if (low[u] == disc[u]) 
        { 
            while (st->top() != u) 
            { 
                w = (int) st->top(); 
                // cout << w << " "; 
                sccNum[w] = cnt;
                stackMember[w] = false; 
                st->pop(); 
            } 
            w = (int) st->top(); 
            // cout << w << "\n"; 
            sccNum[w] = cnt;
            stackMember[w] = false; 
            st->pop(); 
        } 
    } 

    void search(int x, int &w, bool *marked, bool *sink, bool *source, bool &sinkNotFound){
        if(!marked[x]){
            cout << "search: " << x << endl;
            if(sink[x]){
                w = x;
                sinkNotFound = false;
            }
            cout << "marking " << x << endl;
            marked[x] = true;
        }
        if(!sinkNotFound) return;   // check
        for(auto it = sccAdj[x].begin(); it != sccAdj[x].end(); it++){
            if(sinkNotFound) search(*it, w, marked, sink, source, sinkNotFound);
        }
    }

    void map(){
        bool marked[sccCnt];
        for(int i=0; i<sccCnt; i++) marked[i] = false;
        int w;
        bool sinkNotFound;

        // Find in and out degree
        int indeg[sccCnt], outdeg[sccCnt];
        for(int i=0; i<sccCnt; i++) indeg[i]=0, outdeg[i]=0;
        memset(indeg, 0, sccCnt);
        memset(outdeg, 0, sccCnt);

        cout << "scc Edges" << endl;
        for(int i=0; i<sccCnt; i++){
            for(auto it=sccAdj[i].begin(); it!=sccAdj[i].end(); it++){
                cout << i << " " << *it << endl;
                indeg[i]++;
                outdeg[*it]++;
            }
        }
        cout << "edges done" << endl;

        // Find source, sink
        bool source[sccCnt],  sink[sccCnt];
        for(int i=0; i<sccCnt; i++) source[i]=false, sink[i]=false;

        for(int i=0; i<sccCnt; i++){
            if(indeg[i] == 0) source[i] = true;
            if(outdeg[i] == 0) sink[i] = true;
        }

        // source
        for(int i=0; i<sccCnt; i++) cout << source[i] << " "; cout << endl;  
        // sink
        for(int i=0; i<sccCnt; i++) cout << sink[i] << " "; cout << endl;  

        // before algo
        cout << "before algo" << endl;
        for(int i=0; i<sccCnt; i++){
            for(auto it=sccAdj[i].begin(); it!=sccAdj[i].end(); it++){
                cout << i << "-->" << *it << endl;
            }
        }

        int i=0;
        for(int j=0; j<sccCnt; j++){
            for(int t=0; t<sccCnt; t++) cout << marked[i] << ": "; cout << endl;
            if(!marked[j]){
                cout << j << endl;
                w = -1;
                sinkNotFound = true;
                search(j, w, marked, sink, source, sinkNotFound);
                if(w != -1){
                    sccAdj[j].push_back(w);
                    i++;
                    // v[i] = v;
                    // w[i] = w;
                }else{
                    cout << "error" << endl;
                }
            }
        }
        int p = i;
        cout << p << endl;

        // after algo
        for(int i=0; i<sccCnt; i++){
            for(auto it=sccAdj[i].begin(); it!=sccAdj[i].end(); it++){
                cout << i << "-->" << *it << endl;
            }
        }
    }

    void first(){
        vector<edge> edges;

        bool visited[n];
        for(int i=0; i<n; i++) visited[i] = false;
        dfs(0,visited, edges);
        for(int i=0; i<n; i++) visited[i] = false;
        dfsRev(0,visited, edges);

        cout << edges.size() << endl;
        for(int i=0; i<edges.size(); i++){
            cout << edges[i].a << " " << edges[i].b << endl; 
        }

        return;
    }

    void second(){
        return;
    }

    void third(){
        return;
    }

    void fourth(){
        return;
    }

    void printEdges(){
        for(int i=0; i<n; i++){
            for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
                cout << i << " " << *it << endl;
            }
        }
        return;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, op;
    cin >> n >> m >> op;

    graph g(n);

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g.addEdge(a, b);
    }

    switch (op) {
        case 0:
            g.first();
            break;
        case 1:
            g.second();
            break;
        case 2:
            g.third();
            break;
        case 3:
            // g.SCC();
            g.fourth();
            break;
    }

    return 0;
}