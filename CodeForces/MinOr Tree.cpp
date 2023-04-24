// Problem: G. MinOr Tree
// URL: https://codeforces.com/problemset/problem/1624/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author: Dimpal Kalita
// 18-04-2023 01:02:20

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;



struct DSU {
    vector<int> s;
    DSU(int n): s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;x    
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};

int n,m;

bool check(vector<pll>&v){
	DSU dsu(n+1);
	for(auto it:v){
		if(!dsu.same(it.F,it.S)){
			dsu.join(it.F,it.S);
		}
	}
	return dsu.size(1)==n;
}

void dk(){
	cin>>n>>m;
	vector<pair<ll,pll>>v(m);
	for(auto &it:v) cin>>it.S.F>>it.S.S>>it.F;
	
	map<pair<ll,pll>,ll>vis;
	ll ans=0;
	
	
	for(int i=29;i>=0;i--){
			
		vector<pll>vp;
		for(auto it:v){
			if(!vis[it] and !((1<<i)&it.F)){
				vp.pb({it.S.F,it.S.S});
			}
		}
		
		if(check(vp)){
			for(auto it:v){
				if(((1<<i)&it.F)){
					vis[it]++;
				}
			}
		}
		else{
			ans|=(1<<i);
		}
		
	}
	
	cout<<ans<<endl;

}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}