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
     ll n,k;
     cin>>n>>k;
     vl v(n);
     inp(v);
     vl h(n);
     inp(h);

     ll mx=0,ct=1,sum=v[0];
     if(sum<=k) mx=max(mx,ct);

     for(int i=1,j=0;i<n;i++){
          if(h[i-1]%h[i]==0){
               ct++;
               sum+=v[i];
               while(j<i and sum>k){
                    sum-=v[j];
                    ct--;
                    j++;
               }
          }else{
               ct=1;
               j=i;
               sum=v[i];
          }
          if(sum<=k) mx=max(mx,ct);
     }
     cout<<mx<<endl;
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