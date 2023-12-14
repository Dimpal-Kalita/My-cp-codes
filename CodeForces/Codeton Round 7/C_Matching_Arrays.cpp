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
     ll n,x;
     cin>>n>>x;
     vl a(n),b(n);
     inp(a);
     inp(b);
     map<ll,set<ll>>ind;
     rep(i,0,n){
          ind[a[i]].insert(i);
     }
     vl v=a;
     vl t=b;
     sort(all(v));
     sort(all(t));
     ll last=1;
     vl ans(n);
     ll X=x;
     rotate(t.begin(),t.begin()+x,t.end());
     for(int i=0;i<n;i++){
          ll temp=*ind[v[i]].begin();
          ind[v[i]].erase(ind[v[i]].begin());
          ans[temp]=t[i];
     }
     ll ct=0;
     for(int i=0;i<n;i++){
          if(a[i]>ans[i]) ct++;
     }
     if(ct!=X){
          cout<<"NO"<<endl;
          return;
     }
     cout<<"YES"<<endl;
     for(auto i:ans){
          cout<<i<<" ";
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