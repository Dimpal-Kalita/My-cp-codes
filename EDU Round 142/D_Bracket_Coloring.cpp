/**
 * 
 * author: Dimpal Kalita
 * date: 25/05/2023 20:59:18
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


void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     if(n%2 || count(all(s),'(')!= count(all(s),')')){
          cout<<-1<<endl;
          return;
     }

     stack<pair<char,int>> st,st2;
     vector<ll> col(n,0);
     ll t1=0,ans=0;
     if(s[0]=='('){
          for(int i=0;i<n;i++){
               if(s[i]=='('){
                    st.push({'(',i});
               }
               else{
                    if(st.empty()){
                         if(s[i]==')'){
                              st2.push({')',i});
                         }       
                    }
                    else{
                         col[i]=1;
                         col[st.top().S]=1;
                         t1=1;
                         st.pop();
                    }
               }
          }
     }else{
          for(int i=0;i<n;i++){
               if(s[i]==')'){
                    st.push({')',i});
               }
               else{
                    if(st.empty()){
                         if(s[i]=='('){
                              st2.push({'(',i});
                         }       
                    }
                    else{
                         col[i]=1;
                         col[st.top().S]=1;
                         t1=1;
                         st.pop();
                    }
               }
          }

     }
     while(!st2.empty() and !st.empty()){
          col[st2.top().S]=2;
          col[st.top().S]=2;
          st2.pop();
          st.pop();
     }
     ll cnt=count(all(col),2);
     if(cnt==0 || cnt==n){
          cout<<1<<endl;
          for(auto x: col){
               cout<<1<<" ";
          }
          cout<<endl;
          return;
     }
     cout<<2<<endl;
     for(auto x: col){
          cout<<x<<" ";
     }
     cout<<endl;
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