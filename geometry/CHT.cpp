// Deque CHT: slopes inserted in increasing order, queries x non-decreasing.
// For min queries. Use long long for values.

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

struct Line {
    ll m, b; // y = mx + b
    Line(ll m = 0, ll b = INFLL): m(m), b(b) {}
};

// check if l2 is useless between l1 and l3 (all slopes are increasing)
bool bad(Line const &l1, Line const &l2, Line const &l3) {
    // Use integer arithmetic to avoid floating error:
    // (b2 - b1)*(m2 - m3) + (b2 - b3)*(m1 - m2) >= 0  => l2 is useless
    __int128_t left  = __int128_t(l2.b - l1.b) * __int128_t(l2.m - l3.m);
    __int128_t right = __int128_t(l2.b - l3.b) * __int128_t(l1.m - l2.m);
    return left + right >= 0;
}

struct CHT {
    deque<Line> dq;

    void add(ll m, ll b) {
        Line L(m, b);
        while (dq.size() >= 2 && bad(dq[dq.size() - 2], dq[dq.size() - 1], L)) {
            dq.pop_back();
        }
        dq.push_back(L);
    }

    ll get(ll x) { // queries must be non-decreasing x
        while (dq.size() >= 2) {
            ll y1 = dq[0].m * x + dq[0].b;
            ll y2 = dq[1].m * x + dq[1].b;
            if (y2 <= y1) {
                dq.pop_front();
            } else {
                break;
            }
        }
        return dq[0].m * x + dq[0].b;
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
