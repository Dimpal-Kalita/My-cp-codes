// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
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





/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/




typedef struct Node{
    ll val;
    string s;
}node;


ll N=1000;

vector<vector<ll>> mat(N, vector<ll>(N, 0));
vector<pll> worm_holes;
vector<ll> snakes;
vector<vector<ll>> vis(N, vector<ll>(N, 0));

ll row,col;




void dk(){

    ll y, x, n;
    cin>>y>>x>>n;
    snakes.resize(n);
    inp(snakes);    
    row=x,col=y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            string s;
            cin>>s;
            if(s=="*") {
                worm_holes.pb({i, j});
                mat[i][j]=1e9;
            }
            else{
                mat[i][j]=stoll(s);
            }
        }
    }

    // sort(all(snakes));
    map<ll,vector<string>>done;
    vector<vector<string>>ans;
    for(int i=0;i<x;i++){
        ll ct=1;
        ll mx=0;
        ll indy=0, indx=i;
        for(int j=0;j<y;j++){
            
            if(ct>mx){
                mx=ct;
                indy=j;
            }
            ct++;
            if(mat[i][j]==1e9 || mat[j][i]<0){
                ct=1;
            }
        }
          if(ct>mx){
                mx=ct;
                indy=y;
            }

        for(ll j=0;j<snakes.size();j++){
            if(done.count(j)) continue;
            if(mx>=snakes[j]){
                vector<string> t;
                t.pb(to_string(indy-mx+1));
                t.pb(to_string(i));
                for(int k=0;k<snakes[j]-1;k++){
                    t.pb("R");
                }
                ans.pb(t);
                done[j]=t;
                break;
            }
        }
    }

    for(ll i=0;i<n;i++){
        vector<string> it=done[i];
        for(int i=0;i<it.size();i++){
           cout<<it[i]<<" ";
        }
        cout<<endl;
    }

}




int main()
{ 
    fast_io;
    
    // #ifndef ONLINE_JUDGE
    // file_io;
    // freopen("D:/cp/error.txt", "w+", stderr);
    // #endif
    
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}