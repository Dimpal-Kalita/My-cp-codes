#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
ll t;
cin>>t;
while(t--)
{
ll n;
cin>>n;
ll arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
ll s=arr[0];
for (int i = 1; i < n; i++)
{
    s=s|arr[i];
}
cout<<s<<endl;

}

return 0;
}