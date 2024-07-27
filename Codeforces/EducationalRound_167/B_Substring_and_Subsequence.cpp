#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;


void solve(){
    string a,b; cin>>a>>b;
    int ans = 1e9;
    for(int i=0; i<b.size(); i++){
        int r =i;
        int count=0;
        int j=0;
        for(j =0 ;j<a.size() and r<b.size(); j++){
            if(a[j] == b[r]) r++;
            else{
                count++;
            }
        }

        count+= a.size() - j;
        ans = min(ans, count);
    }
    cout << ans  + b.size() << endl;

}
	


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t=1; cin>>t;
	while(t--)solve();
	return 0;
}