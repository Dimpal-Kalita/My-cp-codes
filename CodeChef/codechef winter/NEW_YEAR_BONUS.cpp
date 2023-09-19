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






void dfs(int s, vector<vector<int> > g,
         int p, int d, int& ans,
         vector<int>& count)
{
    for (int i : g[s]) {

        if (i != p) {
            ans += d;
            dfs(i, g, s, d + 1,
                ans, count);
            count[s] = count[s] + count[i];
        }
    }
}
 
// Function to find the distances from
// every other node using distance from
// node 0
void dfs2(int s, vector<vector<int> > g,
          int p, vector<ll>& pd_all,
          int n, vector<int> count)
{
    for (int i : g[s]) {
 
        // If i is not equal to the
        // parent p
        if (i != p) {
            pd_all[i] = pd_all[s]
                        - count[i]
                        + n - count[i];
            dfs2(i, g, s, pd_all,
                 n, count);
        }
    }
}
 


void dk(){
     int n;
     cin>> n;
     vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int N=n;
    vector<int> count(N, 1);
    int pd_0 = 0;
    dfs(0, g, -1, 1, pd_0, count);
    vector<ll> pd_all(N, 0);
    pd_all[0] = pd_0;

    dfs2(0, g, -1, pd_all, N, count);
    
    ll ans=0;
    sort(all(pd_all));
    lld mn= pd_all[0];
    lld mx= pd_all.back();
    lld avg= (mx+mn)/2;

    for(auto it:pd_all){
        if(it<avg){
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