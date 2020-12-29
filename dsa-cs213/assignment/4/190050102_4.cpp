// Ref: http://www.springer.com/cda/content/document/cda_downloaddocument/9780387235288-c2.pdf

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll N = 100005;
ll sccRep[N], in_deg[N], out_deg[N];
vector<ll> v[N], v1[N], v3[N], v4[N];

class graph{
    ll n, w, p;
    list<ll> *adj, *rev, *sccAdj;
    set<ll> s1, s2;
    set<pair<ll, ll> > e1, e2, e;
    bool snf;
    vector<ll> in, out, src, src2, snk1, snk2, iso, src3, snk;
    map<int, vector<int> > ans;
    ll *sccRep, *in_deg, *out_deg;
    ll cnt, inc=1, sccNum, sccCnt;

    struct edge{
        ll a, b; // a -> b
        bool keep;

        edge(ll _a, ll _b){
            a = _a;
            b = _b;
            keep = false;
        }
    };

    void dfs(ll u, bool *reached, vector<edge> &e){
        reached[u] = true;
        for(auto it : adj[u]){
            if(reached[it] == true) continue;
            e.push_back(edge(u,it));
            dfs(it, reached, e);
        }
        return;
    }

    void dfs(ll u, bool *reached) {
        in_deg[u] =inc, reached[u] = true;
        for (ll v: v3[u]) {
            if (reached[v]==false) {
                out_deg[u] =inc;
                dfs(v, reached);
            }
        }
    }

    void dfs(ll u, bool* reached, list<ll> &s) {
        reached[u] = true;
        for (auto v: v3[u]) {
            if (!reached[v]) {
                e1.insert({u, v});
                dfs(v, reached, s);
            }
        }
        s.push_back(u);
    }

    void dfs(ll u, bool* reached, ll sccNum) {
        reached[u] = true, sccRep[u] = sccNum, ans[sccNum].push_back(u);
        for (auto x: v4[u]) {
            if (!reached[x]) {
                e2.insert({u, x});
                dfs(x, reached, sccNum);
            }
        }
    }

    void dfsRev(ll s, bool *reached, vector<edge> &e){
        reached[s] = true;
        for(auto it : rev[s]){
            if(reached[it]) continue;
            e.push_back(edge(s,it));
            dfs(it, reached, e);
        }
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
        // sccAdj = new list<int>[n];          // Delete this
        // for(int i=0; i<n; i++){
        //     for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
        //         if(sccNum[i] == sccNum[*it]) continue;
        //         sccAdj[sccNum[i]].push_back(sccNum[*it]);
        //     }
        // }

        // cout << "testing" << endl;
        // cout << cnt << endl;
        // for(int i=0; i<n; i++){
        //     cout << sccNum[i] << " ";
        // }
        cout << endl;
        // map();

        delete [] sccAdj;
        sccAdj = NULL;
    }

