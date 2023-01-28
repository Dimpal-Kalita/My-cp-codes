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
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);

     vector<ll> index(n+1);

     for(int i=0;i<n;i++){
        index[v[i]]=i;
     }

     if(n%2){

        ll lval= (n+1)/2, rval=(n+1)/2;
        ll ans=0;
        ll l= index[lval], r=index[rval];
        ll ansl=0, ansr=0;

        if(l<=r){

            while(l>=0){
                if(v[l]==lval){
                    lval--;
                    ansl++;
                }
                l--;
            }
        
            while(r<n){
                if(v[r]==rval){
                    rval++;
                    ansr++;
                }
                r++;
            }

        }

        // cout<<ans<<" ";
        cout<<(n+1)/2-min(ansl, ansr)<<endl;
        return;
     }

        ll lval= (n)/2, rval=(n)/2+1;
        ll ans=0;
        ll l= index[lval], r=index[rval];
        ll ansl=0, ansr=0;
        if(l<r){
            while(l>=0){
                if(v[l]==lval){
                    lval--;
                    ansl++;
                }
                l--;
            }
            while(r<n){
                if(v[r]==rval){
                    rval++;
                    ansr++;
                }
                r++;
            }
        }
        // cout<<ans<<" ";
        cout<<n/2-min(ansl, ansr)<<endl;


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