#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
#define mini(a, b) a = min(a,b)
#define maxi(a, b) a = max(a,b)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define double long double
 
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


void solve(){

    int n;cin>>n;
    map<int,int>m;
    m[1]=1e9;
    m[0]=1e9;
    m[11]=1e9;
    m[10]=1e9;
    for(int i=0;i<n; i++){
        int a, b;cin>>a>>b;
        if(b==0)continue;
        m[b] = min(a, m[b]);
    }
    int ans = 1e9;
    ans = min(ans, m[11]);
    ans  = min(ans ,  m[10] + m[1]);
    if(ans ==1e9) cout << -1 ;
    else cout << ans ;
    cout << endl;
    


}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
 
}