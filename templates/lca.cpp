#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;

const int log2N = 17;
int parent[100001];
int depth[100001];
int ST[100001][20];

void dfs(int n, vector<int>nodes[], int p){
  ST[n][0] = parent[n];

  for(int j=1; j<=log2N; j++){
    ST[n][j] = ST[ST[n][j-1]][j-1];
  }

  for(auto b: nodes[n]){
    if(b==p)continue;
    parent[b]=n; 
    depth[b] = depth[n]+1;
    dfs(b, nodes, n);
  }
}

int lca(int a, int b){
  if(depth[a]< depth[b]) swap(a,b);

  int diff= depth[a] - depth[b];

  for(int i=log2N; i>=0; i--){
    if((diff>>i) &1){
      a = ST[a][i];
    }
  }

  if(a==b) return a;

  for(int i= log2N; i>=0 ;i--){
    if(ST[a][i]!=ST[b][i]){
      a = ST[a][i];
      b = ST[b][i];
    }
  }

  return ST[a][0];
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