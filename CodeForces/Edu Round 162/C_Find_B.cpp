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
     ll n,q;
     cin>>n>>q;
     vl v(n);
     vl ps(n+1);
     vl ss(n+1);
     rep(i,0,n){
        cin>>v[i];
        ps[i+1]=ps[i];
        ss[i+1]=ss[i];
        if(v[i]==1) ps[i+1]++;
        else ss[i+1]+=v[i];
     }
     while(q--){
        ll l,r;
        cin>>l>>r;
        ll sum=ss[r]-ss[l-1];
        ll cnt=ps[r]-ps[l-1];
        ll len=r-l+1;
        ll extra=len-cnt;
        if(cnt>(sum-extra) || len==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
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