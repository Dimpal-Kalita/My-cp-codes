/**
 * 
 * author: Dimpal Kalita
 * 
 */

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


bool first(int n,string s){
     string ans="";
     for(int i=0;i<n;i++){
          ans+='(';
     }
     for(int i=0;i<n;i++){
          ans+=')';
     }
     for(int i=0;i<2*n;i++){
          if(ans.substr(i,n)==s) return 0;
     }
     cout<<"YES"<<endl;
     cout<<ans<<endl;
     return 1;
}
bool second(int n,string s){
     string ans="";
     for(int i=0;i<n;i++){
          ans+="()";
     }
     for(int i=0;i<2*n;i++){
          if(ans.substr(i,n)==s) return 0;
     }
     cout<<"YES"<<endl;
     cout<<ans<<endl;
     return 1;
}
void dk(){
     string s;
     cin>>s;
     int n=s.length();
     if(first(n,s) || second(n,s)){
          return;
     }
     cout<<"NO"<<endl;
     return;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}