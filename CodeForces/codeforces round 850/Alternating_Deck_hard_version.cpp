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
     ll ans1=1, ans2=0;
     bool val=1;
     ll x=2;
     pair<ll,ll> l={1,0}, r={0,0};
     while(ans1+ans2<n){
            if(val==0){
                 ll temp=ans1;
                 if(n-ans1-ans2>=x){
                    ans1+=x;
                    x++;
                }else if(n-ans1-ans2>0){
                    ans1+=n-ans1-ans2;
                    x++;
                }
                
                if(n-ans1-ans2>=x){
                    ans1+=x;
                    x++;
                }else if(n-ans1-ans2>0){
                    ans1+=n-ans1-ans2;
                    x++;
                }
                temp= ans1-temp;
                l.F+=(temp+1)/2;
                l.S+=temp/2;
            }
            else{
                ll temp=ans2;
                if(n-ans1-ans2>=x){
                    ans2+=x;
                    x++;
                }else if(n-ans1-ans2>0){
                    ans2+=n-ans1-ans2;
                    x++;
                } 
                if(n-ans1-ans2>=x){
                    ans2+=x;
                    x++;
                }else if(n-ans1-ans2>0){
                    ans2+=n-ans1-ans2;
                    x++;
                }
                temp= ans2-temp;
                r.F+=(temp)/2;
                r.S+=(temp+1)/2;
            }
            val=!val;
     }
     
     cout<<l.F<<" "<<l.S<<" "<<r.F<<" "<<r.S<<endl;


}




int main()
{ 

  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}