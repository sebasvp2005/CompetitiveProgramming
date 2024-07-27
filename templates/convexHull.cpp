#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define ll long long int
#define endl '\n'

int cross(point o, point a, point b){
    return  ((a.first - o.first) * (b.second - o.second)) - ((a.second - o.second) * (b.first - o.first));
}

vector<point> convexHull( vector<point> points){
    int n = points.size();
    if( n<3) return points;

    sort(points.begin(), points.end());

    vector<point> hull;

    for(int i=0;i<n; i++){
        while(hull.size()>=2 and cross(hull[hull.size()-2], hull.back(), points[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    for(int i=n-2, t=hull.size()+1; i>=0; i--){
        while(hull.size()>=t and cross(hull[hull.size()-2], hull.back(), points[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

double dist(point a, point b){
    return 1.0 * ((b.first - a.first) * (b.first-a.first) + (b.second-a.second) * (b.second - a.second));
}

void solve(){
    int n;cin>>n;
    vector<point>points;

    map<point, int> m;
    for(int i=0; i<n; i++){
        int x,y;cin>>x>>y;
        if(m.find({x,y})==m.end()){
            m[{x,y}]=i;
            points.push_back({x,y});
        }
    }

    vector<point> ans = convexHull(points);
    double dis = 0.0;

    for(int i=1; i<ans.size(); i++){
        dis += sqrt(dist(ans[i-1], ans[i]));
    }
    dis += sqrt(dist(ans.back(), ans.front()));
    


    cout << fixed << setprecision(2) << dis << endl;
    auto tar = ans[0];
    int it = 0;
    for(int i=0;i<ans.size(); i++){
        if(ans[i].second<tar.second){ tar = ans[i]; it = i;}
        else if (ans[i].second==tar.second and ans[i].first < tar.first) { tar = ans[i]; it = i;}
    }
    for(int i=0;i<ans.size(); i++) cout << m[ans[(i+it)%ans.size()]]+1 << " ";
    cout << endl << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;cin>>t;
    while(t--) solve();
}
