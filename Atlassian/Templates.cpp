// LCA
struct LCA{
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 20; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};

// binpow
const ll mod = 1000000007; // faster if const
ll modpow(ll b, ll e) {
     ll ans = 1;
     for (; e; b = b * b % mod, e /= 2)
          if (e & 1) ans = ans * b % mod;
     return ans;
}

// trie

class Trie{

public:
    const static int N = 26;
    const static char baseChar = 'a';
    struct TrieNode
    {
        int next[N];
        bool isEnd;
        int freq;
        TrieNode()
        {
            for (int i = 0; i < N; i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
        }
    };

    vector<TrieNode> tree;
    Trie()
    {
        tree.push_back(TrieNode());
    }

    void insert(const string &s)
    {
        int p = 0;
        tree[p].freq++;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
            {
                tree.push_back(TrieNode());
                tree[p].next[s[i] - baseChar] = tree.size() - 1;
            }

            p = tree[p].next[s[i] - baseChar];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
    }

    bool checkPrefix(const string &s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
                return false;

            p = tree[p].next[s[i] - baseChar];
        }
        return true;
    }

    bool checkString(const string &s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
                return false;

            p = tree[p].next[s[i] - baseChar];
        }

        return tree[p].isEnd;
    }

    int persistentInsert(int head, const string &s)
    {
        int old = head;

        tree.push_back(TrieNode());
        int now = tree.size() - 1;
        int newHead = now;

        int i, j;

        for (i = 0; i < s.size(); i++)
        {
            if (old == -1)
            {
                tree.push_back(TrieNode());
                tree[now].next[s[i] - baseChar] = tree.size() - 1;
                tree[now].freq++;
                now = tree[now].next[s[i] - baseChar];
                continue;
            }
            for (j = 0; j < N; j++)
                tree[now].next[j] = tree[old].next[j];
            tree[now].freq = tree[old].freq;
            tree[now].isEnd = tree[old].isEnd;

            tree[now].freq++;

            tree.push_back(TrieNode());
            tree[now].next[s[i] - baseChar] = tree.size() - 1;

            old = tree[old].next[s[i] - baseChar];
            now = tree[now].next[s[i] - baseChar];
        }

        tree[now].freq++;
        tree[now].isEnd = true;

        return newHead;
    }

    bool persistentCheckPrefix(int head, const string &s)
    {
        int p = head;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
                return false;

            p = tree[p].next[s[i] - baseChar];
        }
        return true;
    }

    bool persistentCheckString(int head, const string &s)
    {
        int p = head;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
                return false;

            p = tree[p].next[s[i] - baseChar];
        }
        return tree[p].isEnd;
    }
};




// segment tree
struct Tree {
     typedef int T;
     static constexpr T unit = INT_MIN;
     T f(T a, T b) { return max(a, b); } // (any associative fn)
     vector<T> s;
     int n;
     Tree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
     void update(int pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
               s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
     }
     T query(int b, int e) { // query [b, e)
          T ra = unit, rb = unit;
          for (b += n, e += n; b < e; b /= 2, e /= 2) {
               if (b % 2) ra = f(ra, s[b++]);
               if (e % 2) rb = f(s[--e], rb);
          }
          return f(ra, rb);
     }
};

// fenwick tree
template<class T> struct BIT {
     vector<T> s;
     int n;
     BIT(int n): s(n + 1), n(n) {}
     void update(int i, T v) {
          for (i++; i <= n; i += i & -i) s[i] += v;
     }
     T query(int i) { // EXCLUSIVE interval [0, i)
          T ans = 0;
          for (; i; i -= i & -i) ans += s[i];
          return ans;
     } // INCLUSIVE-EXCLUSIVE interval [l, r)
     T query(int l, int r) { return query(r) - query(l); }
     int kth(T k) { // 0-indexed, returns n if k > sum of tree
          if (k < 0) return -1;
          int i = 0;
          for (int pw = 1 << __lg(n); pw; pw >>= 1)
               if (i + pw <= n && s[i + pw] <= k) k -= s[i += pw];
          return i;
     }
};

