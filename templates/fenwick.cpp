#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll mod = 1e9+7;



struct fenwick
{
    int size ;
    vector<ll>tree;
    fenwick(int n){
        size = n+5;
        tree = vector<ll> (n+5);
    }
    void add(int x, int v){
        for(; x<=size; x+=x&-x) tree[x]+=v;
    }
    ll sum(int x){
        ll s=0;
        for(; x>0; x-=x&-x)s+=tree[x];
        return s;
    }
};



void solve(){

}
	
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t=1; //cin>>t;
	while(t--)solve();
	return 0;
}

/*
	You should read all the statement
	If you dont know what do to,then you havent understand the problem
*/