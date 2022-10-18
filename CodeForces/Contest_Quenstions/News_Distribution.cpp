#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%lld\n",x)
#define md                  10000007
#define pb                  push_back
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define pn                  printf("\n")
#define debug               printf("I am here\n")
#define ps                  printf(" ")
//ll  pow_calc(ll x, ll e){ ll res;  if (e == 0) res = 1; else if (e == 1) res = x; 
// else { res = bigpow(x, e / 2);  res = res * res;  if (e % 2) res = res * x; } return res; }
//ll find_all_divisor(ll n){  fr1(i,sqrt(n)){     ll i,x;  if(n % i == 0)  { x = n / i; v.pb(i);  if(i != x) v.pb(x);}}}
ll m,n,p,x,y;
vector<ll> edges[1000005];
bool vis[500005];
ll a[1000005];
ll b[1000005];
ll c[1000005];
int main()
{
    cin>>n>>m;
    fr(i,m){
        cin>>p;
        vector<ll>v;
        fr(j,p){
            cin>>v[j];
            --v[j];     
             }
         fr(j,p){
           edges[v[j]].pb(v[j+1]);
           edges[v[j+1]].pb(v[j]);
        }
        }
fr(i,n)
{
    if(!vis[i])
    {
        vector<ll>component;
        queue<ll>q;
        while (!q.empty())
        {
           x=q.front();
           q.pop();
           if(vis[x]) continue;
           vis[x]=1;
           component.pb(x);
        for(ll y: edges[x])
        {
             if(!vis[y])
             {
                 q.push(y);
             }
        }
               
           }
           for(ll x:component)
           a[x]=component.size();
        }
        fr(i,n)
        {
            cout<<a[i]<<" ";
        }

    }

    
   return 0;
}