#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct edge {
    ll valor = 0, flujo = 0, capacidad = 0, posAncestro = 0;
    edge(ll valor, ll capacidad, ll posAncestro)
        : valor(valor), flujo(0), capacidad(capacidad), posAncestro(posAncestro) {}
};

struct dinic {
	const ll INF = 1e18;
	vector<ll> nivel, nextEdge, padre;
	vector<vector<edge>>adj;
	vector<vector<ll>> resp, resp2;
	dinic(int n){
		nivel = nextEdge = padre = vector<ll>(n);
		adj = vector<vector<edge>>(n);
		resp = resp2 = vector<vector<ll>>(n);
	}
	
    ll dfs(ll ini, ll sumidero, ll flujoTotal, ll pap) {
        if (ini == sumidero) {
            return flujoTotal;
        }
        for (ll i = nextEdge[ini]; i < adj[ini].size(); i++) {
            ll disponible = adj[ini][i].capacidad - adj[ini][i].flujo;
            if (disponible == 0 || nivel[adj[ini][i].valor] != nivel[ini] + 1) {
                nextEdge[ini]++;
                continue;
            }
            ll flujoMin = dfs(adj[ini][i].valor, sumidero, min(flujoTotal, disponible), ini);
            if (flujoMin > 0) {
                adj[ini][i].flujo += flujoMin;
                adj[adj[ini][i].valor][adj[ini][i].posAncestro].flujo -= flujoMin;
                return flujoMin;
            }
            nextEdge[ini]++;
        }
        return 0;
    }

    bool bfs(ll s, ll t, ll n) {
        fill(nivel.begin(), nivel.end(), -1);
        queue<ll> q({s});
        nivel[s] = 0;
        while (!q.empty()) {
            ll u = q.front();
            nextEdge[u]=0;	
            q.pop();
            if (u == t) {
                return true;
            }
            for (edge e : adj[u]) {
                int v = e.valor;
                ll disponible = e.capacidad - e.flujo;
                if (nivel[v] == -1 && disponible > 0) {
                    nivel[v] = nivel[u] + 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    ll maxFlow(ll s, ll t, ll n) {
        ll ans = 0;
        while (bfs(s, t, n)) {
            while (ll inc = dfs(s, t, INF, -1)) {
                ans += inc;
            }
        }
        return ans;
    }
	void addEdge(ll origen, ll destino, ll capacidad, bool undirected = false) {
	    adj[origen].push_back({destino, capacidad, adj[destino].size()});
	    adj[destino].push_back({origen, capacidad * undirected, adj[origen].size() - 1});
	}
};


void solve(){
    dinic d(5);
    //d.addEdge(origen, target, capacity, isbidirect);
    //index base 1
    // d.maxFlow(source, sink, nodes)
	
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t=1; cin>>t;
    while(t--)solve();

    return 0;
}



	