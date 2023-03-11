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




void dk(){
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);

     deque<ll> q;
     for(auto it:v) q.push_back(it);
     string ans="";
     map<deque<ll>,ll> mp;

     while(!is_sorted(all(q))){
        mp[q]++;
        ll f=q.front();
        q.pop_front();
        ll s=q.front();
        q.pop_front();
        if(s==q.back()+1) {
            ans+="S";
            q.push_front(f);
            q.push_back(s);
            ans+="P";
        }
        else if(f==q.back()+1){
            q.push_front(s);
            q.push_back(f);
            ans+="P";          
        }
        else if(f>s) {
            q.push_front(f);
            q.push_front(s);
            ans+="S";
        }
        else{
            q.push_front(s);
            q.push_back(f);
            ans+="P";
        }

        if(mp[q]>0){
            ll f=q.front();
            q.pop_front();
            ll s=q.front();
            q.pop_front();
            q.push_back(s);
            q.push_back(f);
            ans+="SPP";
        }

     }

     if(ans.size()==0){
        cout<<"empty"<<endl;
        return;
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