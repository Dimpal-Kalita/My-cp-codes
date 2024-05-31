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
     string s;
     cin>>s;
     string title="",domain="";
     ll ind=0;
     while(ind<sz(s) and s[ind]!='@'){
          title+=s[ind];
          ind++;
     }
     if(ind==sz(s)){
          cout<<"no"<<endl;
          return;
     }
     domain=s.substr(ind+1);
     if(domain!="odoo.com"){
          cout<<"no"<<endl;
          return;
     }
     if(sz(title)==2 or sz(title)==3 or sz(title)==4){
          for(auto i:title){
               if(i>='a' and i<= 'z') continue;
               cout<<"no"<<endl;
               return;
          }
          cout<<"yes"<<endl;
          return;
     }else{
          cout<<"no"<<endl;
          return;
     }
     // cout<<title<<" "<<domain<<endl;
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