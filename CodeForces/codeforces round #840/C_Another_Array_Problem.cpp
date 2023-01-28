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
    ll n;
    cin>>n;
    vector<ll> v(n);
    inp(v);

    ll mx= *max_element(all(v));
    if(n>3){
        cout<<mx*n<<endl;
        return;
    }

    if(n==2){
        cout<<max(v[0]+v[1], 2*abs(v[0]-v[1]))<<endl;        
        return;
    }

    if(v[0]==mx || v[2]==mx){
        cout<<3*mx<<endl;
        return;
    }

    ll ans=max(3*abs(v[0]-v[1]), max(3*abs(v[0]-v[2]), 3*abs(v[1]-v[2])));
    ans=max(3*v[0], max(ans, 3*v[2]));
    cout<<max(ans, v[0]+v[1]+v[2])<<endl;
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