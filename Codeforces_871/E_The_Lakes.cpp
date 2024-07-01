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
    int n,m;cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>>v(n, vector<bool>(m));
    ll ans=0;
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){

            if(v[i][j] or arr[i][j]==0)continue;

            queue<pair<int,int>>q;
            q.push({i,j});
            v[i][j]=1;
            ll cur =0 ;
            while (q.size())
            {
                auto [y,x] = q.front();q.pop();

                cur += arr[y][x];

                for(auto [dy, dx]: moves){
                    int ny =  y +dy;
                    int nx = x + dx;

                    if(ny>=0 and ny < n and nx>=0 and nx < m){
                        if(v[ny][nx] or arr[ny][nx]==0)continue;
                        v[ny][nx]=1;
                        q.push({ny, nx});
                    }
                }

            }
            ans = max(ans, cur);
            
        }
    }

    cout << ans << endl;


}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
 
}