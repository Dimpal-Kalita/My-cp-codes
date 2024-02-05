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

bool isVowel(char a){
     if(a=='a'|| a=='e' || a=='i' || a=='o' || a=='u') return 1;
     return 0;
}

void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     string ans="";
     for(int i=n-1;i>=0;i--){
          if(isVowel(s[i])){
               ans+=".";
               ans+=s[i];
               ans+=s[i-1];
               i--;
          }else{
               ans+=".";
               ans+=s[i];
               ans+=s[i-1];
               ans+=s[i-2];
               i-=2;
          }
     }
     reverse(all(ans));
     ans.pop_back();
     cout<<ans<<endl;
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