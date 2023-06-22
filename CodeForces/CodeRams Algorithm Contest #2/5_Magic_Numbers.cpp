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


bool checkPal(string s){
     ll n=s.length();
     if(n%2) return 0;
     return s.substr(0,n/2)==s.substr(n/2);
}

bool ending(string s){
     ll n=s.length();
     if(n%2==0) return 0;
     return count(all(s),'9')==n;
}

ll calc(string s){
     ll val=0;
     reverse(all(s));
     for(int i=0;i<s.length();i++){
          val+= (s[i]-'0')*pow(10,i);
     }
     return val;
}
string makestring(ll x){
     string s="";
     while(x){
          s+='0';
          x--;
     }
     return s;
}


void dk(){
     ll n;
     cin>>n; 
     ll ct=0;
     // cout<<calc(to_string(n))<<endl;
     while(1){
          cerr<<n<<endl;
          string s=to_string(n);
          if(ending(s)){
               cout<<ct<<endl;
               return;
          }else if(checkPal(s)){
               string t=s.substr(0,s.length()/2);
               ct++;
               n=stoll(t);
          }
          else if(s.length()%2==0){
               string t=s.substr(0,s.length()/2);
               string tt= t+t;
               ll ff= calc(tt);
               if(n<ff){
                    ll k= ff-n+1;
                    ct+=k;
                    n=stoll(t);
               }
               else{
                    ll val= calc(t);
                    string temp=to_string(val+1)+makestring(s.length()/2);
                    ct+= calc(temp)-n;
                    string t2= to_string(val+1)+makestring(s.length()/2);
                    n=calc(t2);
               }
          }
          else{
               ct+=pow(10,s.length())-n-1;
               cout<<ct<<endl;
               return;
          }
     }
     cout<<ct<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}