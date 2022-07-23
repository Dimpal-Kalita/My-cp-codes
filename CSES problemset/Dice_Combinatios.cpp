#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define md                  1000000007;
using namespace std;

int main()
{
ll n,m;
cin>>m>>n;
vector<ll> v1;
v1.resize(m);
for(auto &x:v1) cin>>x;
vector<ll> dp(n+1,0);
sort(v1.begin(), v1.end());
dp[0]=1;
for ( ll j = 1; j <= n; j++)
{
    for (auto x: v1)
    {
        if(x>j) break;
        dp[j]=(dp[j]+dp[j-x])%md;
    }
}

cout<<dp[n]%md;
return 0;
}