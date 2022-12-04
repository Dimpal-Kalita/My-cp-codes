// 2112048
// Dimpal Kalita
// CSE sec A

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
    

    vector<ll> v1, v2;
    set<ll> st;
    
    for(ll i=0;i<n;i++){
            ll ct1=0, ct2=0;
            while(v[i]%2==0){
                v[i]/=2;
                ct1++;
            }
            while(v[i]%3==0){
                v[i]/=3;
                ct2++;
            }
            v1.pb(ct1);
            v2.pb(ct2);
            st.insert(v[i]);
    }
    if(st.size()>1){
        cout<<-1<<endl;
        return;
    }

    ll ans=0;
    sort(all(v1));
    sort(all(v2));

    for(ll i=0;i<n;i++){
        ans+= v1[i]-v1[0];
        ans+= v2[i]-v2[0];
    }

    cout<<ans<<endl;
      
}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    //cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}