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
     ll n;
     cin>>n;
     string s;
     cin>>s;
     vector<ll>vis(26,0),v(n,0);
     for(int i=0;i<n;i++){
          vis[s[i]-'a']=max(vis[s[i]-'a'],1LL);
          for(int j=s[i]-'a'+1;j<26;j++){
               vis[s[i]-'a']=max(vis[s[i]-'a'],vis[j]+1);
          }
          v[i]=vis[s[i]-'a'];
     }
     ll mx=*max_element(all(v));
     if(mx>2){
          cout<<"NO"<<endl;
          return;
     }
     cout<<"YES"<<endl;
     for(auto &it:v) cout<<(--it);
     cout<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   