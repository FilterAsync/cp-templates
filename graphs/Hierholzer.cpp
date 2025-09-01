// Hierholzer algorithm for finding an Euler tour
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

constexpr int N = 1E5 + 5, M = 2E5 + 5;
constexpr int INF = 1E9 + 7;
constexpr ll INFLL = 1E18;
constexpr int MOD = 1E9 + 7; // 998244353
constexpr double EPS = 1E-10;

struct Edge {
    int to, id;
    Edge(int to, int id): to(to), id(id) {}
};

vector<Edge> adj[N];
bool used[M];

list<int> hierholzer(int s) {
    list<int> res;
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        int u = st.top();
        while (!adj[u].empty()) {
            auto [v, id] = adj[u].back();
            adj[u].pop_back();
            if (used[id]) continue;
            used[id] = true;
            st.push(v);
            u = v;
        }
        res.push_front(st.top());
        st.pop();
    }
    return res;
}

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
