#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll mod = 1e9+7;

struct fract{
    ll num, den;
    fract(ll num , ll den){
        this->num = num;
        this->den = den;
    }
    fract(){this->num=0; this->den=1;}
    fract simplify(){
        ll g = __gcd(this->den, this->num);
        this->den/=g;
        this->num/=g;
        return *this;
    }
    fract operator+(const fract b){
        ll a = this->num * b.den;
        ll bb = b.num * this->den;
        ll c = b.den * this->den;
        a += bb;
        return fract(a, c).simplify();
    }
    fract operator-(const fract b){
        ll a = this->num * b.den;
        ll bb = b.num * this->den;
        ll c = b.den * this->den;
        a -= bb;
        return fract(a, c).simplify();
    }
    fract operator*(const fract b){
        ll a = this->num * b.num;
        ll bb = this->den * b.den;
        return fract(a, bb).simplify();
    }
    void operator=(const fract b){
        this->num = b.num;
        this->den = b.den;
    }
};


void solve(){


}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
 
	int t=1;// cin>>t;
	while(t--)solve();
	return 0;
}