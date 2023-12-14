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
     ll ans=0;
     map<char,int>mp;
     for(int i=0;i<n;i++){
         mp[s[i]]++;
     }
     priority_queue<int>pq;
     for(auto x:mp){
         pq.push(x.S);
     }
     while(pq.size()>1){
          int x=pq.top();
          pq.pop();
          int y=pq.top();
          pq.pop();
          x--,y--;
          if(x) pq.push(x);
          if(y) pq.push(y);
     }
     if(pq.empty()) cout<<0<<endl;
     else cout<<pq.top()<<endl;
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