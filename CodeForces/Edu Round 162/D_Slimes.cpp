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


vl func(vl v,ll n){
     vl ps(n+1);
     vl ans(n,1e9);
     vl same(n+1);
     for(int i=0;i<n;i++){
        ps[i+1]=ps[i]+v[i];
     }
     same[n-1]=n;
     for(int i=n-2;i>=0;i--){
        if(v[i]==v[i+1]){
            same[i]=same[i+1];
        }else{
            same[i]=i+1;
        }
     }

     for(int i=0;i<n;i++){
        ll ind=lower_bound(all(ps),ps[i+1]+v[i]+1)-ps.begin();
        if(i+1<n and v[i]<v[i+1]){
            ans[i]=1;
            continue;
        }
        if(ind!=n+1){
            ll x=ind;
            if(same[i+1]==n) continue;
            ans[i]=max(ind,same[i+1]+1)-(i+1);
        }
     }
     return ans;
}

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     vl ans1=func(v,n);
     reverse(all(v));
     vl ans2=func(v,n);
     for(ll i=0;i<n;i++){
        ll x=min(ans1[i],ans2[n-i-1]);
        if(x==1e9) x=-1;
        cout<<x<<" ";
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