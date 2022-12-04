// 2112048
// Dimpal Kalita
// CSE sec A

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
     ll  n, l;
     cin>>n>>l;
     vector<ll> v(n);
     inp(v);
     ll sum1=0, sum2=0;
     ll ind=1, last=0;
     for(ll i=0;i<n;i++){
        // cout<<ind<<" ";
        if(ind==l-1){
            last = i+1;
            break;
        }
        if(ind > l-1){
            last = i;
            break;
        }

        if(v[i]==1) ind+=2;
        if(v[i]==2) ind+=3;


     }
     //cout<<last<<" ";
     for(int i = last ; i < n ; i ++){
        if(v[i] == 2){
            cout << "No" << endl;
            return;
        }
     }

     cout<<"Yes"<<endl;
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