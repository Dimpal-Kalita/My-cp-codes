#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
 
 
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
 
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define endl                  " \n"
/// --------------------------------------------------------------------------------------------------------- ///
 
/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/// --------------------------------------------------------------------------------------------------------- ///
 
 
 
 
 
const ll N=INT_MAX;
ll ans=N;
ll n,m;
string str="";
vector<vector<ll>> dp(1100,vector<ll>(1100,N));
vector<vector<ll>> vis(1110,vector<ll>(1110,0));
 

 
void solve(){
    cin>>n>>m;
    ll ax=-1,ay=-1,bx=-1,by=-1;
    vector<vector<char>> v(n,vector<char>(m));
    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                ax=i;
                ay=j;
            }
            if(v[i][j]=='B'){
                bx=i;
                by=j;
            }
        }
    }

    queue<pll> q;
    q.push({bx,by});
    dp[bx][by]=0;
    vis[bx][by]=1;
    while(!q.empty()){
        ll x=q.front().ff;
        ll y=q.front().ss;
        q.pop();
        if(x+1<n && vis[x+1][y]==0 && v[x+1][y]!='#'){
            vis[x+1][y]=1;
            dp[x+1][y]=min(dp[x+1][y],dp[x][y]+1);
            q.push({x+1,y});
        }
        if(x-1>=0 && vis[x-1][y]==0 && v[x-1][y]!='#'){
            vis[x-1][y]=1;
            dp[x-1][y]=min(dp[x-1][y],dp[x][y]+1);
            q.push({x-1,y});
        }
        if(y+1<m && vis[x][y+1]==0 && v[x][y+1]!='#'){
            vis[x][y+1]=1;
            dp[x][y+1]=min(dp[x][y+1],dp[x][y]+1);
            q.push({x,y+1});
        }
        if(y-1>=0 && vis[x][y-1]==0 && v[x][y-1]!='#'){
            vis[x][y-1]=1;
            dp[x][y-1]=min(dp[x][y-1],dp[x][y]+1);
            q.push({x,y-1});
        }
    }



    string temp="";
    // cerr<<bx<<" "<<by<<endl;

    
    if(dp[ax][ay]==N){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<dp[ax][ay]<<endl;
 
        int x=ax,y=ay;
        while(temp.size()<dp[ax][ay]){
            //cerr<<x<<" "<<y<<endl;
            if(x==bx && y==by){
                break;
            }
            if(x+1<n && dp[x+1][y]==dp[x][y]-1){
                temp+='D';
                x++;
            }else if(x-1>=0 && dp[x-1][y]==dp[x][y]-1){
                temp+='U';
                x--;
            }else if(y+1<m && dp[x][y+1]==dp[x][y]-1){
                temp+='R';
                y++;
            }else if(y-1>=0 && dp[x][y-1]==dp[x][y]-1){
                temp+='L';
                y--;
            }
        }
        cout<<temp<<endl;
    }
 
}
 
 
int main(){
 
fast_io;
 
ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}