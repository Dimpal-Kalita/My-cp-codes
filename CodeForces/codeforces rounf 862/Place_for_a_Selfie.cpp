// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               ((long long)((x).size()));
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key




void dk(){
     ll n, m;
     cin>>n>>m;
     vector<ll> v(n);
     inp(v);
     sort(all(v));

     while(m--){
        lld a,b,c;
        cin>>a>>b>>c;
        if(a*c<0){
            cout<<"NO"<<endl;
            continue;
        }
        lld x= b- 2*sqrtl(a*c);
        lld y= b+ 2*sqrtl(a*c);

        ll ind= upper_bound(all(v),x)-v.begin();

        // cout<<x<<" "<<y<<endl;
        bool flag=0;
        for(int i=ind-1;i<=ind+1;i++){
            if(i<n && i>=0 && v[i]<y && v[i]>x){
                cout<<"YES"<<endl;
                cout<<v[i]<<endl;
                flag=1;  
                break;             
            }
        }
        if(flag) continue;
        flag=0;
        ind= lower_bound(all(v),y)-v.begin();
        for(int i=ind-1;i<=ind+1;i++){
            if(i<n && i>=0 && v[i]>x && v[i]<y){
                cout<<"YES"<<endl;
                cout<<v[i]<<endl;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        cout<<"NO"<<endl;
     } 
      


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