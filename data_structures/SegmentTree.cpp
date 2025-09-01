#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
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

template<class T> bool chmax(T &a, T const &b) { return (a < b ? (a = b, true) : false); }

template<class T> bool chmin(T &a, T const &b) { return (a > b ? (a = b, true) : false); }

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
constexpr ll MOD = 1E9 + 7, INFLL = 1E18 + 7;
constexpr double EPS = 1E-9;

// range sum
template<class T> struct SegmentTree {
private:
    int n;
    vector<T> tree;

    void build(vector<T> const &a, int i, int l, int r) {
        if (l == r) {
            tree[i] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, i << 1, l, m);
        build(a, i << 1 | 1, m + 1, r);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
public:
    SegmentTree(int n): n(n), tree(4 * n + 5) {}
    SegmentTree(vector<T> const &a, int n): n(n), tree(4 * n + 5) {
        build(a, 1, 1, n);
    }

    void update(int i, int l, int r, int k, T val) {
        if (l > r || l > k || k > r) return;
        if (l == r) {
            tree[i] = val;
            return;
        }
        int m = (l + r) >> 1;
        update(i << 1, l, m, k, val);
        update(i << 1 | 1, m + 1, r, k, val);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    T get(int i, int l, int r, int ql, int qr) {
        if (l > r || l > qr || r < ql || ql > qr) return T();
        if (l >= ql && r <= qr) return tree[i];
        int m = (l + r) >> 1;
        return get(i << 1, l, m, ql, qr) + get(i << 1 | 1, m + 1, r, ql, qr);
    }

    void update(int k, T val) { return update(1, 1, n, k, val); }

    T get(int ql, int qr) { return get(1, 1, n, ql, qr); }
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