// DSU
struct DSU {
     vector<int> s;
     DSU(int n): s(n, -1) {}
     int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
     bool join(int a, int b) {
          a = find(a), b = find(b);
          if (a == b) return false;
          if (s[a] > s[b]) swap(a, b);
          s[a] += s[b], s[b] = a;
          return true;
     }
     int size(int i) { return -s[find(i)]; }
     bool same(int a, int b) { return find(a) == find(b); }
};

// tree lifting
struct lift {
     vi d, p, j;
     lift(vector<vi>& adj): d(sz(adj)), p(d), j(d) {
          dfs(0, adj);
     }
     void dfs(int u, vector<vi>& adj) {
          int jmp = (d[u] + d[j[j[u]]] == 2 * d[j[u]]) ? j[j[u]] : u;
          for (int v : adj[u])
               if (v != p[u])
                    d[v] = d[p[v] = u] + 1, j[v] = jmp, dfs(v, adj);
     }
     int lca(int u, int v) {
          if (d[u] < d[v]) swap(u, v);
          while (d[u] > d[v]) u = d[j[u]] >= d[v] ? j[u] : p[u];
          if (u == v) return u;
          while (p[u] != p[v])
               if (j[u] != j[v]) u = j[u], v = j[v];
               else u = p[u], v = p[v];
          return p[u];
     }
     int kth(int u, int k) {
          if (k > d[u]) return -1;
          k = d[u] - k;
          while (d[u] > k) u = d[j[u]] >= k ? j[u] : p[u];
          return u;
     }
};

// recursive segtree
struct SegmentTree {
     // TO CHANGE

     struct Node { // set default values
          ..

          template<typename T>
          void apply(int l, int r, T val) { // update value and save push
               ...
          }
     };

     Node merge(const Node& left, const Node& right) {
          ...
     }

     void push(int v, int l, int r) {
          if (tree[v].??? != ...) {
               int mid = (r + l) >> 1;
               int vl = v + 1, vr = v + ((mid - l) << 1);
               tree[vl].apply(l, mid, tree[v].???);
               tree[vr].apply(mid, r, tree[v].???);
               tree[v].??? = ...;
          }
     }

     // DEFAULT PART

     vector<Node> tree;
     int n;

     template<typename T>
     void build(int v, int l, int r, const vector<T>& arr) {
          if (l + 1 == r) {
               tree[v].apply(l, r, arr[l]);
               return;
          }
          int mid = (r + l) >> 1;
          int vl = v + 1, vr = v + ((mid - l) << 1);
          build(vl, l, mid, arr);
          build(vr, mid, r, arr);
          tree[v] = merge(tree[vl], tree[vr]);
     }

     void build(int v, int l, int r) {
          if (l + 1 == r) {
               return;
          }
          int mid = (r + l) >> 1;
          int vl = v + 1, vr = v + ((mid - l) << 1);
          build(vl, l, mid);
          build(vr, mid, r);
          tree[v] = merge(tree[vl], tree[vr]);
     }

     Node find(int v, int l, int r, int ql, int qr) {
          if (ql <= l && r <= qr) {
               return tree[v];
          }
          push(v, l, r);
          int mid = (r + l) >> 1;
          int vl = v + 1, vr = v + ((mid - l) << 1);
          if (qr <= mid) {
               return find(vl, l, mid, ql, qr);
          } else if (ql >= mid) {
               return find(vr, mid, r, ql, qr);
          } else {
               return merge(find(vl, l, mid, ql, qr), find(vr, mid, r, ql, qr));
          }
     }

     template<typename T>
     void update(int v, int l, int r, int ql, int qr, const T& newval) {
          if (ql <= l && r <= qr) {
               tree[v].apply(l, r, newval);
               return;
          }
          push(v, l, r);
          int mid = (r + l) >> 1;
          int vl = v + 1, vr = v + ((mid - l) << 1);
          if (ql < mid) {
               update(vl, l, mid, ql, qr, newval);
          }
          if (qr > mid) {
               update(vr, mid, r, ql, qr, newval);
          }
          tree[v] = merge(tree[vl], tree[vr]);
     }

