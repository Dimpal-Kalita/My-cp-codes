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
   cin >> n;
   vector<ll> v1(n), v2(n); 
   inp(v1);
   inp(v2);
   cin >> m;
   map<ll,ll> mp, ans;
   for(int i=0;i<m;i++){
        ll x;
        cin>>x;
        ans[x]++;
   }

   priority_queue<ll> pq;

   for(ll i=0;i<n;i++){

     while(!pq.empty() && -pq.top() < v2[i]){
        ll x = -pq.top();
        pq.pop();
        mp[x]++;
     }

     if(v1[i] > v2[i]){
        if(pq.empty()){
            pq.push(-v2[i]);
        }
        else if(-pq.top() > v2[i]){
            pq.push(-v2[i]);
        }
     }

     if(v1[i]  < v2[i]){
        cout << "NO" << endl;
        return;
     }

    }
 
    while(!pq.empty()){
        ll x = -pq.top();
        pq.pop();
        mp[x]++;
    }

    // for(int i=0;i<m;i++){

    //     if(ans[h[i]]<mp[h[i]]){
    //         cout<<"NO"<<endl;
    //         return;
    //     }

    // }

    for(auto it:mp){
        if(ans[it.F]<it.S){
            cout<<"NO"<<endl;
            return;
        }
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