#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull __int128_t
#define mini(a, b) a = min(a,b)
#define maxi(a, b) a = max(a,b)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define double long double

const ll MAXN = 2e5 + 5;
ll base = 37;
ll mod1 = 1e9+7;
ll mod2 = 1e9 +9;
ll mod = 1e9 +7;

ll pot[MAXN + 5][2];  

void hashi(string &s, ll hasha[][2]){
    hasha[0][1] = hasha[0][0]=0;
    for(int i=1;i<=s.size(); i++){
        hasha[i][0] = ((s[i-1]-'a'+1) + hasha[i-1][0]*base) % mod1;
        hasha[i][1] = ((s[i-1]-'a'+1) + hasha[i-1][1]*base) % mod2;
    }
}

ll subhash(ll hasha[][2], int l , int size, ll mod, int part){
    return ((hasha[l + size -1][part]-hasha[l-1][part] * pot[size][part]) % mod + mod) % mod;
}

pair<ll,ll> gethash(int l, int size, ll hasha[][2]){
    return {subhash(hasha, l, size, mod1, 0), subhash(hasha, l, size, mod2, 1) };
}

void init(){
    pot[0][1] = pot[0][0] = 1;
    for(int i=1; i<=MAXN; i++){
        pot[i][0] = (pot[i-1][0]*base) % mod1;
        pot[i][1] = (pot[i-1][1]*base) % mod2;
    }
}


void solve(){


}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1; cin>>t;
    while(t--) solve();
 
}