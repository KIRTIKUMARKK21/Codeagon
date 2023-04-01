// Trying To Improve:)
#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MOD1 1000000009  //For Double Hashing
#define MOD2 1610612741  // For Double Hashing
// B = 911382323;  //Hashing Big Primes
// C = 972663749;  //Hashing Big Primes
#define   pb              push_back
#define   rep(i,a,b)      for(int i=a;i<b;i++)
#define   vl              vector<ll>
#define   vi              vector<int>
#define   lb              lower_bound
#define   ub              upper_bound
#define   print(ans)      printf("%.9f\n",ans)
#define all(x) (x).begin(), (x).end()
typedef int64_t ll;
typedef unsigned long long ull;
typedef long double lld;
#define   pi              pair<ll, int>
#define nline "\n"

//========================================Debugging Starts=================================

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//==========================================Debugging Ends==========================================

// vector<vector<int>> vec( n , vector<int> (m, 0));
// priority_queue<pi, vector<pi>, greater<pi>>q;
// cout<<fixed<<setprecision(10);

bool prime[100000];
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= 100000; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 100000; i += p)
                prime[i] = false;
        }
    }
}
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD
           ;
}
ll invmd(ll n)
{
    return (binpow(n, MOD - 2));
}
ll ceil2(ll a, ll b) {
    return (a + b - 1) / b;
}
// const int N=1e5+5;
// ll fact[N];
// void calcfactorial()
// {
//     fact[0]=1;
//     rep(i,1,N-1)
//     {
//         fact[i]=(fact[i-1]*i)%MOD;

//     }
// }
// ll ncr(ll n, ll k) {
//     return fact[n] * invmd(fact[k] * fact[n - k] % MOD) % MOD;
// }

void solve()
{
    ll n;
    cin >> n;
    vector<ll>m(n + 1, 0);
    rep(i, 1, n + 1)
    {
        cin >> m[i];
    }
    vector<ll>v(n + 1, 0);
    rep(i, 1, n + 1)
    {
        cin >> v[i];
    }
    ll prm = m[1];
    ll pm = m[1] * v[1];
    vector<pair<ll, ll>>ans;
    for (int i = 2; i < n + 1; i++)
    {
        double prv = double(pm) / double(prm);
        if (v[i] >= prv)
        {

            ans.pb({prm, pm});
            prm = m[i];
            pm = v[i] * m[i];

        }
        else
        {
            pm += v[i] * m[i];
            prm += m[i];

        }
    }
    ans.pb({prm, pm});
    // debug(ans);
    sort(all(ans));
    cout<<ans.size()<<nline;
    for(auto it:ans)
    {
        cout<<it.first<<" "<<it.second<<nline;
    }





}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    solve();
    return 0;
}


