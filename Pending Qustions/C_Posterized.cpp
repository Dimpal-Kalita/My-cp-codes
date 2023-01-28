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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inp(v);
    //  sort(all(v));
    map<ll,ll> mp;

    

    for(int i=0;i<n;i++){
        int num= v[i];
        int cur=num;

        for(int j=v[i]; j>=max(v[i]-k+1, 0ll); j--){
            // cout<<j<<" ";
            cur=j;
            if(mp.count(j)){

                if(v[i]-mp[j]+1<=k){
                    cur=mp[j];
                    break;
                }
                else{
                    cur=j+1;
                    break;
                }

            }

        }

        for(int j=cur;j<=v[i];j++){
            mp[j]=cur;
        }

    }

    for(int i=0;i<n;i++){
        cout<<mp[v[i]]<<" ";
    }

}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}