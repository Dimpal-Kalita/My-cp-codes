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
     stack<char>st;
     reverse(all(s));
     for(auto i:s){
          st.push(i);
          while(st.size()>=3){
              char ff=st.top();
              st.pop();
              char ss=st.top();
              st.pop();
              char th=st.top();
              st.pop();
              if(ff=='A' and ss=='B' and th=='C'){

              }else{
               st.push(th);
               st.push(ss);
               st.push(ff);
               break;
              }
          }
     }
     // cout<<st.size()<<endl;
     string ans="";
     while(!st.empty()){
          ans+=st.top();
          st.pop();
     }
     cout<<ans<<endl;
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