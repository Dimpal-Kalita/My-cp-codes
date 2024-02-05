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
     ll n,k,m;
     cin>>n>>k>>m;
     string s;
     cin>>s;
     vl cnt(k+1,0);
     for(auto x:s){
          cnt[x-'a']++;
     }
     rep(i,0,k){
          if(cnt[i]<n){
               cout<<"NO"<<endl;
               cout<<string(n,i+'a')<<endl;
               return;
          }
     }
     cnt.assign(26,0);
     ll val=n;
     ll ct=0;
     set<ll>st;
     string ans="";
     rep(i,0,m){
          st.insert(s[i]-'a');
          if(st.size()==k){
               val--;
               st.clear();
               ans+=s[i];
          }
     }
     if(val<=0){
          cout<<"YES"<<endl;
     }
     else{
          cout<<"NO"<<endl;
          rep(i,0,k){
               if(!st.count(i)){
                    ans+=string(n-ans.length(),i+'a');
                    break;
               }
          }
          cout<<ans<<endl;
     }
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