#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;
int subtree_size[100000];
bool is_removed[100000];
vector<int>nodes[100000];


int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : nodes[node]) {
		if (child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : nodes[node]) {
		if (child == parent || is_removed[child]) { continue; }
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}



void solve(){

}
	


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t=1; //cin>>t;
	while(t--)solve();
	return 0;
}