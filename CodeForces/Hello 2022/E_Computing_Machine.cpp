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
     auto check=[&](string x,string y)->ll{
          int n=x.size();
          for(int i=0;i<n-2;i++){
               if(x[i]=='0' and x[i+2]=='0') y[i+1]='1';
          }
          for(int i=0;i<n-2;i++){
               if(y[i]=='1' and y[i+2]=='1') x[i+1]='1';
          }

          int cnt=0;
          for(int i=0;i<n;i++) cnt+=(x[i]=='1');

          return cnt;
     };
     ll n;
     cin>>n;
     string s,t;
     string a,b; 
     cin>>s>>t;
     a=s,b=t;
     for(int i=0;i<n-2;i++){
          if(a[i]=='0' and a[i+2]=='0') b[i+1]='1';
     }
     for(int i=0;i<n-2;i++){
          if(b[i]=='1' and b[i+2]=='1') a[i+1]='1';
     }
     vl cnt(n+1);
     for(int i=0;i<n;i++){
          cnt[i+1]+=(cnt[i]+(a[i]=='1'));
     }
     // debug(cnt);
     auto get_cnt=[&](ll l,ll r)->ll{
          return cnt[r+1]-cnt[l];
     };

     auto get_answer=[&](ll l,ll r)->ll{
          ll ans=0;
          ans+=get_cnt(l+2,r-2);
          ans+=(s[l]=='1');
          ans+=(s[r]=='1');
          if(t[l]=='1' and t[l+2]=='1') ans++;
          if(t[r]=='1' and t[r-2]=='1') ans++;
          return ans;   
     };
     ll q;
     cin>>q;
     while(q--){
          ll l,r;
          cin>>l>>r;
          l--,r--;
          if(r-l+1<=5){
               string x=s.substr(l,r-l+1);
               string y=t.substr(l,r-l+1);
               cout<<check(x,y)<<endl;
               continue;
          }
          cout<<get_answer(l,r)<<endl;
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