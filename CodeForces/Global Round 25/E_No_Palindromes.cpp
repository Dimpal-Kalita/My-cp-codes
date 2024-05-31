#include<bits/stdc++.h>
using namespace std;

#define endl                "\n"
#define read(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define int                 long long
#define ld                  long double
#define printv(v)           for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl; 
void google(int t) {cout << "Case #" << t << ": ";}
int bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}

struct manacher{
    vector<int>p;
    void run_manacher(string s){
        int n = s.length();
        p.assign(n,1);
        int l=1,r=1;
        for(int i=1;i<n;i++){
            p[i] = max(0ll,min(r-i,p[l+r-i]));
            while(i+p[i]<n and i-p[i]>=0 and s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }

            if((i+p[i])>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }
    void build(string s){
        string t;
        for(auto i:s){
            t.push_back('#');
            t.push_back(i);
        }
        t.push_back('#');
        run_manacher(t);
    } 

    int get_longest(int index,bool odd){
        if(odd){
            return (p[(2*index)+1])-1;
        }else{
            return (p[2*(index+1)])-1;
        }
    }

    bool check_palindrome(int l,int r){
        int l1 = l,r1=r;
        l = (2*l+1);
        r = (2*r+1);
        int index = (l+r)>>1;
        if(p[index]-1>=(r1-l1+1)){
            return true;
        }else{
            return false;
        }

    }

}m;

vector<pair<int,int>>ans;

bool func(int l,int r){

    if(m.check_palindrome(l,r)){
        if(l==r){
            return false;
        }else{
            int mid = (l+r)>>1;
            return (func(l,mid)&&func(mid+1,r));
        }
    }else{
        ans.push_back({l,r});
    }

}


void solve(){

    string str;
    cin>>str;
    m.build(str);

     if(!m.check_palindrome(0,str.length()-1)){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<str<<endl;
        return;
    }


    int n = str.length();
    for(int i=0;i<n-1;i++){
        if((m.check_palindrome(0,i)==false) and (m.check_palindrome(i+1,n-1)==false)){
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<str.substr(0,i+1)<<" "<<str.substr(i+1,(n-1)-(i+1)+1)<<endl;
            return;
        }
    }


    ans.clear();

    if(func(0,str.length()-1)){
        cout<<"YES"<<endl;
        sort(all(ans));

        cout<<ans.size()<<endl;
        for(auto i:ans){
            cout<<str.substr(i.first,i.second-i.first+1)<<" ";
        } 
        cout<<endl;

    }else{
        cout<<"NO"<<endl;
    }





}







int32_t main(){
    fast_io;
    
    int q = 1;
    cin>>q;
    while(q--){
        solve();
    
    }

    return 0;
}