#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define double long double
#define endl '\n'

 
ll mod = 998244353;

class SegmentTree
{
    vector<int> tree;
    const int INF = 2e9;
    int n;
 
public:
    SegmentTree(int ss)
    {
        int s = 2*pow(2, ceil(log2(ss)));
        tree = vector<int>(s, INF);
        n = s/2;
    }

    SegmentTree(){}

    void operator = (const SegmentTree & s){
        this->tree = s.tree;
        this->n = s.n;
    }
 
    void update(int idx1, int add)
    {
		int t = idx1 + tree.size()/2;
		tree[t] = add;
        for(t>>=1; t ; t>>=1) tree[t] = min(tree[(t<<1)], tree[(t<<1)|1]);
    }
 
    int query(int idx1, int idx2)
    {
        int l = idx1 + n;
        int r = idx2 + n + 1;
        int res = INF;

        while (l < r) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

};



void solve(){
    int n,q; cin>>n>>q;

    SegmentTree st(n);
    for(int i=0;i<n; i++){
        int x;cin>>x;
        st.update(i, x);
    }
    while(q--){
        int op,a,b;cin>>op>>a>>b;
        if(op==1){
            a--;
            st.update(a, b);
        }else{
            a--;b--;
            cout << st.query(a,b) << endl;

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