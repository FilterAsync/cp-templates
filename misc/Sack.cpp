// aka. DSU on Tree
// Example: Given a tree with colored nodes, compute for each node how many distinct colors exist in its subtree.
#include <bits/stdc++.h>

using namespace std;

template<class T> bool chmax(T &a, T const &b) {
    return (a < b ? (a = b, true) : false);
}

template<class T> bool chmin(T &a, T const &b) {
    return (a > b ? (a = b, true) : false);
}

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define by(x) [](auto const &a, auto const &b) { return a.x < b.x; }
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define PROBLEM ""

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define LOCAL
#ifdef LOCAL
template<typename T> void _print(const char* name, T&& x) {
    cerr << name << " = " << x << el;
}
#define debug(x) _print(#x, x)
#else
#define debug(x)
#endif

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1E5 + 5;
const int INF = 1E9 + 7;
const ll MOD = 1E9 + 7, INFLL = 1E18 + 7;
const double EPS = 1E-9;

vi adj[MAXN];
int sz[MAXN], color[MAXN], cnt[MAXN], res[MAXN];
int distinct = 0;

void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u);
            sz[u] += sz[v];
        }
    }
}

void add(int u, int p, int delta) {
    cnt[color[u]] += delta;
    if (cnt[color[u]] == 0 && delta == -1) distinct--;
    if (cnt[color[u]] == 1 && delta == +1) distinct++;
    for (int v : adj[u]) {
        if (v != p) {
            add(v, u, delta);
        }
    }
}

void dfs(int u, int p, bool keep) {
    int big_child = -1, max_size = -1;

    for (int v : adj[u]) {
        if (v != p && chmax(max_size, sz[v])) {
            big_child = v;
        }
    }

    for (int v : adj[u]) {
        if (v != p && v != big_child) {
            dfs(v, u, false);
        }
    }

    if (big_child != -1) dfs(big_child, u, true);

    for (int v : adj[u]) {
        if (v != p && v != big_child) {
            add(v, u, +1);
        }
    }

    cnt[color[u]]++;
    if (cnt[color[u]] == 1) distinct++;

    res[u] = distinct;

    if (!keep) {
        add(u, p, -1);
        distinct = 0;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    FOR(i, 1, n) {
        cin >> color[i];
    }

    FOR(i, 1, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_size(1, 0);
    dfs(1, 0, true);

    while (q--) {
        int u;
        cin >> u;
        cout << res[u] << el;
    }
}

int main() {
    fast_io
    #ifndef LOCAL
    freopen(PROBLEM ".INP", "r", stdin);
    freopen(PROBLEM ".OUT", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