     int find_first(int v, int l, int r, int ql, int qr, const function<bool(const Node&)>& predicate) {
          if (!predicate(tree[v])) {
               return -1;
          }
          if (l + 1 == r) {
               return l;
          }
          push(v, l, r);
          int mid = (r + l) >> 1;
          int vl = v + 1, vr = v + ((mid - l) << 1);
          if (ql < mid) {
               int lans = find_first(vl, l, mid, ql, qr, predicate);
               if (lans != -1) {
                    return lans;
               }
          }
          if (qr > mid) {
               int rans = find_first(vr, mid, r, ql, qr, predicate);
               if (rans != -1) {
                    return rans;
               }
          }
          return -1;
     }

     // INTERFACE

     SegmentTree(int n) : n(n) { // build from size with default values
          tree.resize(2 * n - 1);
          build(0, 0, n);
     }

     template<typename T>
     SegmentTree(const vector<T>& arr) { // build from vector
          n = arr.size();
          tree.resize(2 * n - 1);
          build(0, 0, n, arr);
     }

     Node find(int ql, int qr) { // find value on [ql, qr)
          return find(0, 0, n, ql, qr);
     }

     Node find(int qi) { // find value of position qi
          return find(0, 0, n, qi,qi+1);
     }

     template<typename T>
     void update(int ql, int qr, const T& newval) { // update [ql, qr) with newval
          update(0, 0, n, ql, qr, newval);
     }

     template<typename T>
     void update(int qi, const T& newval) { // update position qi with newval
          update(0, 0, n, qi, qi + 1, newval);
     }

     int find_first(int ql, int qr, const function<bool(const Node&)>& predicate) { // find first index on [ql, qr) that satisfies predicate or -1 if none
          return find_first(0, 0, n, ql, qr, predicate);
     }

     int find_first(int ql, const function<bool(const Node&)>& predicate) { // find first index >= ql that satisfies predicate or -1 if none
          return find_first(0, 0, n, ql, n, predicate);
     }

     int find_first(const function<bool(const Node&)>& predicate) { // find first index that satisfies predicate or -1 if none
          return find_first(0, 0, n, 0, n, predicate);
     }
};


// number theory




/*-----------------------------------------------Number theory Starts-----------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*-----------------------------------------------Number theory Ends---------------------------------------------------------------*/



// combination
struct nCr{
    ll maxx , mod; 
    vector<ll> fact, ifact; 
    inline ll mul(ll a, ll b) { return a *1LL* b % mod ;}
    ll power(ll a, ll n) {
        if(n == 0) return 1 ; 
        int p = power(a, n/2) % mod ; 
        p = mul(p, p) ;  
        return n & 1 ? mul(p, a) : p ; 
    }
    int invMod(int a) {return power(a,mod-2);}
    void pre() {
        fact[0] = 1 ;
        for(int i = 1;i< maxx;++i) fact[i] = mul(i, fact[i-1]) ;
        ifact[maxx-1] = invMod(fact[maxx-1]) ; 
        for(int i = maxx-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
    }
    nCr(int _mxN, int _M) {
        maxx = _mxN + 1; 
        mod = _M ; 
        fact.resize(maxx) ; 
        ifact.resize(maxx) ;
        pre() ;  
    }
    ll C(ll n, ll r) {
        if (n < r || r < 0 || n < 0) return 0;
        return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
    }
};
//maxx N we need
//const int N = 100;
// initialise nCr struct
// nCr comb(N , mod);


// mod inverse
const ll mod = 1000000007, LIM = 200000;
ll* inv = new ll[LIM] - 1;
inv[1] = 1;
rep(i, 2, LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;



// KMP
vi pi(const string& s) {
     vi p(sz(s));
     rep(i, 1, sz(s)) {
          int g = p[i - 1];
          while (g && s[i] != s[g]) g = p[g - 1];
          p[i] = g + (s[i] == s[g]);
     }
     return p;
}
vi match(const string& s, const string& pat) {
     vi p = pi(pat + '\0' + s), res;
     rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat))
          res.push_back(i - 2 * sz(pat));
     return res;
}
