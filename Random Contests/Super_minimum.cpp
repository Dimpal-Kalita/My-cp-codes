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
     ll n,k;
     cin>>n>>k;
     vl v(n);
     inp(v);
     list<int>list;
     for(int i=0;i<k;i++){
           while(!list.empty() && v[list.back()]>=v[i]){
                list.pop_back();
           }
           list.push_back(i);
     }
     for(int i=k,j=0;i<n;i++,j++){
           cout<<v[list.front()]<<" ";
           while(!list.empty() && list.front()<=j){
                list.pop_front();
           }
           while(!list.empty() && v[list.back()]>=v[i]){
                list.pop_back();
           }
           list.push_back(i);
     }
     cout<<v[list.front()]<<" ";
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