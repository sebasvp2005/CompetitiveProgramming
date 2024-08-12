#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

const int MAXN = 100005;

vector<int> adj[MAXN];
int dp[MAXN][2];
int weight[MAXN];
bool visited[MAXN];

int find_maximum_weighted_independent_set(int n) {
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        dp[u][0] = 0;  
        dp[u][1] = weight[u];  // change this by 1 if only want the size
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
                dp[u][1] += dp[v][0];
                dp[u][0] += max(dp[v][0], dp[v][1]);
            }
        }
    };

    fill(visited, visited + n + 1, false);
    dfs(1);
    return max(dp[1][0], dp[1][1]);
}