    void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[], int cnt){ 
        static int time = 0; 
    
        disc[u] = low[u] = ++time; 
        st->push(u); 
        stackMember[u] = true; 
    
        list<int>::iterator i; 
        // for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        // { 
        //     int v = *i;  // v is current adjacent of 'u' 
    
        //     if (disc[v] == -1) 
        //     { 
        //         SCCUtil(v, disc, low, st, stackMember, cnt); 
    
        //         low[u]  = min(low[u], low[v]); 
        //     } 
    
        //     else if (stackMember[v] == true) 
        //         low[u]  = min(low[u], disc[v]); 
        // } 
    
        int w = 0;  // To store stack extracted vertices 
        if (low[u] == disc[u]) 
        { 
            while (st->top() != u) 
            { 
                w = (int) st->top(); 
                // cout << w << " "; 
                // sccNum[w] = cnt;
                stackMember[w] = false; 
                st->pop(); 
            } 
            w = (int) st->top(); 
            // cout << w << "\n"; 
            // sccNum[w] = cnt;
            stackMember[w] = false; 
            st->pop(); 
        } 
    } 

    void mapping(){
        bool marked[sccCnt];
        for(int i=0; i<sccCnt; i++) marked[i] = false;
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
        cout << "edges dinc" << endl;

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

        int i=0, w;
        for(int j=0; j<sccCnt; j++){
            for(int t=0; t<sccCnt; t++) cout << marked[i] << ": "; cout << endl;
            if(!marked[j]){
                cout << j << endl;
                w = -1;
                sinkNotFound = true;
                // search(j, w, marked, sink, source, sinkNotFound);
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

    void search(ll x) {
        if (!src3[x]) {
            if (v[x].size() == 0) {
                w = x;
                snf = 0;
            }	
            src3[x] =inc;
            for (auto y: v[x]) {
                if (snf) search(y);
            }
        }
    }

    void prlledges(){
        for(ll i=0; i<n; ++i){
            for(auto it=adj[i].begin(); it!=adj[i].end(); ++it){
                cout << i << " " << *it << endl;
            }
        }
        return;
    }

public:
    graph(ll _n){
        n = _n;
        w = 0;
        adj = new list<ll>[n];
        rev = new list<ll>[n];
        sccAdj = new list<ll>[n];
        in = vector<ll>(n,0);
        out = vector<ll>(n,0);
        snf = true;
        sccRep = new ll[N];
        in_deg = new ll[N];
        out_deg = new ll[N];
        cnt = 0;
    }

    ~graph(){
        delete []adj;
        delete []rev;
        delete []sccAdj;
        delete []sccRep;
        delete []in_deg;
        delete []out_deg;
    }

    void addEdge(ll u, ll v){
        adj[u].push_back(v);
        rev[v].push_back(u);
		if (out[u] == 0) out[u] =inc;
		if (in[v] == 0) in[v] =inc;
        v3[u].push_back(v);
		e.insert({u, v});
		v4[v].push_back(u);
        return;
    }

    void first(){
        vector<edge> e;

        bool reached[n];
        for(ll i=0; i<n; ++i) reached[i] = false;
        dfs(0,reached, e);
        for(ll i=0; i<n; ++i) reached[i] = false;
        dfsRev(0,reached, e);

        cout << e.size() << endl;
        for(ll i=0; i<e.size(); ++i){
            cout << e[i].a << " " << e[i].b << endl; 
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
        list<ll> lst;
        bool reached[n];
        for(ll i=0; i<n; ++i) reached[i] = false;
        for (ll i = 0; i < n; ++i) {
            if (!reached[i]) {
                dfs(i, reached, lst);
            }
        }
        vector<ll> temp[n];
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < v3[i].size(); ++j) {
                temp[v3[i][j]].push_back(i);
            }
        }
        for(ll i=0; i<n; ++i) reached[i] = false;
        sccNum = 0;
        for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
            if (!reached[*it]) {
                sccNum++;
                dfs(*it, reached, sccNum);
            }
        }
        
        if(sccNum == inc){
            cout << "0" << endl;
            return;
        }

        set<pair<ll, ll> > temp1;
        for(auto x=e.begin(); x!=e.end(); x++)
            if (sccRep[x->first] != sccRep[x->second] && temp1.find({sccRep[x->first], sccRep[x->second]}) == temp1.end()) {
                temp1.insert({sccRep[x->first], sccRep[x->second]});
                v1[sccRep[x->second]].push_back(sccRep[x->first]);
                v[sccRep[x->first]].push_back(sccRep[x->second]);
        } 
        
        ll n = sccNum;
        ll tempcnt = 0;
        for(ll i=0; i<N; ++i){
            iso.push_back(0);
            src3.push_back(0);
            snk.push_back(0);
            src2.push_back(0);
            snk2.push_back(0);
        }
        for (ll i =inc; i <= n; ++i) {
            if (v[i].size() == 0 && v1[i].size() == 0) {
                ++tempcnt;
                iso[tempcnt] = i;
            }
            else if (v[i].size() == 0){
                snk1.push_back(i);
            }else if(v1[i].size() == 0){
                src.push_back(i);
            }
        }

        for (ll i = 0; i < src.size(); ++i) {
            if (!src3[src[i]]) {
                ll v = src[i];
                w = 0;
                snf =inc;
                search(v);
                if (w != 0) {
                    cnt++;
                    snk2[cnt] = w;
                    s2.insert(w);
                    snk[w] =inc;
                    src2[cnt] = v;
                    s1.insert(v);
                }
            }
        }
        p = cnt;

        ll temp2 = cnt;
        for (ll i = 0; i < src.size(); ++i) {
            if (s1.find(src[i]) == s1.end()) {
                src2[++temp2] = src[i]; 
            }
        }	

        temp2 = cnt;
        for (ll j = 0; j < snk1.size(); ++j) {
            if (s2.find(snk1[j]) == s2.end()) {
                snk2[++temp2] = snk1[j];
            }
        }

        ll s = src.size(), t = snk1.size(), q = tempcnt;

        vector<ll> src21 = snk2;
        vector<ll> snk_temp = src2;

        set<pair<int, int> > final;
        bool enter =inc;
        
        // cout << "test" << endl;
        // cout << s << " " << t << " " << enter << endl;
        if (s == t && s == 0 && q > 0) {
            enter = 0;
            for (ll i =inc; i < n; ++i) 
                final.insert({i, i +inc});
            final.insert({n,inc});
        }
        else if (t < s && enter){
            ll s1 = t, t1 = s;

            if (q == 0 && s1 == t1) {
                final.insert({snk_temp[p], src21[1]});
            }
            else if (q == 0 && s1 < t1) {
                for (ll i = s1 +inc; i < t1; ++i) {
                    final.insert({snk_temp[i], snk_temp[i +inc]});
                }
                final.insert({snk_temp[t1], src21[1]});
                final.insert({snk_temp[p], snk_temp[s1 +inc]});
            }
            else {
                if (s1 < t1) final.insert({snk_temp[p], snk_temp[s1 +inc]});
                
                for (ll i = s1 +inc; i < t1; ++i) {
                    final.insert({snk_temp[i], snk_temp[i +inc]});
                }
                final.insert({snk_temp[t1], iso[1]});
                for (ll i =inc; i < q; ++i) {
                    final.insert({iso[i], iso[i +inc]});
                }
                final.insert({iso[q], src21[1]});
            }

            for (ll i =inc; i < p; ++i) {
                final.insert({snk_temp[i], src21[i +inc]});
            }
            for (ll i = p +inc; i <= s1; ++i) {
                final.insert({snk_temp[i], src21[i]});
            }
        }
        if (s <= t && enter) {
            if (q == 0 && s < t) {
                final.insert({snk2[p], snk2[s +inc]});
                for (ll i = s +inc; i < t; ++i) {
                    final.insert({snk2[i], snk2[i +inc]});
                }
                final.insert({snk2[t], src2[1]});
            }
            else if (q == 0 && s == t) {
                final.insert({snk2[p], src2[1]});
            }
            else {
                if (s < t) final.insert({snk2[p], snk2[s +inc]});
                for (ll i = s +inc; i < t; ++i) {
                    final.insert({snk2[i], snk2[i +inc]});
                }
                final.insert({snk2[t], iso[1]});
                for (ll i =inc; i < q; ++i) {
                    final.insert({iso[i], iso[i +inc]});
                }
                final.insert({iso[q], src2[1]});
            }

            for (ll i =inc; i < p; ++i) {
                final.insert({snk2[i], src2[i +inc]});
            }
            for (ll i = p +inc; i <= s; ++i) {
                final.insert({snk2[i], src2[i]});
            }
        }

        cout << final.size() << endl;
        for (auto x: final) {
            printf("%d %d\n", ans[x.first][0], ans[x.second][0]);
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, op;
    cin >> n >> m >> op;
    graph g(n);

    int a, b;
    for(ll i=0; i<m; ++i){
        // scanf("%d %d", &a, &b);
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
            g.fourth();
            break;
    }

    return 0;
}