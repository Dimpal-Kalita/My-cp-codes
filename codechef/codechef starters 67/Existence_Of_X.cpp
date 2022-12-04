// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


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
     ll a, b, c;
     cin>>a>>b>>c;
     ll ans=0;
     ll carry=0;
     for(ll i=0;i<28;i++){
        int x=((1ll<<i)&a)?1:0;
        int y=((1ll<<i)&b)?1:0;
        int z=((1ll<<i)&c)?1:0;

        if((x^y^carry)==z){
            carry=(x+y+carry)>1?1:0;
        }
        else if((x^y^carry)==(z^1)){
            carry=((x^1)+(y^1)+carry)>1?1:0;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
        // cout<<carry<<" ";
     }
    //  cout<<carry<<" ";
     if(carry>0){
        cout<<"NO"<<endl;
        return;
     }
     cout<<"YES"<<endl;
     return;
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