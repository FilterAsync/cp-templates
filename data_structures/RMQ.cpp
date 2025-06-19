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

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

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

const string NAME = "PROBLEM";
const int MAXN = 1E5 + 5;
const int INF = 1E9 + 7;
const ll MOD = 1E9 + 7, INFLL = 1E18;
const double EPS = 1E-9;

// Sparse Table for Range Minimum Query (RMQ)
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
    #ifndef LOCAL
    freopen((NAME + ".INP").c_str(), "r", stdin);
    freopen((NAME + ".OUT").c_str(), "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
