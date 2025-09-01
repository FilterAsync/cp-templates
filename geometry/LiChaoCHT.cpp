// Li Chao Tree for integer x in [X_L, X_R], max queries.

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
constexpr ll INFLL = 4E18;
constexpr int MOD = 1E9 + 7; // 998244353
constexpr double EPS = 1E-10;

struct Line {
    ll m, b; // y = mx + b
    Line(ll m = 0, ll b = -INFLL): m(m), b(b) {}
    ll eval(ll x) const {
        __int128_t res = (__int128_t)m * x + b;
        if (res > INFLL) return INFLL;
        if (res < -INFLL) return -INFLL;
        return (ll)res;
    }
};

struct LiChao {
    struct Node {
        Line line;
        Node *left, *right;
        Node(Line const &line): line(line), left(nullptr), right(nullptr) {}
    };
    Node *root;
    ll lo, hi;
    LiChao(ll lo, ll hi): root(nullptr), lo(lo), hi(hi) {}

    Node* insert(Node* node, ll l, ll r, Line nw) {
        if (!node) return new Node(nw);
        ll mid = (l + r) / 2;
        // at mid prefer the line that gives smaller value
        if (nw.eval(mid) < node->line.eval(mid)) {
            swap(nw, node->line);
        }
        if (l == r) return node;
        if (nw.eval(l) < node->line.eval(l)) {
            node->left = insert(node->left, l, mid, nw);
        } else if (nw.eval(r) < node->line.eval(r)) {
            node->right = insert(node->right, mid + 1, r, nw);
        }
        return node;
    }

    void add(Line nw) { root = insert(root, lo, hi, nw); }
    void add(ll m, ll b) { add(Line(m, b)); }

    ll get(Node* node, ll l, ll r, ll x) const {
        if (!node) return INFLL;
        ll res = node->line.eval(x);
        if (l == r) return res;
        ll mid = (l + r) / 2;
        if (x <= mid) {
            return min(res, get(node->left, l, mid, x));
        } else {
            return min(res, get(node->right, mid + 1, r, x));
        }
    }

    ll get(ll x) const {
        if (x < lo || x > hi) return INFLL;
        return get(root, lo, hi, x);
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
