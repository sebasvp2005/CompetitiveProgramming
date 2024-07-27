#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;
vector<ll> cells(1000001, 1e9);
ll dp[1000001];


void solve(){
    int n,m; cin>>n>>m;
    
    ll a[n],b[n];
    ll me[m];
    ll mx = 0;
    for(int i=0;i<n; i++) {cin>>a[i]; mx = max(mx , a[i]);}
    for(int i=0;i<n; i++) cin>>b[i];
    for(int i=0;i<m; i++) cin>>me[i];

    for(int i=0;i<n; i++){
        cells[a[i]] = min(cells[a[i]], a[i] - b[i]);
    }

    for(int i=1; i<=mx; i++){
        cells[i] = min(cells[i], cells[i-1]);
    }

    for(int i=1; i<=mx; i++){
        if(cells[i]!=1e9) dp[i] = 2 + dp[i - cells[i]];
    }
    

    ll ans =0;
    for(int i=0;i<m; i++){
        if(me[i]>mx){
            ll d =( me[i] - mx) / cells[mx];
            ans += d*2;
            me[i]-= d*cells[mx];
            if(me[i]>mx){
                me[i]-=cells[mx];
                ans+=2;
            }
        }
        ans += dp[me[i]];
    }
    cout << ans << endl;

}
	


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t=1; //cin>>t;
	while(t--)solve();
	return 0;
}