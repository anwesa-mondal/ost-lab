#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

// -------------------- Fast IO ------------------------
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// -------------------- Typedefs -----------------------
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

#define f(i,n) for(ll i=0;i<n;i++)
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)


// Vectors
template<typename T>
using vec = vector<T>;
using vi  = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

// Priority Queues
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

// Unordered Maps / Sets
template<typename K, typename V>
using umap = unordered_map<K, V>;

template<typename T>
using uset = unordered_set<T>;

// -------------------- Constants ----------------------
const ll INF  = (ll)4e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const double PI = 3.141592653589793238;

// -------------------- Macros -------------------------
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// -------------------- Debug (Local Only) -------------
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// -------------------- Utility Functions --------------
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll mod_add(ll a, ll b, ll m = MOD) { return (a + b) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return (a - b + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a * b) % m; }

ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a, ll m = MOD) {
    return mod_pow(a, m - 2, m);  // Fermat's little theorem
}

// vi a;                  // vector<int>
// vll b;                 // vector<long long>
// vec<string> s;         // vector<string>

// minpq<int> pq;         // min heap
// maxpq<int> pq2;        // max heap

// umap<int, int> mp;     // unordered_map<int, int>
// uset<int> st;          // unordered_set<int>

// f(i,n) for(int i=0;i<n;i++)
// fr(i,a,b) for(int i=a;i<b;i++)
// rf(i,n) for(int i=n-1;i>=0;i--)



int main() {
    fastio();

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;

        vll a(n);

        f(i,n) cin>> a[i];

       
        vll suff;
        vll pref;

        ll sum=0;
        
        for(auto i:a){
            sum+=i;
            pref.pb(sum);
        }

        sum=0;

        for(int i=n-1;i>=0;i--){
            sum+=a[i];
            suff.pb(sum);
        }

        int l=0;
        int r=n-1;
        ll ans=0;

        while(l<r){
            if(suff[l]==sum[r]){
                ans=sum[l];
                break;
            }
            if(sum[l]<sum[r]){
                l++;
            }else r--;
        }

        cout<<ans<<endl;
    }

   
}