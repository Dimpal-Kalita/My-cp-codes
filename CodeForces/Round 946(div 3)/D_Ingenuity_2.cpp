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


void dk(){
     ll N;
     cin>>N;
     string S;
     cin>>S;
     ll e=0,w=0,n=0,s=0;
     for(auto i:S){
          if(i=='E') e++;
          else if(i=='W') w++;
          else if(i=='N') n++;
          else s++;
     } 
     if((e-w)%2 or (n-s)%2){
          cout<<"NO"<<endl;
          return;
     }
     string ans=S;
     ll cte=0,ctw=0,ctn=0,cts=0;
     rep(i,0,N){
          if(S[i]=='E'){
               if(cte<e/2) ans[i]='H',cte++;
               else ans[i]='R';
          }
          if(S[i]=='W'){
               if(ctw<w/2) ans[i]='H',ctw++;
               else ans[i]='R';
          }
          if(S[i]=='N'){
               if(ctn<n/2) ans[i]='R',ctn++;
               else ans[i]='H';
          }
          if(S[i]=='S'){
               if(cts<s/2) ans[i]='R',cts++;
               else ans[i]='H';
          }
     }
     // cout<<ans<<endl;
     ll ct=count(all(ans),'H');
     if(ct==0 or ct==N){
          cout<<"NO"<<endl;
          return;
     }
     cout<<ans<<endl;
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