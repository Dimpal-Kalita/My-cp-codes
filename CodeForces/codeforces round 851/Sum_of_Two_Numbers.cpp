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
      string s= to_string(n);
      ll v1=0, v2=0;
      string a1="", a2="";
      for(int i=0;i<s.length();i++){
            ll x= s[i]-'0';
            if(x%2==1){
                if(v1>v2){
                    v1+=x/2;
                    v2+=x/2+1;
                    a1+= (x/2+'0');
                    a2+= (x/2+1+'0');
                }
                else{
                     v1+=x/2+1;
                     v2+=x/2;
                     a1+= (x/2+1+'0');
                     a2+= (x/2+'0');
                }
            }
            else{
                     v1+=x/2;
                     v2+=x/2;
                     a1+= (x/2+'0');
                     a2+= (x/2+'0');
            }

      }

      reverse(all(a1));
      while(a1.back()=='0' && a1.size()>1) a1.pop_back();
      reverse(all(a1));

      reverse(all(a2));
      while(a2.back()=='0' && a2.size()>1) a2.pop_back();
      reverse(all(a2));

      cout<<a1<<" "<<a2<<endl;
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