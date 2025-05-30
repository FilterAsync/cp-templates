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

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

#define LOCAL

const int MAXN = 1E5 + 5;
const ll MOD = 1E9 + 7, INF = 1E18;
const double EPS = 1E-9;

void solve() {
	int n;
	cin >> n;

	int a[n + 1];
	FOR(i, 1, n) {
		cin >> a[i];
	}

	// index compression
	pii pairs[n + 1];
	FOR(i, 1, n) {
		pairs[i] = {a[i], i};
	}
	sort(pairs + 1, pairs + n + 1);
	int idx = 1;
	FOR(i, 1, n) {
		if (i == 1 || pairs[i].fi != pairs[i - 1].fi) {
			a[pairs[i].se] = idx++;
		} else {
			a[pairs[i].se] = idx - 1;
		}
	}
}

int main() {
	fast_io
	#ifndef LOCAL
		freopen("INPUT.INP", "r", stdin);
		freopen("OUTPUT.OUT", "w", stdout);
	#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();
}
