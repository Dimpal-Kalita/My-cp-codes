 /**
 *
 * author: Dimpal Kalita",
 *
 */
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


void dk(){
	ll n;
	cin>>n;
	string s="";



	while(n){
		if(n==7){
			n-=7;
			s+='8';
		}
		else if(n==5){
			n-=5;
			s+='2';
		}
		else if(n==4){
			n-=4;
			s+='4';
		}
		else if(n==3){
			n-=3;
			s+='7';
		}
		else if(n==2){
			n-=2;
			s+='1';
		}
		else {
			n-=6;
			s+='0';
		}
	}
	cout<<s<<endl;

}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}