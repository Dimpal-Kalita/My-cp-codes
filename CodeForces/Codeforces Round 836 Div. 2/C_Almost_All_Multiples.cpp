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
const int MX= 2e5+7;

int vec[MX+1];
void calc(){
    for(int i=0;i<=MX; i++) vec[i]=-1; 
    for(int i=2;i<=MX;i++){
        if(vec[i]!=-1)continue;
        for(int j=i;j<=MX;j+=i){
            if(vec[j]==-1){
                vec[j]=i;
            }
     }
    }
}


void dk(){

    ll n, x;
    cin>>n>>x;
    vector<ll> ans(n+1, -1);
    ans[1]=x;
    ans[n]=x;
    vector<int>vp;
    vp.push_back(x);
    while(x!=n){
       int num = n/x;
       int k = x*vec[num];
       vp.push_back(k);
       x = k;
    }
    vector<int>vis(n+1,0);

    for(int i=1;i<vp.size();i++){
        ans[vp[i-1]] = vp[i];
        vis[vp[i-1]] = 1;
    }

    for(int i=2;i<n;i++){
        if(!vis[i]) ans[i]=i;
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
      
      


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
    calc();
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}