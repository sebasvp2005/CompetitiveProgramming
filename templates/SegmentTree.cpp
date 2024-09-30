#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
class SegmentTree
{
    vector<ll> tree;
    vector<ll> lazy;
    int n;
 
    void build_tree(const vector<int>& v, int node, int a, int b)
    {
        if (a > b) return;
 
        if (a == b) { tree[node] = v[a]; return; }
 
        build_tree(v, node * 2, a, (a + b) / 2);
        build_tree(v, node * 2 + 1, 1 + (a + b) / 2, b);
        tree[node] = tree[node * 2]+ tree[node * 2 + 1];
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
 
    void update_tree(int node, int a, int b, int i, int j, ll value)
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
 
        tree[node] = tree[node * 2]+ tree[node * 2 + 1];
    }
 
    ll query_tree(int node, int a, int b, int i, int j)
    {
        if (a > b || a > j || b < i) return 0;
 
        if (lazy[node] != 0) update_lazy(node,a,b);
 
        if (a >= i && b <= j) return tree[node];
 
        ll q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
        ll q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
 
        return q1 +  q2;
    }
 
public:
    SegmentTree(const vector<int>& v)
    {
        n = v.size();
 
        int s = 2*pow(2, ceil(log2(v.size())));
 
        tree = vector<ll>(s,0);
        lazy =  vector<ll>(s,0);
 
 
        build_tree(v, 1, 0, n - 1);
    }
    
    SegmentTree(){

    }

    void operator = (const SegmentTree & s){
        this->tree = s.tree;
        this->lazy = s.lazy;
		this->n = s.n;
    }
 
    void update(int idx1, int idx2, ll add)
    {
        update_tree(1, 0, n - 1, idx1, idx2, add);
    }
 
    ll query(int idx1, int idx2)
    {
        return query_tree(1, 0, n - 1, idx1, idx2);
    }
};
 
 
int main(){
    int n,m;cin>>n>>m;
    vector<int>arr(n);
    for(auto &e: arr) cin>>e;
    SegmentTree st (arr);
    while(m--){
        int a;cin>>a;
        if(a==1){
            int b,c,d;cin>>b>>c>>d;
            st.update(b-1,c-1, d);
        }
        else{
            int b;cin>>b;
            cout << st.query(b-1, b-1) << endl;
        }
    }
 
}
