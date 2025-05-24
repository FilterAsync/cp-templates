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

class DSU {
private:
	vector<int> parent, size;
public:
	DSU(int n) {
		parent.resize(n + 1);
		size.assign(n + 1, 1);
		iota(all(parent), 0);
	}

	int find(int u) {
		return parent[u] == u ? u : parent[u] = find(parent[u]);
	}

	bool unite(int u, int v) {
		u = find(u), v = find(v);

		if (u == v) {
			return false;
		}

		if (size[u] < size[v]) {
			swap(u, v);
		}

		parent[v] = u;
		size[u] += size[v];

		return true;
	}
};

void solve() {
	
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
