// Sparse Table for RMQ

#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define FOR(i, l, r) for (int i = l; i <= (r); i++)
#define FOD(i, l, r) for (int i = l; i >= (r); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using db = long double;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vbool = vector<bool>;
using vvbool = vector<vbool>;

template<class T> inline bool chmax(T &a, T const &b) { return (a < b ? (a = b, true) : false); }
template<class T> inline bool chmin(T &a, T const &b) { return (a > b ? (a = b, true) : false); }

// #define DEBUG
#ifdef DEBUG
#include "D:\cpp\debug.h"
#else
#define debug(...)
#define debug_arr(...)
#endif

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1E5 + 5;
constexpr int INF = 1E9 + 7;
constexpr ll INFLL = 1E18;
constexpr int MOD = 1E9 + 7; // 998244353
constexpr double EPS = 1E-10;

template <typename T> class RMQ {
private:
    int n, lg;
    vector<vector<T>> st;
public:
    RMQ(vector<T> const &a) {
        n = sz(a);
        lg = __lg(n) + 1;
        st.resize(lg);
        st[0] = a;
        FOR(i, 1, lg - 1) {
            st[i].resize(n - (1 << i) + 1);
            FOR(j, 0, n - (1 << i)) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve() {
    
}

int main() {
    fast_io
    #define LOCAL
    #ifndef LOCAL
    #define PROBLEM ""
    freopen(PROBLEM ".INP", "r", stdin);
    freopen(PROBLEM ".OUT", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
