// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key




void dk(){
     vector<ll> a(4, 0);
     inp(a);
     ll sum= accumulate(all(a), 0ll);
     ll alice=0, bob=0;
     alice+=a[0], bob+=a[0];
     ll ans=a[0];

     if(alice>0){

        ll x=min(a[1], a[2]);
        a[1]-=x;
        a[2]-=x;
        ans+=2*x;
        
        ll y= min(bob, a[1]);
        bob-=y;
        a[1]-=y;
        ans+=y;
        
        ll z= min(alice, a[2]);
        alice-=z;
        a[2]-=z;
        ans+=z;
     }

     ll u= min(a[3], min(alice, bob));
     ans+=u;
     cout<<min(sum,ans+1)<<endl;
}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}