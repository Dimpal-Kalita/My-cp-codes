// 2112048
// Dimpal Kalita

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

using pii = pair<int,int>;
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using vl  = vector<ll>;



void dk(){
    ll n;
    cin>>n;
    vl v(n);
    map<ll,ll> mp;
    for(auto &it:v){
        cin>>it;
        mp[it]++;
    }
    ll mx=*max_element(all(v));
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        if(v[i]==mx){
            ans=n-i;
            break;
        }
    }

    cout<<(mp[mx]==1?ans:ans-1)<<endl;
}


int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}