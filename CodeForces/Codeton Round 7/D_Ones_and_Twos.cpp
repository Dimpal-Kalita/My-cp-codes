#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
     ll n,q;
     cin>>n>>q;
     vl v(n);
     ll ct=0;
     ll sum=0;
     set<ll>st;
     for(int i=0;i<n;i++){
          cin>>v[i];
          if(v[i]==1){
               ct++;
               st.insert(i);
          }
          sum+=v[i];
     }
     while(q--){
          ll t;
          cin>>t;
          if(t==1){
               ll x;
               cin>>x;
               if((ct==0 and x%2==1)|| x>sum){
                    cout<<"NO"<<endl;    
                    continue;
               }
               if(v[0]==1 || v[n-1]==1 || ct==0){
                    cout<<"YES"<<endl;
                    continue;
               }

               ll mn=*st.begin();
               ll mx=*st.rbegin(); 
               ll ind=min(mn,n-mx-1);
               if((sum-x)%2==0){
                    cout<<"YES"<<endl;
                    continue;
               }
               ll temp=(sum-x-1)/2+1;

               if(temp<=ind){
                    cout<<"NO"<<endl;
               }else{
                    cout<<"YES"<<endl;
               }

          }else{
               ll ind,x;
               cin>>ind>>x;
               ind--;
               sum-=v[ind];

               if(v[ind]==1){
                    ct--;
                    st.erase(ind);
               }
               v[ind]=x;
               if(v[ind]==1){
                    ct++;
                    st.insert(ind);
               }
               sum+=x;

          }
     } 

}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   