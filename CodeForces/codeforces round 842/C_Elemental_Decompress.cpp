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






void dk(){
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);

     map<ll,ll> vis1, vis2;

     vector<pair<ll,ll>> vp(n+1, {-1, -1});

     vector<ll> v1(n, 0), v2(n, 0);

     
     for(ll i=0;i<n;i++){
        if(vp[v[i]].F==-1){
            v1[i]=v[i];
            vp[v[i]].F=i;
        }
        else if(vp[v[i]].S==-1) {
            v2[i]=v[i];
            vp[v[i]].S=i;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
     }
     
     set<ll> st1, st2;
     for(int i=1;i<=n;i++){
        if(vp[i].F==-1){
            st1.insert(i);
        }
        if(vp[i].S==-1){
            st2.insert(i);
        }
     }
     debug(v1)
     debug(st1)
     debug(st2)

     for(ll i=0;i<n;i++){

        if(v1[i]==0){

            auto it= st1.upper_bound(v2[i]);
            if(st1.size()==0 || it==st1.begin()){
                // cout<<i<<" ";
                // cout<<1<<endl;
                cout<<"NO"<<endl;
                return;
            }
            else{
                it--;
                v1[i]=*it;
                st1.erase(it);
            }
        
        }
        else{
         
            auto it= st2.upper_bound(v1[i]);
            if(st2.size()==0 || it==st2.begin()){
                cout<<"NO"<<endl;
                return;
            }
            else{
                it--;
                v2[i]=*it;
                st2.erase(it);
            }
        }
     }

    cout<<"YES"<<endl;
    for(auto x: v2) cout<<x<<" ";
    cout<<endl;
    for(auto x: v1) cout<<x<<" ";
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
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}