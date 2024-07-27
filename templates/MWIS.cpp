#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'


pair<ll, unordered_set<ll>> calculate_mwis(const vector<vector<int>>& tree, const vector<ll>& weights, int n, const vector<bool>& deleted) {
    vector<ll> dp_incl(n, 0);
    vector<ll> dp_excl(n, 0);
    vector<vector<ll>> included_nodes(n);
    vector<vector<ll>> excluded_nodes(n);
    vector<bool> visited(n, false);

    function<void(int, int)> dfs = [&](int node, int parent) {
        dp_incl[node] = weights[node];
        dp_excl[node] = 0;
        included_nodes[node] = {node};
        excluded_nodes[node] = {};

        for (int neighbor : tree[node]) {
            if (neighbor != parent && !deleted[neighbor] && !visited[neighbor]) {
                dfs(neighbor, node);
                dp_incl[node] += dp_excl[neighbor];
                included_nodes[node].insert(included_nodes[node].end(), excluded_nodes[neighbor].begin(), excluded_nodes[neighbor].end());
                if (dp_incl[neighbor] > dp_excl[neighbor]) {
                    dp_excl[node] += dp_incl[neighbor];
                    excluded_nodes[node].insert(excluded_nodes[node].end(), included_nodes[neighbor].begin(), included_nodes[neighbor].end());
                } else {
                    dp_excl[node] += dp_excl[neighbor];
                    excluded_nodes[node].insert(excluded_nodes[node].end(), excluded_nodes[neighbor].begin(), excluded_nodes[neighbor].end());
                }
            }
        }

        visited[node] = true;
    };

    ll ans = 0;
    unordered_set<ll> final_set;

    for (int i = 0; i < n; ++i) {
        if (!deleted[i] && !visited[i]) {
            dfs(i, -1);
            if (dp_incl[i] > dp_excl[i]) {
                ans += dp_incl[i];
                final_set.insert(included_nodes[i].begin(), included_nodes[i].end());
            } else {
                ans += dp_excl[i];
                final_set.insert(excluded_nodes[i].begin(), excluded_nodes[i].end());
            }
        }
    }

    return {ans, final_set};
}

void solve_monster_problem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> weights(n);
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }
        vector<vector<int>> nodes(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            nodes[a - 1].push_back(b - 1);
            nodes[b - 1].push_back(a - 1);
        }
        vector<bool> deleted(n, false);
        ll dele = 0;
        for (auto weight : weights) {
            dele += weight;
        }


        ll ans = dele;
        int sum=n;
        while(sum){
            auto result = calculate_mwis(nodes, weights, n, deleted);
            cout << result.first << endl;
            dele -= result.first;
            ans += dele;
            for (int node : result.second) {
                if(!deleted[node]) sum--;
                deleted[node] = true;
            }

        }
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(0);
	ios_base::sync_with_stdio(0);
    solve_monster_problem();
    return 0;
}
