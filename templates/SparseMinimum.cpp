#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define double long double
#define endl '\n'

class SparseTable {
private:
    std::vector<std::vector<int>> table;
    std::vector<int> log;

public:
    SparseTable(const std::vector<int>& arr) {
        int n = arr.size();
        int maxLog = std::log2(n) + 1;
        table.assign(n, std::vector<int>(maxLog));
        log.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }

        for (int j = 1; j <= maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = std::min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        int j = log[R - L + 1];
        return std::min(table[L][j], table[R - (1 << j) + 1][j]);
    }
};


 
 
void solve(){


}
	
 
 
int main() {
    cin.tie(0);
	ios_base::sync_with_stdio(0);
 
	ll t=1; cin>>t;
	while(t--)solve();
	return 0;
}