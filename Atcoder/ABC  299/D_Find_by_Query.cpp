#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
// #define endl                " \n"
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



ll ask(ll n){
    cout<<"? "<<n<<endl;
    ll x;
    cin>>x;
    return x;
}

void dk(){
    ll n;
    cin>>n;

    map<ll,ll> mp;
    ll l=1, r=n+1;
    while(l<r){
        ll mid= (l+r)/2;
        ll x= ask(mid);
        mp[mid]=x;

        if(mp.count(mid+1) and mp[mid+1]!=mp[mid]){
            cout<<"! "<<mid<<endl;
            return;
        }
        if(mp.count(mid-1) and mp[mid-1]!=mp[mid]){
            cout<<"! "<<mid-1<<endl;
            return;
        }
        if(x==0){
            l=mid+1;
        }else{
            r=mid;
        }
    }

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