#include <bits/stdc++.h>
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int mp[2005][2005];
int x[2005];
int y[2005];
void solve()
{
	ms(mp,0);
	ms(x,0);
	ms(y,0);
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		x[a]=1;
		y[b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i]==0||y[i]==0)
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	solve();
	}
}