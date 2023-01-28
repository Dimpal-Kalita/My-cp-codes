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









vector<vector<ll>> subsets(vector<ll>& arr) {
    vector<vector<ll>> res;
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++) {
        vector<ll> subset;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                subset.pb(arr[j]);
        res.pb(subset);
    }
    return res;
}

ll calc(ll n, ll r){
    vector<ll> v;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) v.pb(i);
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        v.pb(n);
    }
    vector<vector<ll>> sub= subsets(v);
    map<ll,ll> mp;
    for(auto it: sub){

        ll mul=1;
        for(auto i:it){
            mul*=i;
        }
       if(it.size()>0) mp[it.size()]+= r/mul;
    }

    debug(mp)
    ll ans=r;
    ll ind=0;
    for(auto it:mp){
        if(ind%2==0){
            ans-= it.S;
        }else{
            ans+= it.S;
        }
        ind++;
    }
    return ans;
}




ll solve(ll a, ll l, ll r){
    return (calc(a, r)- calc(a,l-1));
}

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a,b);
}

void dk(){
     ll a, b, l, r;
     cin>>a>>b>>l>>r;
     ll g= lcm(a, b);
    //  cout<<solve(b, l, r)<<endl;
     cout<<solve(a,l,r)+solve(b,l,r)-solve(g,l,r)<<endl; 
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