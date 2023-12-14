/**
 * 
 * author: Dimpal Kalita
 * date: 09/12/2023 20:16:40
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


bool is_Palidrome(vector<ll>v){
    int n=sz(v);
    for(int i=0;i<n/2;i++){
        if(v[i]!=v[n-i-1]) return false;
    }
    return true;
}
void dk(){
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    iota(all(v),1);
    do{
        if(v[0]!=x) continue;
        vector<ll>dif;
        for(int i=0;i<n-1;i++){
            dif.pb(v[i+1]-v[i]);
        }
        if(is_Palidrome(dif)){
            for(auto i:v) cout<<i<<" ";
            cout<<endl;
        }
    }while(next_permutation(all(v)));
}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}