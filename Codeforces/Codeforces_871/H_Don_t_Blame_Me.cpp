#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
#define mini(a, b) a = min(a,b)
#define maxi(a, b) a = max(a,b)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define double long double
 
vector<pair<int,int>>moves = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};

pair<int,int>rot(pair<int,int>p, int n){
    return { n-1-p.second,p.first};
}

ll fast(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = ans*b;
        b = b*b;
        e>>=1;
    }
    return ans;
}

int arr[100000];


ll mod = 1e9+7;




void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << 6, 0));
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        for(ll mask = 0; mask < (1 << 6); ++mask) {
            dp[i][mask] += dp[i - 1][mask];
            if(dp[i][mask] >= mod) dp[i][mask] -= mod;
            dp[i][mask & a[i]] += dp[i - 1][mask];
            if(dp[i][mask & a[i]] >= mod) dp[i][mask & a[i]] -= mod;
        }
        dp[i][a[i]] = (dp[i][a[i]] + 1) % mod;
    }
    ll ans = 0;
    for(ll mask = 0; mask < (1 << 6); ++mask) {
        if(__builtin_popcount(mask) == x) {
            ans = (ans + dp[n][mask]) % mod;
        }
    }
    cout << ans << "\n";

}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
 
}