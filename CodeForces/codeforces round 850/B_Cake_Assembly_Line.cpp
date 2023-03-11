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
     ll n,w, h;
     cin>>n>>w>>h;
     vector<ll> a(n);
     vector<ll> b(n);
     inp(a);
     inp(b);
     for(ll i=1;i<n;i++){
        a[i]-=a[0];
        b[i]-=b[0];
     }
     a[0]=0;
     b[0]=0;
     ll val1=0, val2=0;
     ll leftmax=0, rightmax=0;
     for(ll i=0;i<n;i++){
        ll l1= a[i]-w, r1= a[i]+w;
        ll l= b[i]-h,r= b[i]+h;
        rightmax= max(r-r1, rightmax);
        leftmax= max(l1-l, leftmax);
     }
     if(leftmax>0 && rightmax>0){
         cout<<"NO"<<endl;
         return;
     }
     for(int i=0;i<n;i++){
        ll l1= a[i]-w, r1= a[i]+w;
        ll l= b[i]-h,r= b[i]+h;
        if(abs(r-r1)<leftmax || abs(l1-l)<rightmax){
            cout<<"NO"<<endl;
            return;
        }
     }
     cout<<"YES"<<endl;
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