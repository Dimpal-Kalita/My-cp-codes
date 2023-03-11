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



vector<pair<ll,vector<pll>>> Gensubarrays(vector<ll> v){

      vector<pair<ll,vector<pll>>> ans;
      for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            vector<pll> subarray;
            for (int k = i; k <= j; k++) {
                subarray.push_back({v[k], k+1});
            }
            ll sum=0;
            for(auto it:subarray) sum+=it.F;
            ans.pb({sum, subarray});
        }
    }
    return ans;
}

ll query(vector<pll> v1, vector<pll> v2){
    cout<<"WEIGH"<<endl;
    cout.flush();
    cout<<1<<endl;
    cout.flush();
    cout<<0<<endl;
    cout.flush();
    cout<<v2.size()<<endl;
    cout.flush();
    for(auto x: v2){
        cout<<x.S<<" ";
        cout.flush();
    }
    cout<<endl;
    string s;
    cin>>s;
    if(s=="=") return 0;
    if(s=="<") return -1;
    if(s==">") return 1;
    return 2;
}


vector<ll> v={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
vector<pair<ll,vector<pll>>> sub=Gensubarrays(v);
void dk(){
    cout<<15<<endl;
    cout.flush();
    for(auto it:v){
        cout<<it<<" ";
        cout.flush();
    }
    cout<<endl;
    cout.flush();
    cout<<25<<endl;
    cout.flush();
    vector<pair<ll,vector<pll>>> sub=Gensubarrays(v);
    sort(all(sub));
    ll ans=0;
    ll l=0,r=sub.size()-1;
    while(l<r){
        ll mid=(l+r)/2;
        ll q=query({{0,0}}, sub[mid+1].S);
        if(q==0){
            cout<<"VERDICT"<<endl;
            cout.flush();
            cout<<"EXACT"<<endl;
            cout.flush();
            cout<<sub[mid+1].F<<endl;
            cout.flush();
            string s;
            cin>>s;
            return;
        }
        if(q==1 && sub[mid+1].F>15){
                cout<<"VERDICT"<<endl;
                cout.flush();
                cout<<"HEAVY"<<endl;
                cout.flush();
        }
        if(q==2){
            return;
        }
        if(q==-1) r=mid;
        else l=mid+1;
    }

    cout<<"VERDICT"<<endl;
    cout.flush();
    cout<<"HEAVY"<<endl;
    cout.flush();

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