// by Siddhid Saha

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007



ll bs(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        ll m = l + (r - l) / 2;
  
        if (arr[m] == x)
            return m;
  
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}


ll gethash(string key)
{
	ll value = 0;
	ll p = 31;
	ll p_power = 1;
 
	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}
 
	return value;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n;
    cin >> n;
    vector <string> likes ;
    vector<ll> liken;
    vector <string> dislikes ;
    vector<ll> disliken;
    set <string> ans;
    for(int i = 0 ; i  < n ; i  ++)
    {
        int u ; cin >> u;
        for(int i = 0 ; i < u ; i ++)
        {
            string s;
            cin >> s;
            ll uu = gethash(s);
            likes.pb(s);
            liken.pb(uu);
        }
        int v; cin >> v;
        for(int i = 0 ; i < v ; i ++)
        {
            string s;
            cin >> s;
            ll uu = gethash(s);
            dislikes.pb(s);
            disliken.pb(uu);
        }

    }
    ll dis[disliken.size()];
    ll li[liken.size()];

    for(int i = 0 ; i < liken.size() ; i ++)
    {
        li[i]= liken[i];
    }
    for(int i = 0 ; i < disliken.size() ; i ++)
    {
        dis[i] = disliken[i];
    }

    for(int i = 0 ; i < disliken.size() ; i ++)
    {
        ll c =bs(li , 0 , liken.size()-1 , dis[i]);
        if( c != -1)
        {
            likes.erase(likes.begin()+c);
        }
    }
    for(int i = 0 ; i < likes.size() ; i ++)
    {
        ans.insert(likes[i]);
    }
    cout << ans.size() <<" ";
    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    



	return 0;
}