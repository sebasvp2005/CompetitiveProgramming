#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll mod = 1e9+7;


const int LOG = 23;

const int PHI = -1;
const int NOL = -2;
const int INF = 1e9;

vector<int> hungarianAlgorithm(const vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();
    int m = costMatrix[0].size(); 

    vector<int> u(n + 1, 0), v(m + 1, 0), p(m + 1, 0), way(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        vector<int> minV(m + 1, INF);
        vector<bool> used(m + 1, false);
        p[0] = i;
        int j0 = 0;

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minV[j]) {
                        minV[j] = cur;
                        way[j] = j0;
                    }
                    if (minV[j] < delta) {
                        delta = minV[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minV[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    vector<int>assignment(n);
    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            assignment[p[j] - 1] = j - 1;
        }
    }
    return assignment;
}


void solve(){


}



    
	
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
 
	int t=1;// cin>>t;
	while(t--)solve();
	return 0;
}