#include<bits/stdc++.h>
using namespace std;
#define ll long long int
using cd = complex<double>;
const double PI = acos(-1);

ll mod = 1e9+7;
 
class SegmentTree
{
    vector<int> tree;
    vector<int> lazy;
    const int INF = -1e9;
    int n;
 
    void build_tree(const vector<int>& v, int node, int a, int b)
    {
        if (a > b) return;
 
        if (a == b) { tree[node] = v[a]; return; }
 
        build_tree(v, node * 2, a, (a + b) / 2);
        build_tree(v, node * 2 + 1, 1 + (a + b) / 2, b);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
 
    void update_lazy(int node, int a, int b)
    {
        tree[node] += lazy[node];
 
        if (a != b) 
        { 
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    void update_tree(int node, int a, int b, int i, int j, int value)
    {
        if (lazy[node] != 0) update_lazy(node,a,b);
 
        if (a > b || a > j || b < i) return;
 
        if (a >= i && b <= j) 
        {
            tree[node] += value;
            if (a != b) 
            {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }
 
        update_tree(node * 2, a, (a + b) / 2, i, j, value);
        update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);
 
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
 
    int query_tree(int node, int a, int b, int i, int j)
    {
        if (a > b || a > j || b < i) return INF;
 
        if (lazy[node] != 0) update_lazy(node,a,b);
 
        if (a >= i && b <= j) return tree[node];
 
        int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
        int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
 
        return max(q1, q2);
    }
 
public:
    SegmentTree(const vector<int>& v)
    {
        n = v.size();
 
        int s = 2*pow(2, ceil(log2(v.size())));
 
        tree = vector<int>(s);
 
        lazy = vector<int>(s);

        build_tree(v, 1, 0, n - 1);
    }
 
    void update(int idx1, int idx2, int add)
    {
        update_tree(1, 0, n - 1, idx1, idx2, add);
    }
 
    int query(int idx1, int idx2)
    {
        return query_tree(1, 0, n - 1, idx1, idx2);
    }
};
 



 
void solve(){
 
}
    
	
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
 
	int t=1; //cin>>t;
	while(t--)solve();
	return 0;
}