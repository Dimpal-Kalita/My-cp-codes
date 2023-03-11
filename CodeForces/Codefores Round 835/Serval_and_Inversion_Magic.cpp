// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define sz(x)               int((x).size())
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key








void dk(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll i=0, j=n-1;
    vector<ll> v,vp;
    while(i<j){
        if(s[i]!=s[j]) v.pb(0);
        else v.pb(1);
        i++, j--; 
    }

    for(int i=0;i<sz(v)-1;i++){
        if(v[i]==v[i+1]) continue;
        else{
            vp.pb(v[i]);
        }
    }
    vp.pb(v[sz(v)-1]);

    ll ct=0;
    for(int i=0;i<sz(vp)-2;i++){
        if(vp[i]==0 && vp[i+1]==1 && vp[i+2]==0){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;

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