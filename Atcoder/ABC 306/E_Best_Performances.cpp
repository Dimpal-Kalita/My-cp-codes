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


void dk(){
      ll n,k,q;
      cin>>n>>k>>q;
      vector<ll> v(n,0);

      map<ll,ll> mp;
      mp[0]+=(n-k);
      multiset<ll>st;
      priority_queue<ll>pq;
      rep(i,0,k) st.insert(0);
      rep(i,0,n-k) pq.push(0);


      ll ans=0;
      while(q--){
          ll ind,x;
          cin>>ind>>x;
          ind--;
          mp[v[ind]]--;

          if(st.find(v[ind])!=st.end()){
               st.erase(st.lower_bound(v[ind]));
               mp[x]++;
               pq.push(x);
               while(!pq.empty() and mp[pq.top()]==0) pq.pop();
               ll mx=pq.top();
               pq.pop();
               st.insert(mx);
               ans-=v[ind];
               ans+=mx;
               mp[mx]--;
               // cout<<pq.size()<<" ";
          }else{
               // cout<<1<<" ";
               pq.push(x);
               while(!pq.empty() and mp[pq.top()]==0) pq.pop();
               ll mx=pq.top();
               ll small= *st.begin();
               if(small<mx){
                    st.erase(st.lower_bound(small));
                    mp[small]++;
                    st.insert(mx);
                    mp[mx]--;
                    pq.pop();
                    ans-=small;
                    ans+=mx;
               }
          }
          v[ind]=x;
          // rep(i,0,n) cerr<<v[i]<<" ";
          // cerr<<endl;
          cout<<ans<<endl;
      }
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