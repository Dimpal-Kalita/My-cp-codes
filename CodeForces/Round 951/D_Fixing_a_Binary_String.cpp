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

bool check(ll ind,ll k,string s){
     string a=s.substr(0,ind);
     reverse(all(a));
     string b=s.substr(ind);
     s=b+a;
     ll ct=1,cur=s[0];
     // cout<<s<<endl;
     rep(i,1,s.length()){
          if(cur==s[i]) ct++;
          else{
               if(ct!=k) return 0;
               ct=1;
               cur=s[i];
          }
     }
     return ct==k;
}
void dk(){
     ll n,k;
     cin>>n>>k;
     string s;
     cin>>s;
     set<int>st;
     st.insert(1);
     st.insert(k);
     st.insert(n);

     int ct=1,cur=s[0];
     for(int i=1;i<n;i++){
          if(s[i]==cur) ct++;
          else{
               if(ct!=k){
                    st.insert(i);
                    if(i-k>=0) st.insert(i-k);
               }
               ct=1;
               cur=s[i];
          }
     }
     if(st.size()>=6){
          cout<<"-1"<<endl;
          return;
     }
     for(auto i:st){
          if(check(i,k,s)){
               cout<<i<<endl;
               return;
          }
     }
     cout<<"-1"<<endl;
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