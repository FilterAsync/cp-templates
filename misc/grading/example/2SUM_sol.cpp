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

// #define LOCAL

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const string NAME = "2SUM";
const int MAXN = 1E5 + 5;
const int INF = 1E9 + 7;
const ll MOD = 1E9 + 7, INFLL = 1E18;
const double EPS = 1E-9;

void solve() {
	// brute force solution for the two-sum problem
    int n, t;
	cin >> n >> t;

	int a[n + 1];
	FOR(i, 1, n) {
		cin >> a[i];
	}

	FOR(i, 1, n) {
		FOR(j, i + 1, n) {
			if (a[i] + a[j] == t) {
				cout << "YES" << el;
				return;
			}
		}
	}

	cout << "NO" << el;
}

int main() {
    fast_io
    #ifndef LOCAL
        freopen((NAME + ".INP").c_str(), "r", stdin);
        freopen((NAME + ".ANS").c_str(), "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
