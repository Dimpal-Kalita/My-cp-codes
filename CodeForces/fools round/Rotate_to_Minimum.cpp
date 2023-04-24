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
     ll n, p, q;
     cin>>n>>p>>q;

     string s;
     cin>>s;
     string ans="";
     for(int i=0;i<n;i++){
        ll x= min(p, 26ll);
        ll y= min(q, 26ll);

        ll ch1=s[i]-'a';
        while(ch1>0 && x>0){
            ch1++;
            ch1%=26;
            x--;
        }

        ll ch2=s[i]-'a';
        while(ch2>0 && y>0){
            ch2--;
            ch2 = (ch2+26)%26;
            y--;
         }
        if(ch1<ch2){
            ans+=char(ch1+'a');
            ll val=min(p,26ll);
            val-=x;
            p-=val;
        }
        else{
            ans+=char(ch2+'a');
            ll val=min(q,26ll);
            val-=y;
            q-=val;
        }

     }
     cout<<ans<<endl;

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