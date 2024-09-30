#pragma GCC optimize("O3")
#include<bits/stdc++.h>
 
using namespace std;

#define ll long long int
#define double long double
#define endl '\n'

class SuffixAutomaton {
public:
    struct State {
        int len, link;
        map<char, int> next;  
    };

    vector<State> st;
    int last;
    int size;


    SuffixAutomaton(int maxLen) {
        st.resize(2 * maxLen);
        st[0].len = 0;
        st[0].link = -1;
        size = 1;
        last = 0;
    }

    void extend(char c) {
        int cur = size++;
        st[cur].len = st[last].len + 1;

        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = size++;
                st[clone] = st[q]; 
                st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }


    void build(const string &s) {
        for (char c : s) {
            extend(c);
        }
    }

};

void solve(){
	SuffixAutomaton st(1e5);
	string s; cin>>s;
	for(auto e: s){
		st.extend(e);
	}


}
	
 
 
int main() {
  	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
	int t=1; //cin>>t;
	while(t--)solve();
	return 0;
}