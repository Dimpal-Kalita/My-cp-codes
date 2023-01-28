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



template <class T> struct SegTree {
    const T ID = 0;
    int n; vector <T> seg;
    T comb(T a, T b) {
      return __gcd(a, b);
    }
    SegTree(int _n) { n = _n; seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void update(int idx, T val) {
        seg[idx += n] = val;
        for (idx /= 2; idx; idx /= 2) pull(idx);
    }
    T query(int l, int r) {
        T lnode = ID, rnode = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) lnode = comb(lnode, seg[l ++]);
            if (r & 1) rnode = comb(seg[-- r], rnode);
        }
        return comb(lnode, rnode);
    }
};


void dk(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    SegTree<ll> seg(n+1);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        seg.update(i, v[i]);
    }

    ll ans=0;
    ll l=0, r=0;    
    while(l<n &&  r<n){
        ll val= seg.query(l, r);
        if(val>=k){
            ans= max(ans, r-l+1);
            r++;
        }
        else l++;
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
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}