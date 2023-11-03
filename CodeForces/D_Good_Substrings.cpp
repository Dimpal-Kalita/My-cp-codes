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




ll expo(ll b, ll e){
     ll ans=1;
     for(;e;e/=2, b=(b*b)%md){
          if(e&2) ans=(ans*b)%md;
     }
     return ans;
}

ll modinv(ll x){
     return expo(x,md-2);
}


void dk(){
     string s;
     cin>>s;
     int n=sz(s);
     string t;
     cin>>t;
     ll k;
     cin>>k;


     vector<ll>hash(n+1);
     const int P=31;
     ll mul=1;
     for(int i=0;i<n;i++){
          hash[i+1]=(hash[i]+s[i]*mul)%md;
          mul=(mul*P)%md;
     }

     auto get_hash=[&](ll l,ll r){
          ll ans=(hash[r]-hash[l]+md)%md;
          ans=(ans*modinv(expo(mul,l)))%md;
          return ans;
     };

     vector<vl>ps(n+1,vl(26,0));
     for(int i=0;i<n;i++){
          for(int j=0;j<26;j++){
               ps[i+1][j]=ps[i][j];
          }
          ps[i+1][s[i]-'a']++;
     }

     set<string>st;
     ll ans=0;
     for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
               int cnt=0;
               for(int k=0;k<26;k++){
                    ll ct=ps[j+1][k]-ps[i][k];
                    if(t[k]=='1') cnt+=ct;
               }
               string tt="";
               for(int k=i;k<=j;k++) tt+=s[k];
               if(cnt<=k){
                    ll h=get_hash(i,j+1);
                    st.insert(tt);
               }
          }
     }
     cout<<st.size()<<endl;
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