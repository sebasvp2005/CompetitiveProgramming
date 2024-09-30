#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
#define endl '\n'

class SegmentTree
{
    vector<ll> tree;
    const int INF = -2e9;
    int n;
 
public:
    SegmentTree(int ss)
    {
        int s = 2*pow(2, ceil(log2(ss)));
        tree = vector<ll>(s);
        n = s/2;
    }

    SegmentTree(){}

    void operator = (const SegmentTree & s){
        this->tree = s.tree;
        this->n = s.n;
    }
 
    void update(int idx1, ll add)
    {
		int t = idx1 + n;
		tree[t] = add;
        for(t>>=1; t ; t>>=1) tree[t] = tree[(t<<1)] + tree[(t<<1)|1];
    }
 
    ll query(int idx1, int idx2)
    {
        int l = idx1 + n;
        int r = idx2 + n + 1;
        ll res = 0;
		for(; l<r; l>>=1, r>>=1){
			if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
		}
        return res;
    }
};





class HLD{

	int cur_pos;
	vector<int> pos, heavy, depth, par, head, revert_pos;
	SegmentTree st;

	int dfs(int cur, vector<vector<int>> &nodes){
		int cur_max=0;
		int size=1;
		for(auto e: nodes[cur]){
			if(e==par[cur])continue;
			par[e] = cur; depth[e] = depth[cur]+1;
			int ne  = dfs(e, nodes);
			size += ne;
			if(ne > cur_max){
				cur_max = ne;
				heavy[cur]= e;
			}
		}
		return size;

	}

	void decompose(int cur, int  h, vector<vector<int>> &nodes){
		pos[cur]= cur_pos++;
		head[cur] = h;
		if(heavy[cur]!=-1){
			decompose(heavy[cur], h, nodes);
		}
		for(auto e: nodes[cur]){
			if(e == par[cur] or heavy[cur] == e)continue;
			decompose(e, e, nodes);
		}
	}

	ll custom_query(int l, int r){
		if(l>r)return 0;
		return st.query(l, r);
	}
	

public:

	HLD(vector<vector<int>> &nodes){
		build(nodes);
	}

	void build(vector<vector<int>>& nodes){
		int n = nodes.size();
		pos = par = depth = head =  revert_pos =vector<int>(n);
		heavy = vector<int>(n,-1);
		cur_pos = 0;
		dfs(0, nodes);
		decompose(0,0,nodes);
		st = SegmentTree(n);
		for(int i=0;i<n; i++){
			revert_pos[pos[i]]=i;
		}
	}

	ll query(int a, int b){
		ll ans  = 0;
		for(;head[a]!=head[b]; b = par[head[b]]){
			if(depth[head[a]] > depth[head[b]]) swap(a,b);
			ll cur = custom_query(pos[head[b]], pos[b]);
			ans += cur;
		}
		if(depth[a] > depth[b]) swap(a,b);
		ans += custom_query(pos[a], pos[b]);
		return ans;
	}

	ll query2(int a, int b){
		ll ans  = 0;
		for(;head[a]!=head[b]; b = par[head[b]]){
			if(depth[head[a]] > depth[head[b]]) swap(a,b);
			ll cur = custom_query(pos[head[b]], pos[b]);
			if(cur>0){
				int l = pos[head[b]], r = pos[b];
				if(l>r)swap(l,r);
				int ans;
				while(l<=r){
					int m = (l+r)/2;
					if(custom_query(l, m)>0){
						r = m-1;
						ans = m;
					}else  l =m+1;
				}
				return revert_pos[ans];
			}
		}
		if(depth[a] > depth[b]) swap(a,b);

		if(custom_query(pos[a], pos[b]) > 0){
			int l = pos[a], r = pos[b];
				int ans;
				if(l>r)swap(l,r);
				while(l<=r){
					int m = (l+r)/2;
					if(custom_query(l, m)>0){
						r = m-1;
						ans = m;
					}else  l =m+1;
				}
				return revert_pos[ans];

		}
		return -2;
	}

	int get_lca(int a, int b){
		for(;head[a]!=head[b]; b = par[head[b]]){
			if(depth[head[a]] > depth[head[b]]) swap(a,b);
		}
		if(depth[a] > depth[b]) swap(a,b);
		return a;
	}

	void update(int idx, int val){
		st.update(pos[idx],  val);
	}

	int get_tree_pos(int x){
		return pos[x];
	}

};

void solve(){

	int n,q; cin>>n>>q;
	vector<vector<int>>nodes(n);
	for(int i=1;i<n; i++){
		int a,b;cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	HLD hld(nodes);

	while(q--){
		int op,a;cin>>op>>a;
		a--;
		if(op == 0){
			int cur = hld.query(a,a);
			hld.update(a, (cur==0));
			
		}else{
			cout << hld.query2(0,a) + 1 << endl;

		}
	}


}

	
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t=1; //cin>>t;
	while(t--)solve();
	return 0;
}