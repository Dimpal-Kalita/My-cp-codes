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

vi pi(const string& s) {
     vi p(sz(s));
     rep(i, 1, sz(s)) {
          int g = p[i - 1];
          while (g && s[i] != s[g]) g = p[g - 1];
          p[i] = g + (s[i] == s[g]);
     }
     return p;
}
vi match(const string& s, const string& pat) {
     vi p = pi(pat + '\0' + s), res;
     rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat))
          res.push_back(i - 2 * sz(pat));
     return res;
}

void dk(){
     string s;
     cin>>s;
     string t;
     cin>>t;
     vi v=match(s,t);
     cout<<sz(v)<<endl;
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