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


void solve(){
    int n,m; cin>>n>>m;
    vector<int>deg(n);
    for(int i=0;i<m; i++){
        int a,b;cin >>a>>b;
        deg[a-1]++;
        deg[b-1]++;
    }

    map<int,int>ma;
    for(int i=0;i<n; i++){
        if(deg[i]!=1){
            ma[deg[i]]++;
        }
    }

    if(ma.size()==1){
        int a  = (*ma.begin()).first;
        cout << a << " " << a-1 << endl;
        return;
    }

    auto e = ma.begin();
    auto a = *e;
    e++;
    auto b = *e;
    if(a.second>b.second){
        cout << b.first << " " << a.first-1 << endl;
    }
    else cout << a.first << " " << b.first-1 << endl;

    


}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
 
}