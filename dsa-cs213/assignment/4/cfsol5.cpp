#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

const int N = 100100;
int n, m, op, comp_no;
vector<int> g[N], g1[N];
map<int, vector<int>> comp;
int which_comp[N], in_deg[N], out_deg[N];
set<array<int, 2>> edges1, edges2, edges;
set<array<int, 2>> con_edges;
vector<int> con[N], con1[N];
int w = 0, p;
vector<int> sources;
vector<int> o_sources;
vector<int> sinks;
vector<int> o_sinks;
vector<int> iso;
vector<int> sourcevis;
vector<int> sinkvis;
set<int> s1, s2;
int co = 0;
bool sinknotfound;

void search(int x) {
	if (!sourcevis[x]) {
		if (con[x].size() == 0) {
			w = x;
			sinknotfound = 0;
		}	
		sourcevis[x] = 1;
		for (auto y: con[x]) {
			if (sinknotfound) search(y);
		}
	}
}

void dfs(int u, vector<bool> &vis, list<int> &s) {
	vis[u] = 1;
	for (auto v: g[u]) {
		if (!vis[v]) {
			edges1.insert({u, v});
			dfs(v, vis, s);
		}
	}
	s.push_back(u);
}

void dfs1(int u, vector<bool> &vis1, int comp_no) {
	vis1[u] = 1;
	which_comp[u] = comp_no;
	comp[comp_no].push_back(u);
	for (auto x: g1[u]) {
		if (!vis1[x]) {
			edges2.insert({u, x});
			dfs1(x, vis1, comp_no);
		}
	}
}

void kosaraju() {
	list<int> s;
	vector<bool> vis(n, 0);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i, vis, s);
		}
	}
	vector<int> g1[n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			g1[g[i][j]].pb(i);
		}
	}
	vector<bool> vis1(n, 0);
	comp_no = 0;
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		if (!vis1[*it]) {
			comp_no++;
			dfs1(*it, vis1, comp_no);
		}
	}
}

void construct_condensation_graph() {
	for (auto x: edges) {
		if (which_comp[x[0]] != which_comp[x[1]]) {
			if (con_edges.find({which_comp[x[0]], which_comp[x[1]]}) == con_edges.end()) {
				con[which_comp[x[0]]].pb(which_comp[x[1]]);
				con1[which_comp[x[1]]].pb(which_comp[x[0]]);
				con_edges.insert({which_comp[x[0]], which_comp[x[1]]});
			}
		}  
	}
}

void dfs3(int u, vector<bool> &vis) {
	vis[u] = 1;
	in_deg[u] = 1;
	for (int v: g[u]) {
		if (!vis[v]) {
			out_deg[u] = 1;
			dfs3(v, vis);
		}
	}
}

