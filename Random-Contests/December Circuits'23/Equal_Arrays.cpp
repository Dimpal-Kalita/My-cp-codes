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
     ll n,m;
     cin>>n>>m;
     vl a(n),b(m);
     inp(a);
     inp(b);
     if(accumulate(all(a),0)!=accumulate(all(b),0)){
          cout<<-1<<endl;
          return;
     }
     ll length=0;
     for(ll i=0,j=0;i<n && j<m;){
          ll suma=a[i],sumb=b[j];
          while(suma!=sumb and i<n and j<m){
               if(suma<sumb){
                    i++;
                    suma+=a[i];
               }
               else{
                    j++;
                    sumb+=b[j];
               }
          }
          if(suma==sumb){
               length++;
               i++;
               j++;
          }
     }
     cout<<length<<endl;
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