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
    ll mex=0;
    for(int i=0;i<n+2;i++){
        if(!mp.count(i)) {
            mex=i;
            break;
        }
    }

    
    if(mex==0){
        cout<<"Yes"<<endl;
        return;
    }

    ll left=0, right=0;
    for(int i=0;i<n;i++){
        if(v[i]==mex+1){
            left=i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(v[i]==mex+1){
            right=i;
            break;
        }
    }

    for(int i=left+1;i<right;i++){
        if(v[i]<mex and mp[v[i]]==1){
            cout<<"No"<<endl;
            return;
        }
        mp[v[i]]--;
    }

    if(n>mex) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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