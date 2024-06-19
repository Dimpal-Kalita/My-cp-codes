#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif




void dk(){
     ll n;
     cin>>n;
     vl a(n),b(n);
     inp(a);
     inp(b);
     vl prev(n+1,-1),next(n+1,-1);
     set<ll>st;  // that are going to die next round     
     rep(i,0,n){
          ll x=(i+1<n?a[i+1]:0)+(i-1>=0?a[i-1]:0);
          if(x>b[i]){
               st.insert(i);
          }
          if(i+1<n) next[i]=i+1;
          if(i-1>=0) prev[i]=i-1;
     }

     for(int k=0;k<n;k++){
          set<ll>check;
          cout<<st.size()<<" ";
          for(auto i:st){
               ll x=prev[i],y=next[i];
               if(x!=-1){
                    next[x]=y;
                    check.insert(x);
               }
               if(y!=-1){
                    prev[y]=x;
                    check.insert(y);
               }

          }
          set<ll>nst;
          for(auto i:check){
               if(st.count(i)) continue;
               ll x=(prev[i]!=-1?a[prev[i]]:0)+(next[i]!=-1?a[next[i]]:0);
               if(x>b[i]){
                    nst.insert(i);
               }
          }
          st=nst;
     }
     cout<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   