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
     ll n,m;
     cin>>n>>m;
     vector<ll> v(n);
     inp(v);
     vector<ll> ps(n, 0); 
     ps[0]=v[0];
     
     for(ll i=1;i<n;i++){
        ps[i]=ps[i-1]+v[i];
     }

     if(n==1){
        cout<<0<<endl;
        return;
     }

     ll ans=0;
     ll sum=0, sum2=0;
     ll extra=0;
     priority_queue<ll> pq;

     for(ll i=m-1;i>=0;i--){
        if(v[i]>0){
            pq.push(v[i]);
        }
        sum2+=v[i];
        while(sum2>0){
            if(i==0) break;
            sum2-=2*pq.top();
            pq.pop();
            ans++;
        }
     }

     while(!pq.empty()) pq.pop();

     for(ll i=m;i<n;i++){
        if(v[i]<0){
            pq.push(-v[i]);
        }

        sum+=v[i];
        while(sum<0){
            sum+=2*pq.top();
            pq.pop();
            ans++;
        }

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
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}