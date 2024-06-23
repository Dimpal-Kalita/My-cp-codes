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



string uppercase(string s){
    for(int i=0;i<sz(s);i++){
        if(s[i]>='a' && s[i]<='z'){
            s[i]-=32;
        }
    }
    return s;
}
string lowercase(string s){
    for(int i=0;i<sz(s);i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]+=32;
        }
    }
    return s;
}

void dk(){
      string s;
      cin>>s;
      ll u=0,l=0;
      for(int i=0;i<sz(s);i++){
          if(s[i]>='a' && s[i]<='z'){
              l++;
          }else u++;
      }
      if(u>l){
          cout<<uppercase(s)<<endl;
      }else cout<<lowercase(s)<<endl;
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