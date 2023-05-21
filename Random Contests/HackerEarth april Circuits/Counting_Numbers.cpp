/**
 * 
 * author: Dimpal Kalita
 * date: 30/04/2023 15:29:10
 * 
 */

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


vector<vector<vector<vl>>> dp;

auto reset(){
     dp.clear();
     dp.resize(20, vector{20, vector<vl>(2,vector<ll>(2,-1))});
}

ll recur(ll c, ll x=0, ll y=-1,ll leading_zero=1, ll z=0){
 
    
    if(x==to_string(c).length()) return 1;
    if(y!=-1 and dp[x][y][leading_zero][z]!=-1) return dp[x][y][leading_zero][z];
 
    ll limit=9;
    if(!z){
        limit=to_string(c)[x]-'0';
    }
 
    ll val=0;
    
    rep(i,0,limit+1){
        if(i==y and i!=0) continue;
        if(i==y and i==0  and leading_zero==0) continue;
        val+= (z?recur(c,x+1,i,(leading_zero&i)!=0,z):recur(c,x+1,i,(leading_zero&i)!=0,i<limit));
    }
 
    if(y==-1) return val;
    return dp[x][y][leading_zero][z]=val;
}

void dk(){
    ll a,b;
    cin>>a>>b;
    reset();
    ll x=recur(a-1);
    reset();
    cout<<recur(b)-x<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}