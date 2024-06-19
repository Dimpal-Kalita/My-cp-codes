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

ll stl(string s){
     reverse(all(s));
     ll x=0;
     for(auto c: s){
          x=x*10+(c-'0');
     }
     return x;
}

void dk(){
     string s;
     cin>>s;
     reverse(all(s));
     ll n=sz(s);
     ll carry=0;
     string a="",b=""; 
     for(int i=0;i<n-1;i++){
          int x=s[i]-'0';
          x-=carry;
          for(int j=5;j<=9;j++){
               bool flag=0;
               for(int k=5;k<=9;k++){
                    if((j+k)%10==x){
                         a+=to_string(j);
                         b+=to_string(k);
                         carry=1;
                         flag=1;
                         break;
                    }
               }
               if(flag) break;
          }
     }
     // cout<<a<<" "<<b<<endl;
     ll xa=stl(a),xb=stl(b);
     ll t=stl(s);
     // cout<<xa<<" "<<xb<<" "<<t<<endl;
     if(xa+xb==t){
          cout<<"YES"<<endl;
     }
     else cout<<"NO"<<endl;
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