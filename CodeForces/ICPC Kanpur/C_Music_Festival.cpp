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
#define sz(x)               int((x).size());
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


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






struct BIT{
    vector<ll>bit;
    ll n;
    BIT(ll n){
        this->n=n;
        bit.assign(n+1,0);
    }
    ll sum(ll r){
        ll ret=0;
        for(;r;r-=r&-r) ret=max(ret,bit[r]);
        return ret;
    }
    void add(ll idx,ll delta){
        for(;idx<=n;idx+=idx&-idx) bit[idx]=max(bit[idx],delta);
    }
};



bool comp(const vector<ll>&a,const vector<ll>&b){
    return a.back()<b.back();
}

void dk(){
     ll n;
     cin>>n;
     ll val=0;
     vector<vector<ll>>v(n);

     map<ll,ll> mp;
     for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ll first;
        cin>>first;
        v[i].pb(first);
        for(int j=1;j<x;j++){
            ll y;
            cin>>y;
            if(y>v[i].back()) v[i].pb(y);
        }
     }


     for(auto it:v){
        for(auto it1:it){
            mp[it1]++;
        }
     }

     sort(all(v), comp);
    //  debug(v);

     int cur=1;

     for(auto &it:mp){
        it.S=cur;
        cur++;
     }


     for(auto &it:v){
        for(auto &it1:it){
            it1=mp[it1];
        }
     }


     BIT bit(cur+100);
     ll ans=0;
     ll prev=0;

     for(auto it:v){
        ll mx=0;
        for(ll i=0;i<it.size();i++){
            ll x= bit.sum(it[i]-1);
            mx= max(mx, x+(ll)it.size()-i);
        }
        bit.add(it.back(),mx);
     }
     

     cout<<bit.sum(cur+10)<<endl;

}




int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}