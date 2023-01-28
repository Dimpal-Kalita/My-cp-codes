// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


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


typedef struct node{
    set<int> st;
} node;

template <class T> struct SegTree {
    node dummy;
    const T ID = node(dummy);
    int n; vector <T> seg;
    T comb(T a, T b) {
      set<int> st;
      for(auto it:b.st){
        st.insert(it);
      }
      for(auto it:a.st){
        st.insert(it);
      }
      node val;
      val.st=st;
      return val;
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
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    inp(a);
    inp(b);
    SegTree<node> sg1(n+1), sg2(n+1);
    for(ll i=0;i<n;i++){
        node member;
        member.st.insert(a[i]);
        sg1.update(i,member);
    }
     for(ll i=0;i<n;i++){
        node member;
        member.st.insert(a[i]);
        sg2.update(i,member);
     }

     ll q;
     cin>>q;
     while(q--){
        ll u, v;
        cin>>u>>v;
        u--, v--;
        node st1, st2;
        st1= sg1.query(0,u);
        st2= sg2.query(0,v);
        if(st1.st==st2.st){
            cout<<"YES"<<endl;
            
        }
        else{   
            cout<<"NO"<<endl;
        }
     }


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