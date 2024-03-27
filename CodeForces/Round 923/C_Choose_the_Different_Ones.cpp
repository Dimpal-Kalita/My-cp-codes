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
     ll n,m,k;
     cin>>n>>m>>k;
     vl a(n),b(m);
     inp(a); 
     inp(b);
     map<ll,ll>mpa,mpb;
     rep(i,0,n) mpa[a[i]]++;
     rep(i,0,m) mpb[b[i]]++;
     ll ak=0,bk=0;
     rep(i,1,k+1){
          if(mpb[i]==0 and mpa[i]==0){
               cout<<"NO"<<endl;
               return;
          }
          if(mpb[i]==0) ak++;
          else if(mpa[i]==0) bk++;
     }
     if(ak>k/2 or bk>k/2){
          cout<<"NO"<<endl;
          return;
     }
     cout<<"YES"<<endl;

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