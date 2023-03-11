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





ll lcm(ll x, ll y){
    return (x*y)/__gcd(x,y);
}

void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     ll x= count(all(s), '+');
     ll y= count(all(s), '-');
     if(y>x) swap(x,y);

     ll q;
     cin>>q;


     while(q--){
        ll l,r;
        cin>>l>>r;
        if(r>l) swap(l,r);
        ll lc= lcm(l,r);

        if(x==y){
            cout<<"YES"<<endl;
        }
        else if(x==0 || y==0){
            cout<<"NO"<<endl;
        }
        else if(l==r && x!=y){
            cout<<"NO"<<endl;
        }
        else if(abs(l*y-r*x)%abs(lc*r-1)==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
     }   
      


}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}