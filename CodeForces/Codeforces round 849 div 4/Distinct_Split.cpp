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
     vector<vector<ll>>ss(n+1, vector<ll>(26, 0)), ps(n+1, vector<ll>(26, 0));

     for(int i=n-1;i>=0;i--){
        ss[i]=ss[i+1];
        ss[i][s[i]-'a']++;
     }
     ll ans=0;
     for(int i=1;i<=n;i++){
        ps[i]=ps[i-1];
        ps[i][s[i-1]-'a']++;
        ll ct1=0, ct2=0;
        for(int j=0;j<26;j++){
           if(ps[i][j]>0) ct1++;
           if(ss[i][j]>0) ct2++;
        }
        ans=max(ans, ct1+ct2);
     }
     cout<<ans<<endl;

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