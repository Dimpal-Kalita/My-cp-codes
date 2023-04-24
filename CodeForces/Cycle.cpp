// Problem: C. Cycle
// URL: https://codeforces.com/problemset/problem/117/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Author: Dimpal Kalita
// 17-04-2023 21:44:59

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

const int N=5005;
string s[N];
vector<bool> vis(N);
vector<array<int,3>>ans;
int n;

bool dfs(int node, int par){
	
	vis[node]=1;
	
	bool ret=0;
	for(int child=0;child<n;child++){
		if(s[node][child]=='1'){
			if(par<=5000 and s[child][par]=='1'){
				ans.pb({par+1,node+1,child+1});
				return 1;
			}		
			if(!vis[child]) ret|=dfs(child,node);
		}
	}
	
	return ret;
}

void dk(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	for(int i=0;i<n;i++){
		if(!vis[i] and dfs(i,N-1)) break;
	}
	
	if(ans.size()) cout<<ans[0][0]<<" "<<ans[0][1]<<" "<<ans[0][2]<<endl;
	else cout<<-1<<endl;

}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}