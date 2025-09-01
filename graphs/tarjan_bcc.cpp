// Tarjan's algorithm for finding biconnected components
#include <bits/stdc++.h>

using namespace std;

template<class T> bool chmax(T &a, T const &b) {
    return (a < b ? (a = b, true) : false);
}

template<class T> bool chmin(T &a, T const &b) {
    return (a > b ? (a = b, true) : false);
}

using ll = long long;

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define by(x) [](auto const &a, auto const &b) { return a.x < b.x; }

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

#define LOCAL

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const string NAME = "PROBLEM";
const int MAXN = 1E5 + 5;
const int INF = 1E9 + 7;
const ll MOD = 1E9 + 7, INFLL = 1E18;
const double EPS = 1E-9;

vector<int> adj[MAXN];
int low[MAXN], num[MAXN];
bool in_stack[MAXN];
stack<int> st;
vector<vector<int>> bccs;
int counter = 0;

void tarjan(int u) {
    low[u] = num[u] = ++counter;
    st.push(u);
    in_stack[u] = true;

    for (int v : adj[u]) {
        if (!num[v]) {
            tarjan(v);
            chmin(low[u], low[v]);
            if (low[v] >= num[u]) {
                vector<int> bcc;
                bcc.push_back(u);
                int x;
                do {
                    x = st.top(); st.pop();
                    in_stack[x] = false;
                    bcc.push_back(x);
                } while (x != v);
                bccs.push_back(bcc);
            }
        } else if (in_stack[v]) {
            chmin(low[u], num[v]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) {
        if (!num[i]) {
            tarjan(i);
        }
    }

    cout << bccs.size() << el;
    for (auto const &bcc : bccs) {
        for (int v : bcc) {
            cout << v << " ";
        }
        cout << el;
    }
}

int main() {
    fast_io
    #ifndef LOCAL
        freopen((NAME + ".INP").c_str(), "r", stdin);
        freopen((NAME + ".OUT").c_str(), "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
