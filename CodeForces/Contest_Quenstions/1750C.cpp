    // 2112048
    // Dimpal Kalita
    // CSE sec A

    #include<bits/stdc++.h>


    // #include <ext/pb_ds/assoc_container.hpp>
    // #include <ext/pb_ds/tree_policy.hpp>


    using namespace std;
    // using namespace __gnu_pbds;


    #define md                  1000000007
    #define pb                  push_back
    #define fr(i,n)             for(ll i=0;i<n;i++)
    #define fr1(i,k,n)          for(ll i=k;i<n;i++)
    #define endl                "\n"
    #define F                   first
    #define S                   second
    #define inp(v)              for(auto &x: v) cin>>x  
    #define all(x)              (x).begin(), (x).end() 
    #define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);


    typedef long long ll;
    typedef pair<ll,ll> pll;
    typedef pair<int,int>pii;
    typedef unsigned long long ull;
    typedef long double lld;
    // typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key




    void dk(){
        ll n;
        cin>>n;
        string s, t;
        cin>>s>>t;

        
        vector<pll> ans;
        // for(ll i=0;i<=n/2;i++){
        //         bool flag1=0, flag2=0;
        //         if(s[i]==s[n-i-1]) flag1=1;
        //         if(t[i]==t[n-i-1]) flag2=1;

        //         if(flag2!=flag1){
        //             cout<<"NO"<<endl;
        //             return;
        //         }
               
        // }

        // cout<<"YES"<<endl;


        ll ct=0;
        
        for(ll i=0;i<n;i++){
            ct+=s[i]=='1';
        }
        ll ind=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='1') {
                ind=i;
                break;
            }
        }

        if(ct%2==0){
            ind=0;
        }
        else {
            ans.pb({ind+1, ind+1});
        }


        for(ll i=ind+1;i<=n/2;i++){
                bool flag1=0, flag2=0;
                if(s[i]==s[n-i-1]) flag1=1;
                if(t[i]==t[n-i-1]) flag2=1;

                if(flag2!=flag1){
                    cout<<"NO"<<endl;
                    return;
                }
                ans.pb({i+1, n-i+1});
        }

        cout<<"YES"<<endl;

        reverse(all(ans));
        cout<<ans.size()<<endl;

        for(auto i:ans){
            cout<<i.F<<" "<<i.S<<endl;
        }
        


    }




    int main()
    { 
        fast_io;
        
        //#ifndef ONLINE_JUDGE
        //file_io;
        //freopen("D:/cp/error.txt", "w+", stderr);
        //#endif

        int n=1;
        cin>>n;
        for(int i=0;i<n;i++){
        //google(i+1);
        dk();
    }
    return 0;
    }