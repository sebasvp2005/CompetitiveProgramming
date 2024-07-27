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

    int n, k; cin>>n>>k;
    queue<int>q;
    q.push(n);
    while(q.size()){
        int cur = q.front();q.pop();
        if(cur == k){
            cout << "YES\n";
            return;
        }
        if(cur%3)continue;
        q.push(cur/3 * 2);
        q.push(cur/3);
    }
    cout << "NO\n";


}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
 
}