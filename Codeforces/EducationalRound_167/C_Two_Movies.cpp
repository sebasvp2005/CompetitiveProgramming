#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;


void solve(){

    int n; cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i< n; i++) cin>>arr[i].first;
    for(int i=0;i< n; i++) cin>>arr[i].second;

    vector<pair<int,int>> temp;

    int aa[2] = {0 ,0};
    for(int i=0;i < n; i++){
        if(arr[i].first == arr[i].second and arr[i].first!=0){
            temp.push_back(arr[i]);
            continue;
        }
        if(arr[i].first > arr[i].second){
            aa[0]+=arr[i].first;
        }else{
            aa[1]+=arr[i].second;
        }
    }
    sort(aa,aa+2);
    for(auto e: temp){
        if(e.first < 0){
            aa[1]--;

        }else{
            aa[0]++;
        }
        sort(aa , aa+2);
    }
    cout << aa[0] << endl;


}
	


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t=1; cin>>t;
	while(t--)solve();
	return 0;
}