void find_minimum_edges() {
	vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs3(i, vis);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// cin >> n; op = 3;
	cin >> n >> m >> op;
	int u, v;
	vector<int> in(n, 0), out(n, 0);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].pb(v);
		edges.insert({u, v});
		g1[v].pb(u);
		if (in[v] == 0) in[v] = 1;
		if (out[u] == 0) out[u] = 1;
	} 

	kosaraju();
	if (comp_no == 1) {
		cout << "0\n";
		return 0;
	}
	construct_condensation_graph();
	int n = comp_no;
	int ciso = 0;
	iso.assign(N, 0);
	for (int i = 1; i <= n; ++i) {
		if (con[i].size() == 0 && con1[i].size() == 0) {
			++ciso;
			iso[ciso] = i;
		}
		else if (con1[i].size() == 0) sources.pb(i);
		else if (con[i].size() == 0) sinks.pb(i);
	}

	sourcevis.assign(N, 0);
	sinkvis.assign(N, 0);
	o_sources.assign(N, 0);
	o_sinks.assign(N, 0);	

	for (int i = 0; i < sources.size(); ++i) {
		if (!sourcevis[sources[i]]) {
			int v = sources[i];
			w = 0;
			sinknotfound = 1;
			search(v);

			if (w != 0) {
				co++;
				o_sources[co] = v;
				s1.insert(v);
				o_sinks[co] = w;
				s2.insert(w);
				sinkvis[w] = 1;
			}
		}
	}
	p = co;
	int p1 = co;
	for (int i = 0; i < sources.size(); ++i) {
		if (s1.find(sources[i]) == s1.end()) {
			++p1;
			o_sources[p1] = sources[i]; 
		}
	}
	p1 = co;
	for (int j = 0; j < sinks.size(); ++j) {
		if (s2.find(sinks[j]) == s2.end()) {
			++p1;
			o_sinks[p1] = sinks[j];
		}
	}

	int s = sources.size(), t = sinks.size(), q = ciso;

	set<array<int, 2>> aug;
	bool enter = 1;
	if (s == t && t == 0 && q > 0) {
		enter = 0;
		for (int i = 1; i < n; ++i) 
			aug.insert({i, i + 1});
		aug.insert({n, 1});
	}
	if (s <= t && enter) {
		for (int i = 1; i < p; ++i) {
			aug.insert({o_sinks[i], o_sources[i + 1]});
		}
		for (int i = p + 1; i <= s; ++i) {
			aug.insert({o_sinks[i], o_sources[i]});
		}

		if (q == 0 && s == t) {
			aug.insert({o_sinks[p], o_sources[1]});
		}
		else if (q == 0 && s < t) {
			aug.insert({o_sinks[p], o_sinks[s + 1]});
			for (int i = s + 1; i < t; ++i) {
				aug.insert({o_sinks[i], o_sinks[i + 1]});
			}
			aug.insert({o_sinks[t], o_sources[1]});
		}
		else {
			if (s < t) aug.insert({o_sinks[p], o_sinks[s + 1]});
			for (int i = s + 1; i < t; ++i) {
				aug.insert({o_sinks[i], o_sinks[i + 1]});
			}
			aug.insert({o_sinks[t], iso[1]});
			for (int i = 1; i < q; ++i) {
				aug.insert({iso[i], iso[i + 1]});
			}
			aug.insert({iso[q], o_sources[1]});
		}
	}
	else if (t < s && enter){
		int s1 = t, t1 = s;
		vector<int> o_sources1 = o_sinks;
		vector<int> o_sinks1 = o_sources;
		set<array<int, 2>> aug1;

		for (int i = 1; i < p; ++i) {
			aug1.insert({o_sinks1[i], o_sources1[i + 1]});
		}
		for (int i = p + 1; i <= s1; ++i) {
			aug1.insert({o_sinks1[i], o_sources1[i]});
		}

		if (q == 0 && s1 == t1) {
			aug1.insert({o_sinks1[p], o_sources1[1]});
		}
		else if (q == 0 && s1 < t1) {
			aug1.insert({o_sinks1[p], o_sinks1[s1 + 1]});
			for (int i = s1 + 1; i < t1; ++i) {
				aug1.insert({o_sinks1[i], o_sinks1[i + 1]});
			}
			aug1.insert({o_sinks1[t1], o_sources1[1]});
		}
		else {
			if (s1 < t1) aug1.insert({o_sinks1[p], o_sinks1[s1 + 1]});
			for (int i = s1 + 1; i < t1; ++i) {
				aug1.insert({o_sinks1[i], o_sinks1[i + 1]});
			}
			aug1.insert({o_sinks1[t1], iso[1]});
			for (int i = 1; i < q; ++i) {
				aug1.insert({iso[i], iso[i + 1]});
			}
			aug1.insert({iso[q], o_sources1[1]});
		}

		for (auto x: aug1) {
			aug.insert({x[1], x[0]});
		}
	}
	set<array<int, 2>> ret;
	for (auto x: aug) {
		ret.insert({comp[x[0]][0], comp[x[1]][0]});
	}
	cout << ret.size() << endl;
	for (auto x: ret) {
		cout << x[0] << " " << x[1] << endl;
	}
	return 0;
}
