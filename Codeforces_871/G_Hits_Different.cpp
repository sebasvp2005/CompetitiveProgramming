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


ll sum[2001][2001];

void init(){
    int level=1;
    ll cur = 1;
    while(cur <= 1e6){
        for(int i=1; i<=level; i++){
            sum[level][i] = sum[level][i-1] + cur*cur;
            cur++;
        }
        level++;
    }
}


void solve(){
    int n; cin>>n;
    int it = 1;
    while(it*(it+1)/2 < n) it++;
    int prev = it-1;
    int cur = 1;
    ll ans=0;
    ll spaces = n - prev * (prev+1)/2  - 1; 
    //cout << it << endl;
    while(it){
        //cout << sum[it][spaces + cur] << " " << sum[it][spaces] << endl;;
        //cout << spaces << " " << cur << endl;
        ans += sum[it][spaces + cur] - sum[it][spaces];
        if(spaces==0 or spaces + cur == it){}
        else cur++;
        spaces--;
        it--;
        spaces = max(0ll, spaces);
        cur = min(it, cur);
    }
    cout << ans << endl;



}
 
int main(){
    init();
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
 
}