#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%lld\n",x)

#define pb                  push_back
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define dsort(a)            sort(a,a+n,greater<int>())
#define pn                  printf("\n")
#define debug               printf("I am here\n")
#define ps                  printf(" ")
//ll  pow_calc(ll x, ll e){ ll res;  if (e == 0) res = 1; else if (e == 1) res = x; 
// else { res = bigpow(x, e / 2);  res = res * res;  if (e % 2) res = res * x; } return res; }
//ll find_all_divisor(ll n){  fr1(i,sqrt(n)){     ll i,x;  if(n % i == 0)  { x = n / i; v.pb(i);  if(i != x) v.pb(x);}}}
ll m,n,p,x,y,a,b;
vector<ll> edges[1000005];
bool vis[500005];
ll ar[1000005];
ll br[1000005];
ll cr[1000005];
int main()
{ int t;
scl(t);
while(t--){
cin>>n>>m;
if(n%2==0)
{
    if(m%n==0)
    {
        cout<<n<<endl;
    }
    else
    {
        cout<<m%n<<endl;
    }
}
else
{
            int md=n/2;
            int ad=((m-1)/md);
            m+=ad;
            cout<<((m-1+n)%n)+1<<"\n";
     
}


}




 return 0;
}