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
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);

     ll sum= *max_element(all(v))- *min_element(all(v)); 

     vector<ll> pos, neg;
     for(auto it:v){
        if(it>=0){
            pos.pb(it);
        }
        else{
            neg.pb(it);
        }
     }
    //  if(pos.size()==n){
    //     cout<<"No"<<endl;
    //     return;
    //  }
    //  cout<<"Yes"<<endl;

    vector<ll> ans;

     sort(all(pos));
     sort(all(neg), greater<ll>());

     int i=0, j=0;
     ll mx=0;
     for(ll ind=0;ind<n;ind++){
        if(i<pos.size() && mx+pos[i]<sum){
            ans.pb(pos[i]);
            mx+=pos[i];
            i++;
        }
        else{

            if(j>=neg.size()){
                cout<<"No"<<endl;
                return;
            }
            ans.pb(neg[j]);
            mx=max(mx+neg[j], 0ll);
            // cout<<neg[j]<<" ";
            j++;
        }

        mx= max(mx, 0ll);
        ll tmp = mx;
        if(mx< 0){
            tmp = -sum;
        }

        if(mx>sum){
            cout<<"No"<<endl;
            return;
        }



     }


    cout<<"Yes"<<endl;


    for(auto it:ans){
        cout<<it<<" ";
    }

     cout<<endl;



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