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
     ull a,b,c,d,e,f;
     cin>>a>>b>>c>>d>>e>>f;

     ull ster=((d-a)*(d-a))+((e-b)*(e-b))+((f-c)*(f-c)), steps=0;

     for(ll i=0;i<=71;i++){
        ull x=(3*b)+c;
        ull y=a/2;
        ull z=b/2;
        // cout<<x<<" "<<y<<" "<<z<<endl;
        ull er=((d-x)*(d-x))+((e-y)*(e-y))+((f-z)*(f-z));
        if(er<0 || er>1e17) break;
        if(er<ster){
            ster=er;
            steps=i+1;
        }
        a=x,b=y,c=z;
     }

     cout<<ster<<" "<<steps<<endl;
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